// Question: https://codezym.com/question/9

#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <sstream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

class Lift {
    int currentFloor = 0, floors, liftsCapacity;
    unordered_set<int> incomingRequests;
    unordered_map<int, int> outgoingRequests;
    unique_ptr<class LiftState> state;

public:
    Lift(int floors, int liftsCapacity);

    int getCurrentFloor();
    void setCurrentFloor(int floor);
    char getMoveDirection();
    int getCurrentPeopleCount();
    void tick();
    void addIncomingRequest(int floor, char direction);
    void addOutgoingRequest(int floor);
    int countPeople(int floor, char direction);
    int getTimeToReachFloor(int floor, char direction);
    void setState(string direction);

    friend class MovingUpState;
    friend class MovingDownState;
    friend class IdleState;
    friend class MovingUpToPickFirstState;
    friend class MovingDownToPickFirstState;
};

class LiftState {
protected:
    Lift* lift;

public:
    LiftState(Lift* lift) : lift(lift) {}
    virtual ~LiftState() = default;   
    virtual int getTimeToReachFloor(int floor, char direction) = 0;
    virtual int countPeople(int floor, char direction) {
        return 0;
    }
    virtual char getDirection() = 0;
    virtual void tick() = 0;
};

class MovingUpState : public LiftState {
public:
    MovingUpState(Lift* lift) : LiftState(lift) {}

    int getTimeToReachFloor(int floor, char direction) override {
        int currentFloor = lift->getCurrentFloor();
        if (direction != 'U' || floor < currentFloor) {
            return -1;
        }
        return floor - currentFloor;
    }

    int countPeople(int floor, char direction) override {
        if (direction != 'U') {
            return 0;
        }

        int count = 0;
        for (auto request: lift->outgoingRequests) {
            if (request.first > floor) {
                count += request.second;
            }
        }

        return count;
    }

    char getDirection() override {
        return 'U';
    }

    void tick() override {
        lift->incomingRequests.erase(lift->getCurrentFloor());
        lift->setCurrentFloor(lift->getCurrentFloor() + 1);
        lift->outgoingRequests.erase(lift->getCurrentFloor());
    }
};

class MovingDownState : public LiftState {
public:
    MovingDownState(Lift* lift) : LiftState(lift) {}

    int getTimeToReachFloor(int floor, char direction) override {
        int currentFloor = lift->getCurrentFloor();
        if (direction != 'D' || floor > currentFloor) {
            return -1;
        }
        return currentFloor - floor;
    }

    int countPeople(int floor, char direction) override {
        if (direction != 'D') {
            return 0;
        }

        int count = 0;
        for (auto request: lift->outgoingRequests) {
            if (request.first < floor) {
                count += request.second;
            }
        }

        return count;
    }

    char getDirection() override {
        return 'D';
    }

    void tick() override {
        lift->incomingRequests.erase(lift->getCurrentFloor());
        lift->setCurrentFloor(lift->getCurrentFloor() - 1);
        lift->outgoingRequests.erase(lift->getCurrentFloor());
    }
};

class IdleState : public LiftState {
public:
    IdleState(Lift* lift) : LiftState(lift) {}    

    int getTimeToReachFloor(int floor, char direction) override {
        return abs(floor - lift->getCurrentFloor());
    }

    char getDirection() override {
        return 'I';
    }

    void tick() override {
    }
};

class MovingUpToPickFirstState : public LiftState {
private:
    int nextStop() {
        int maxFloor = -1;
        for (int f: lift->incomingRequests) {
            maxFloor = max(maxFloor, f);
        }
        return maxFloor;
    }

public:
    MovingUpToPickFirstState(Lift* lift) : LiftState(lift) {}

    int getTimeToReachFloor(int floor, char direction) override {
        int stop = nextStop();
        if (stop == -1 || direction != 'D') {
            return -1;
        }

        return stop - lift->getCurrentFloor() + stop - floor;
    }

    char getDirection() override {
        return 'U';
    }

    void tick() override {
        lift->setCurrentFloor(lift->getCurrentFloor() + 1);
        if (nextStop() == lift->getCurrentFloor()) {
            lift->setState("D");
        }
    }
};

class MovingDownToPickFirstState : public LiftState {
private:
    int nextStop() {
        int minFloor = lift->floors;
        for (int f: lift->incomingRequests) {
            minFloor = min(minFloor, f);
        }
        return minFloor == lift->floors ? -1 : minFloor;
    }

public:
    MovingDownToPickFirstState(Lift* lift) : LiftState(lift) {}

    int getTimeToReachFloor(int floor, char direction) override {
        int stop = nextStop();
        if (stop == -1 || direction != 'U') {
            return -1;
        }

        return lift->getCurrentFloor() - stop + floor - stop;
    }

    char getDirection() override {
        return 'U';
    }

    void tick() override {
        lift->setCurrentFloor(lift->getCurrentFloor() - 1);
        if (nextStop() == lift->getCurrentFloor()) {
            lift->setState("U");
        }
    }
};

