// Question: https://codezym.com/question/5

#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
#include <map>
#include <sstream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

class Order {
private:
    string orderId, restaurantId, foodItemId;
    int rating;
public:
    Order(string orderId, string restaurantId, string foodItemId, int rating) {
        this->orderId = orderId;
        this->restaurantId = restaurantId;
        this->foodItemId = foodItemId;
        this->rating = rating;
    }

    void setRating(int rating) {
        this->rating = rating;
    }

    string getRestaurantId() {
        return this->restaurantId;
    }

    string getFoodItemId() {
        return this->foodItemId;
    }

    int getRating() {
        return this->rating;
    }
};

class Rating {
private:
    int sum, count;

public:
    Rating(): sum(0), count(0) {}

    void add(int rating) {
        sum += rating;
        count++;
    }

    double getRating() {
        double rating = 1.0 * sum / count;
        rating = round(rating * 10) / 10; // round to 1 decimal place
        return rating;
    }
};

class RateOrderObserver {
public:
    virtual void update(Order order) = 0;
    virtual ~RateOrderObserver() = default;
};

struct RatingData {
    string restaurantId;
    double rating;

    RatingData(string restaurantId, double rating): restaurantId(restaurantId), rating(rating)  {}

    bool operator < (const RatingData& other) const {
        // floating point comparison
        if (fabs(rating - other.rating) < 1e-9) {
            return restaurantId < other.restaurantId;
        }
        return rating > other.rating;
    }
};

class Helper {
public:
    static vector<string> getTopRestaurants(int n, map<string, Rating> ratings) {
        set<RatingData> topOnes;
        for (auto it: ratings) {
            topOnes.insert(RatingData(it.first, it.second.getRating()));
            if (topOnes.size() > n) {
                topOnes.erase(prev(topOnes.end()));
            }
        }

        vector<string> restaurantIds;
        for (auto it: topOnes) {
            cout << it.restaurantId << " " << it.rating << endl;
            restaurantIds.push_back(it.restaurantId);
        }

        return restaurantIds;
    }
};

class MostRatedRestaurants : public RateOrderObserver {
private:
    map<string, Rating> ratings;

public:
    void update(Order order) {
        ratings[order.getRestaurantId()].add(order.getRating());
    }

    vector<string> getTopRestaurants(int n) {
        cout << "Here in MostRatedRestaurants:" << endl;
        // DRY principle
        return Helper::getTopRestaurants(n, ratings);
    }
};

class MostRatedRestaurantsByFood : public RateOrderObserver {
private:
    map<string, map<string, Rating>> ratings;

public:
    void update(Order order) {
        map<string, Rating>& restaurantToRating = ratings[order.getFoodItemId()];

        restaurantToRating[order.getRestaurantId()].add(order.getRating());
    }

    vector<string> getTopRestaurants(string foodItemId, int n) {
        cout << "Here in MostRatedRestaurantsByFood:" << endl;
        
        if (ratings.find(foodItemId) == ratings.end()) {
            return {};
        }

        map<string, Rating> restaurantToRating = ratings[foodItemId];

        // DRY principle
        return Helper::getTopRestaurants(n, restaurantToRating);
    }
};

class OrderManager {
private:
    map<string, Order> orders;
    vector<RateOrderObserver*> orderObservers;

public:
    void orderFood(string orderId, string restaurantId, string foodItemId) {
        Order order(orderId, restaurantId, foodItemId, 0);
        orders.insert({orderId, order});
    }

    void rateOrder(string orderId, int rating) {
        auto it = orders.find(orderId);
        if (it == orders.end()) {
            return;
        }

        it->second.setRating(rating);
        notifyAll(it->second);
    }    

    void addObserver(RateOrderObserver* observer) {
        orderObservers.push_back(observer);
    }

    void notifyAll(Order order) {
        for (auto& observer: orderObservers) {
            observer->update(order);
        }
    }
};

class Solution {
private:
    OrderManager orderManager;
    unique_ptr<MostRatedRestaurants> mostRated;
    unique_ptr<MostRatedRestaurantsByFood> mostRatedByFood;

public:
    void init() {
        mostRated = make_unique<MostRatedRestaurants>();
        orderManager.addObserver(mostRated.get());

        mostRatedByFood = make_unique<MostRatedRestaurantsByFood>();
        orderManager.addObserver(mostRatedByFood.get());
    }

