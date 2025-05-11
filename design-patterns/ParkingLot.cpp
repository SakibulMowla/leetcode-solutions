// Question: https://codezym.com/question/7

#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
#include <sstream>

using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;

class ParkingFloor {
    private:
        int floor, row, column;
        VVI parking;
        vector<vector<bool>> reserved;
        unordered_map<int, int> freeSpaces;
    
    public:
        ParkingFloor(int floor, VVI& parking) {
            this->parking = parking;
            this->floor = floor;
            row = parking.size();
            column = parking[0].size();
            reserved = vector<vector<bool>>(row, vector<bool> (column, false));

            for (int i = 0; i < row; i++) {
                for (int j = 0; j < column; j++) {
                    int vehicleType = parking[i][j];
                    if (vehicleType != 0) {
                        freeSpaces[vehicleType]++;
                    }
                }
            }
        }
    
        string park(int vehicleType) {
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < column; j++) {
                    if (parking[i][j] == vehicleType && reserved[i][j] == false) {
                        reserved[i][j] = true;
                        freeSpaces[vehicleType]--;
                        return to_string(floor) + "-" + to_string(i) + "-" + to_string(j);
                    }
                }
            }
            return "";
        }

        int getFreeSpotsCount(int vehicleType) {
            return freeSpaces[vehicleType];
        }

        bool removeVehicle(int row, int column) {
            if (reserved[row][column] == false || parking[row][column] == 0) {
                return false;
            }

            int vehicleType = parking[row][column];
            freeSpaces[vehicleType]++;

            reserved[row][column] = false;
            return true;
        }
    };

enum ParkingStrategyType {
    NEAREST = 0,
    MOST_FREE = 1
};

// abstract class
class ParkingStrategy {
public:
    virtual string park(vector<ParkingFloor>& floors, int vehicleType) = 0;
    virtual ~ParkingStrategy() = default;
};

class NearestParkingStrategy : public ParkingStrategy {
public:
    virtual string park(vector<ParkingFloor>& floors, int vehicleType) {
        for (ParkingFloor& floor: floors) {
            string spotId = floor.park(vehicleType);
            if (spotId != "") {
                return spotId;
            }
        }
        return "";
    }
};

class MostFreeSpacesParkingStrategy : public ParkingStrategy {
    public:
        virtual string park(vector<ParkingFloor>& floors, int vehicleType) {
            int floorCount = floors.size();
            int floor = -1;
            int maxSpace = 0;
            
            for (int i = 0; i < floorCount; i++) {
                int spaces = floors[i].getFreeSpotsCount(vehicleType);
                if (spaces > maxSpace) {
                    maxSpace = spaces;
                    floor = i;
                }
            }

            if (floor == -1) {
                return "";
            }

            return floors[floor].park(vehicleType);
        }
    };

class ParkManager {
private:
    vector<unique_ptr<ParkingStrategy>> strategies;

public:
    ParkManager() {
        strategies.push_back(make_unique<NearestParkingStrategy>());
        strategies.push_back(make_unique<MostFreeSpacesParkingStrategy>());
    }

    string park(vector<ParkingFloor>& floors, int vehicleType, ParkingStrategyType parkingStrategy) {
        if (parkingStrategy < 0 || parkingStrategy >= strategies.size()) {
            return "";
        }

        return strategies[parkingStrategy]->park(floors, vehicleType);
    }
};

class SearchManager {
private:
    unordered_map<string, string> parkRecord;

public:
    void insert(string vehicleNumber, string ticketId, string spotId) {
        parkRecord[vehicleNumber] = spotId;
        parkRecord[ticketId] = spotId;
        return;
    }

    string find(string query) {
        if (parkRecord.find(query) == parkRecord.end()) {
            return "";
        }

        return parkRecord[query];
    }
};

class Solution {
private:
    vector<ParkingFloor> floors;
    ParkManager parkManager = ParkManager();
    SearchManager searchManager = SearchManager();

    vector<int> parse(string spotId) {
        stringstream ss(spotId);
        string token;
        vector<int> result;

        while (getline(ss, token, '-')) {
            result.push_back(stoi(token));
        }

        return result;
    }

public:
    void init(VVVI& parking) {
        int floorCount = parking.size();
        floors.clear();
        for (int i = 0; i < floorCount; i++) {
            floors.push_back(ParkingFloor(i, parking[i]));
        }
    }

    string park(int vehicleType, string vehicleNumber, string ticketId, ParkingStrategyType parkingStrategy) {
        string spotId = parkManager.park(floors, vehicleType, parkingStrategy);
        if (spotId != "") {
            searchManager.insert(vehicleNumber, ticketId, spotId);
        }
        return spotId;
    }

    bool removeVehicle(string spotId) {
        vector<int> parsed = parse(spotId);
        int floor = parsed[0];
        return floors[floor].removeVehicle(parsed[1], parsed[2]);
    }

    string searchVehicle(string query) {
        return searchManager.find(query);
    }

    int getFreeSpotsCount(int floor, int vehicleType) {
        if (floor < 0 || floor >= floors.size()) {
            return 0;
        }

        return floors[floor].getFreeSpotsCount(vehicleType);
    }
};

// Using strategy pattern to park vehicles

int main() {
    Solution solution;

    // Test cases to validate the solution
    VVVI parking = {
        {
            {4, 4, 2, 2},
            {2, 4, 2, 0},
            {0, 2, 2, 2},
            {4, 4, 4, 0}
        },
        {
            {4, 4, 4, 4},
            {2, 4, 4, 0},
            {0, 2, 4, 2},
            {4, 4, 4, 0}
        }
    };
    
    solution.init(parking);
    cout << solution.park(2, "bh234", "tkt4534", ParkingStrategyType::NEAREST) << endl; // should return "0-0-2"
    cout << solution.searchVehicle("bh234") << endl; // should return "0-0-2"
    cout << solution.searchVehicle("tkt4534") << endl; // should return "0-0-2"
    cout << solution.getFreeSpotsCount(0, 2) << endl; // should return 6
    cout << solution.removeVehicle("0-0-2") << endl; // should return True
    cout << solution.getFreeSpotsCount(0, 2) << endl; // should return 7

    cout << solution.park(4, "bh402", "tkt63363", ParkingStrategyType::MOST_FREE) << endl; // should return "1-0-0"
    cout << solution.searchVehicle("tkt63363") << endl; // should return "1-0-0"
    cout << solution.searchVehicle("bh402") << endl; // should return "1-0-0"
    cout << solution.getFreeSpotsCount(1, 4) << endl; // should return 9
    cout << solution.removeVehicle("1-0-0") << endl; // should return True
    cout << solution.getFreeSpotsCount(1, 4) << endl; // should return 10
 
    return 0;
}