Lift::Lift(int floors, int liftsCapacity) : floors(floors), liftsCapacity(liftsCapacity),
        state(make_unique<IdleState>(this)) {

}

int Lift::getCurrentFloor() {
    return currentFloor;
}

void Lift::setCurrentFloor(int floor) {
    currentFloor = floor;
}

char Lift::getMoveDirection() {
    return state->getDirection();
}

int Lift::getTimeToReachFloor(int floor, char direction) {
    return state->getTimeToReachFloor(floor, direction);
}

int Lift::countPeople(int floor, char direction) {
    return state->countPeople(floor, direction);
}

void Lift::addIncomingRequest(int floor, char direction) {
    if (getMoveDirection() == 'I') {
        if (floor == currentFloor) {
            setState(string(1, direction));
        } else if (floor > currentFloor) {
            direction == 'D' ? setState("UD") : setState("U");
        } else {
            direction == 'U' ? setState("DU") : setState("D");
        }
    }
    incomingRequests.insert(floor);
    return;
}

void Lift::addOutgoingRequest(int floor) {
    outgoingRequests[floor]++;
}

void Lift::setState(string direction) {
    if (direction == "I") state.reset(new IdleState(this));
    else if (direction == "U") state.reset(new MovingUpState(this));
    else if (direction == "D") state.reset(new MovingDownState(this));
    else if (direction == "UD") state.reset(new MovingUpToPickFirstState(this));
    else if (direction == "DU") state.reset(new MovingDownToPickFirstState(this));
}

void Lift::tick() {
    state->tick();
    if (incomingRequests.empty() && outgoingRequests.empty()) {
        setState("I");
    }
}

int Lift::getCurrentPeopleCount() {
    int count = 0;
    for (auto it: outgoingRequests) {
        count += it.second;
    }
    return count;
}

class Solution {
    int floors, liftsCount, liftsCapacity;
    vector<unique_ptr<Lift>> lifts;

public:
    Solution(int floors, int liftsCount, int liftsCapacity) : 
             floors(floors), liftsCount(liftsCount), liftsCapacity(liftsCapacity) {
        this->lifts.resize(liftsCount);
        for (int i = 0; i < liftsCount; i++) {
            lifts[i] = make_unique<Lift>(floors, liftsCapacity);
        }
    }

    int requestLift(int floor, char direction) {
        int liftIndex = -1, minTime = INT_MAX;
        for (int i = 0; i < liftsCount; i++) {
            int time = lifts[i]->getTimeToReachFloor(floor, direction);
            if (time < 0 || lifts[i]->countPeople(floor, direction)) {
                continue;
            }
            if (minTime > time) {
                minTime = time;
                liftIndex = i;
            }
        }

        if (liftIndex >= 0) {
            lifts[liftIndex]->addIncomingRequest(floor, direction);
        }

        return liftIndex;
    }

    void pressFloorButtonInLift(int liftIndex, int floor) {
        lifts[liftIndex]->addOutgoingRequest(floor);
    }

    string getLiftState(int liftIndex) {

        return to_string(lifts[liftIndex]->getCurrentFloor()) + "-" +
               lifts[liftIndex]->getMoveDirection() + "-" +
               to_string(lifts[liftIndex]->getCurrentPeopleCount());
    }

    void tick() {
        for (int i = 0; i < liftsCount; i++) {
            lifts[i]->tick();
        }
    }
};

int main() {
    Solution solution(6, 2, 2);

    // Test cases to validate the solution
    cout << solution.requestLift(0, 'U') << endl; // returns lift 0
    cout << solution.requestLift(5, 'D') << endl; // returns lift 1
    solution.pressFloorButtonInLift(0, 4);
    solution.tick();
    cout << solution.getLiftState(0) << endl; // returns 1-U-1 i.e. Lift 0 is at floor 1, going Up, has 1 people inside.
    cout << solution.getLiftState(1) << endl; // returns 1-U-0 i.e. Lift 1 is at floor 1, going Up, has 0 people inside.
    cout << solution.requestLift(3, 'D') << endl; // returns lift 1
    cout << solution.requestLift(6, 'D') << endl; // returns lift -1
    cout << solution.requestLift(0, 'U') << endl; // returns lift -1
    solution.tick();
    solution.tick();
    cout << solution.getLiftState(0) << endl; // returns 3-U-1 i.e. Lift 0 is at floor 3, going Up, has 1 people inside.
    cout << solution.getLiftState(1) << endl; // returns 3-U-0 i.e. Lift 1 is at floor 3, going Up, has 0 people inside.
    solution.tick();
    cout << solution.getLiftState(0) << endl; // returns 4-I-0 i.e. Lift 0 is at floor 4, standing Idle, has 0 people inside.
    cout << solution.getLiftState(1) << endl; // returns 4-U-0 i.e. Lift 1 is at floor 4, going Up, has 0 people inside.
    // Lift 1 didn't picked up requestLift(floor = 3, direction = 'D') even though it passed 3rd floor.
    // First it will go to 5th floor for the first request and then while coming it will stop on 3rd floor.

    return 0;
}
