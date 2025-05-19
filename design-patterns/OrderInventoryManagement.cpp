// Question: https://codezym.com/question/4

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
#include <shared_mutex>
#include <thread>

using namespace std;

class Seller {
    unordered_set<string> pincodes;
    unordered_set<string> modes;

public:
    Seller(vector<string>& serviceablePincodes, vector<string>& paymentModes) {
        pincodes = unordered_set<string>(serviceablePincodes.begin(), serviceablePincodes.end());
        modes = unordered_set<string>(paymentModes.begin(), paymentModes.end());
    }

    bool isPincodeSupported(string pincode) {
        return pincodes.find(pincode) != pincodes.end();
    }

    bool isPaymentSupported(string paymentMode) {
        return modes.find(paymentMode) != modes.end();
    }
};

class SellerManager {
    unordered_map<string, Seller> sellers;
    mutable shared_mutex seller_mutex;

public:
    void createSeller(string sellerId, vector<string>& serviceablePincodes,
        vector<string>& paymentModes) {
        unique_lock lock(seller_mutex);
        sellers.insert({sellerId, Seller(serviceablePincodes, paymentModes)});
    }

    unique_ptr<Seller> getSeller(string sellerId) {
        shared_lock lock(seller_mutex);
        if (sellers.find(sellerId) == sellers.end()) {
            return nullptr;
        }
        return make_unique<Seller>(sellers.find(sellerId)->second);
    }
};

class InventoryManager {
    unordered_map<int, unordered_map<string, int>> inventory;
    mutable shared_mutex inventory_mutex;

public:
    void addInventory(int productId, string sellerId, int delta) {
        unique_lock lock(inventory_mutex);
        if (inventory.find(productId) == inventory.end()) {
            inventory.insert({productId, unordered_map<string, int>()});
        }

        auto& sellers = inventory[productId];
        if (sellers.find(sellerId) == sellers.end()) {
            sellers.insert({sellerId, 0});
        }

        sellers[sellerId] += delta;
    }

    bool reduceInventory(int productId, string sellerId, int delta) {
        unique_lock lock(inventory_mutex);
        if (inventory.find(productId) == inventory.end()) {
            return false;
        }

        auto& sellers = inventory[productId];
        if (sellers.find(sellerId) == sellers.end()) {
            return false;
        }

        if (sellers[sellerId] < delta) {
            return false;
        }

        sellers[sellerId] -= delta;

        return true;
    }

    int getInventory(int productId, string sellerId) {
        shared_lock lock(inventory_mutex);
        if (inventory.find(productId) == inventory.end()) {
            return 0;
        }

        auto& sellers = inventory[productId];
        if (sellers.find(sellerId) == sellers.end()) {
            return 0;
        }

        return sellers[sellerId];
    }
};

class Solution {
    SellerManager sellerManager;
    InventoryManager inventoryManager;

public:
    Solution(int productsCount) {

    }

    void createSeller(string sellerId, vector<string> serviceablePincodes,
                      vector<string> paymentModes) {
        sellerManager.createSeller(sellerId, serviceablePincodes, paymentModes);
    }

    void addInventory(int productId, string sellerId, int delta) {
        inventoryManager.addInventory(productId, sellerId, delta);
    }

    int getInventory(int productId, string sellerId) {
        return inventoryManager.getInventory(productId, sellerId);
    }

    string createOrder(string orderId, string destinationPincode, string sellerId, int productId,
                     int productCount, string paymentMode) {
        unique_ptr<Seller> seller = sellerManager.getSeller(sellerId);
        if (seller == nullptr) {
            return "Seller unavilable";
        }
        if (seller->isPincodeSupported(destinationPincode) == false) {
            return "pincode unserviceable";
        }
        if (seller->isPaymentSupported(paymentMode) == false) {
            return "payment mode not supported";
        }

        bool reduced = inventoryManager.reduceInventory(productId, sellerId, productCount);

        return reduced ? "order placed" : "insufficient product inventory";
    }
};

// Worker to create sellers
void createSellers(Solution& solution) {
    solution.createSeller("seller-1", {"123456", "654321"}, {"upi", "netbanking"});
    solution.createSeller("seller-2", {"111111", "222222"}, {"cash", "upi"});
}

// Worker to add inventory
void addInventory(Solution& solution) {
    for (int i = 0; i < 10; ++i) {
        solution.addInventory(100 + i % 2, "seller-1", 50);
        solution.addInventory(100 + i % 2, "seller-2", 30);
        this_thread::sleep_for(chrono::milliseconds(10));
    }
}

// Worker to place orders
void placeOrders(Solution& solution, int id) {
    for (int i = 0; i < 5; ++i) {
        string response = solution.createOrder("order-" + to_string(id * 10 + i),
                                               "123456", "seller-1", 100, 1, "upi");
        cout << "[Thread " << id << "] " << response << endl;
        this_thread::sleep_for(chrono::milliseconds(15));
    }
}

// Worker to read inventory
void readInventory(Solution& solution, int id) {
    for (int i = 0; i < 5; ++i) {
        int inv = solution.getInventory(100, "seller-1");
        cout << "[Inventory Reader " << id << "] Inventory: " << inv << endl;
        this_thread::sleep_for(chrono::milliseconds(12));
    }
}

void runTests() {
    Solution solution(100);

    thread t1(createSellers, ref(solution));
    thread t2(addInventory, ref(solution));

    t1.join();
    t2.join();

    // Start multiple threads placing orders and checking inventory
    thread order1(placeOrders, ref(solution), 1);
    thread order2(placeOrders, ref(solution), 2);
    thread reader1(readInventory, ref(solution), 1);
    thread reader2(readInventory, ref(solution), 2);

    order1.join();
    order2.join();
    reader1.join();
    reader2.join();
}

int main() {
    // Test cases to validate the solution
    Solution solution(10);

    solution.createSeller("seller-0", {"110001", "560092", "452001", "700001"}, {"netbanking", "cash", "upi"});
    solution.createSeller("seller-1", {"400050", "110001", "600032", "560092"}, {"netbanking", "cash", "upi"});
    solution.addInventory(0, "seller-1", 52);
    solution.addInventory(0, "seller-0", 32);
    cout << solution.createOrder("order-1", "400050", "seller-1", 0, 5, "upi") << endl; // returned "order placed"
    cout << solution.getInventory(0, "seller-1") << endl; // returned 47
    cout << solution.createOrder("order-2", "560092", "seller-0", 0, 1, "upi") << endl; // returned "order placed"
    cout << solution.getInventory(0, "seller-0") << endl; // returned 31

    runTests();

    return 0;
}