    void orderFood(string orderId, string foodItemId, string restaurantId) {
        orderManager.orderFood(orderId, restaurantId, foodItemId);
    }

    void rateOrder(string orderId, int rating) {
        orderManager.rateOrder(orderId, rating);
    }

    vector<string> getTopRestaurantsByFood(string foodItemId) {
        return mostRatedByFood->getTopRestaurants(foodItemId, 20);
    }

    vector<string> getTopRatedRestaurants() {
        return mostRated->getTopRestaurants(20);
    }

    void printHelper(vector<string> restaurants) {
        cout << "Size = " << restaurants.size() << endl;
        for (auto restaurant: restaurants) {
            cout << restaurant << ",";
        }
        cout << endl;
    }
};

void testSingleOrderRating() {
    Solution solution;
    solution.init();

    solution.orderFood("order-1", "food-1", "restaurant-A");
    solution.rateOrder("order-1", 4);

    auto top = solution.getTopRatedRestaurants();
    assert(top.size() == 1);
    assert(top[0] == "restaurant-A");
}

void testRatingTieBreaker() {
    Solution solution;
    solution.init();

    solution.orderFood("o1", "food-x", "res-A");
    solution.orderFood("o2", "food-x", "res-B");
    solution.rateOrder("o1", 3);
    solution.rateOrder("o2", 3);

    auto top = solution.getTopRatedRestaurants();
    assert(top.size() == 2);
    assert(top[0] == "res-A"); // because "A" < "B"
}

void testMultipleRatingsAverage() {
    Solution solution;
    solution.init();

    solution.orderFood("o1", "food-x", "res-X");
    solution.orderFood("o2", "food-x", "res-X");
    solution.rateOrder("o1", 2);
    solution.rateOrder("o2", 4); // avg = 3.0

    auto top = solution.getTopRatedRestaurants();
    assert(top[0] == "res-X");
}

void testTopByFoodItem() {
    Solution solution;
    solution.init();

    solution.orderFood("o1", "food-apple", "res-1");
    solution.orderFood("o2", "food-apple", "res-2");
    solution.rateOrder("o1", 5);
    solution.rateOrder("o2", 3);

    auto top = solution.getTopRestaurantsByFood("food-apple");
    assert(top[0] == "res-1");
}

void testNoOrders() {
    Solution solution;
    solution.init();

    auto top = solution.getTopRatedRestaurants();
    assert(top.empty());

    auto topByFood = solution.getTopRestaurantsByFood("some-food");
    assert(topByFood.empty());
}

void runAllTests() {
    testSingleOrderRating();
    testRatingTieBreaker();
    testMultipleRatingsAverage();
    testTopByFoodItem();
    testNoOrders();

    cout << "✅ All tests passed!" << endl;
}

// Using observer pattern to update the rating in rating strategies

int main() {
    Solution solution;

    // Test cases to validate the solution
    solution.init();

    solution.orderFood("order-0", "food-1", "restaurant-0");
    solution.rateOrder("order-0", 3);

    solution.orderFood("order-1", "food-0", "restaurant-2");
    solution.rateOrder("order-1", 1);

    solution.orderFood("order-2", "food-0", "restaurant-1");
    solution.rateOrder("order-2", 3);

    solution.orderFood("order-3", "food-0", "restaurant-2");
    solution.rateOrder("order-3", 5);

    solution.orderFood("order-4","food-0", "restaurant-0");
    solution.rateOrder("order-4", 3);

    solution.orderFood("order-5", "food-0", "restaurant-1");
    solution.rateOrder("order-5", 4);

    solution.orderFood("order-6", "food-1", "restaurant-0");
    solution.rateOrder("order-6", 2);

    solution.orderFood("order-7", "food-1", "restaurant-0");
    solution.rateOrder("order-7", 2);

    solution.orderFood("order-8", "food-0", "restaurant-1");
    solution.rateOrder("order-8", 2);
    
    solution.orderFood("order-9", "food-0", "restaurant-1");
    solution.rateOrder("order-9", 4);

    solution.printHelper(solution.getTopRestaurantsByFood("food-0")); // returns [restaurant-1, restaurant-0, restaurant-2]
    solution.printHelper(solution.getTopRestaurantsByFood("food-1")); // returns [restaurant-0]
    solution.printHelper(solution.getTopRatedRestaurants()); // returns [restaurant-1, restaurant-2, restaurant-0]

    runAllTests();

    return 0;
}
