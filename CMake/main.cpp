/*
author: a_natural
//////////////
Use long long instead of long always.
printf("%.2lf", double_value);  // 4.00
*/
///////////////////////////////////////////////////////////////
// #include <bits/stdc++.h>
#include <assert.h>
#include <cxxabi.h>     // Demangling type name so that it is human-readable
#include <float.h>      // DBL_MAX
#include <math.h>       // ceil/floor
#include <semaphore.h>  // sem_t m; sem_init(&m, 0, 1); sem_destroy(&m); sem_wait(&m); sem_post(&m);
#include <time.h>       // clock_t clock(); CLOCKS_PER_SEC
#include <unistd.h>     // sleep(10) in seconds and usleep(10)

#include <algorithm>  // max/min lower_bound/upper_bound binary_search reverse next_permutation
#include <bitset>     // (c & a).any() and access like array
#include <chrono>     // system time
#include <climits>    // INT_MIN LLONG_MAX
#include <condition_variable>
// rand() and srand()
#include <cstdlib>
// provides functions for dealing with C-style strings. It creates null-terminated arrays of characters.
#include <cstring>
#include <deque>
// fstream fio("sample.txt",ios::trunc|ios::out|ios::in); fio<<line; getline(fio,line); fio.close();
#include <fstream>
#include <functional>
#include <iomanip>  // cout<<setprecision(5); contain functions to manipulate i/o format.
#include <iostream>
#include <list>     // doubly linked list and variable.sort(vector like compare);
#include <map>      // sorts by key
#include <memory>   // unique_ptr/shared_ptr/weak_ptr
#include <mutex>    // mutex n; n.lock(); n.unlock();
#include <numeric>  // gcd there will be sqiggly red line but no compilation error
// priority_queue <int, vector<int>, greater<int>> minHeap; (priority_queue is by default max heap)
#include <queue>
// sorts by value
#include <set>
#include <stack>
#include <string>
// thread my_thread(runner, 10, " ready"); my_thread.join();
#include <thread>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// cout << "Line 1..." << flush; or default endl for interactive programs
#define endl "\n"
using namespace std;

void setup(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef I_AM_DEBUGGING
    freopen("../input.txt", "r", stdin);
    string inputFlag = argc > 1 ? argv[1] : "";
    if (inputFlag == "OUTPUT_TO_FILE") {
        freopen("../output.txt", "w", stdout);
    } else {
        cout << "c++ version is " << __cplusplus << endl;
#ifdef __clang__
        cout << "clang++ " << __clang_major__ << "." << __clang_minor__ << ".";
        cout << __clang_patchlevel__ << endl;
#elif _MSC_VER
        cout << "MSVC " << _MSC_VER << endl;
#else
        cout << "g++ " << __GNUC__ << "." << __GNUC_MINOR__ << ".";
        cout << __GNUC_PATCHLEVEL__ << endl;
#endif
    }
#endif
}

// For map like
// map<int, int, cmp> myMap;
// struct comp {
//     bool operator()(int a, int b) const {
//         return a < b;  // true means a definitely before b
//     }
// };

// For unordered_map like
// std::unordered_map<tuple<int, int>, int, customHash> myMap;
// struct customHash {
//     size_t operator()(const tuple<int, int>& a) const {
//         // max value of second element is 99.
//         return get<0>(a)*100+get<1>(a);
//     }
// };

/*
NOTES:


*/
///////////////////////////////////////////////////////////////

class Vehicle {
   public:
    Vehicle(int id, int numberOfWheels) {
        mId = id;
        mNumberOfWheels = numberOfWheels;
    }
    int getNumberOfWheels() {
        return mNumberOfWheels;
    }
    int getId() {
        return mId;
    }

   private:
    int mNumberOfWheels;
    int mId;
};

class TwoWheeler : Vehicle {
   public:
    TwoWheeler(int id, int numberOfWheels) : Vehicle(id, 2) {
    }

   private:
};

class FourWheeler : Vehicle {
   public:
    FourWheeler(int id, int numberOfWheels) : Vehicle(id, 4) {
    }
    void setCng(bool isCng) {
        mIsCng = isCng;
    }
    bool getCng() {
        return mIsCng;
    }

   private:
    bool mIsCng;
};

class ParkingSpace {
   public:
    ParkingSpace(int id, int capacity) {
        mId = id;
        mCapacity = capacity;
    }

    int getId() {
        return mId;
    }

    int getCapacity() {
        return mCapacity;
    }

   private:
    int mId;
    int mCapacity;
};

class ParkingLot {
   public:
    ParkingLot(int id) {
        mId = id;
    }

    void addParkingSpace(ParkingSpace* parkingSpace) {
        int parkingSpaceId = parkingSpace->getId();
        mParkingSpace[parkingSpaceId] = parkingSpace;
        mAvailableParking[mParkingSpace[parkingSpaceId]->getCapacity()].insert(parkingSpaceId);
    }

    void park(Vehicle* parkingVehicle) {
        int parkingVehicleId = parkingVehicle->getId();
        int neededCapacity = parkingVehicle->getNumberOfWheels() / 2;

        mParkingVehicles[parkingVehicleId] = parkingVehicle;

        if (neededCapacity == 1 && mAvailableParking.count(1) != 0) {
            int parkingSpaceId = *mAvailableParking[1].begin();
            mAvailableParking[1].erase(parkingSpaceId);
            if (mAvailableParking[1].size() == 0) {
                mAvailableParking.erase(1);
            }

            mVehicleParkingLocation[parkingVehicleId] = parkingSpaceId;
        } else {
            if (mAvailableParking.count(2) != 0) {
                int parkingSpaceId = *mAvailableParking[2].begin();
                mAvailableParking[2].erase(parkingSpaceId);

                if (neededCapacity == 1) {
                    mAvailableParking[1].insert(parkingSpaceId);
                }

                if (mAvailableParking[2].size() == 0) {
                    mAvailableParking.erase(2);
                }

                mVehicleParkingLocation[parkingVehicleId] = parkingSpaceId;
            } else {
                cout << "Error" << endl;
            }
        }
    }

    void removeVehicle(int id) {
        int vehicleParkingLocation = mVehicleParkingLocation[id];
        int neededSpace = mParkingVehicles[id]->getNumberOfWheels() / 2;

        if (neededSpace == 1) {
            if (mAvailableParking[1].count(vehicleParkingLocation) != 0) {
                mAvailableParking[1].erase(vehicleParkingLocation);
                mAvailableParking[2].insert(vehicleParkingLocation);
            } else {
                mAvailableParking[1].insert(vehicleParkingLocation);
            }
        } else {
            mAvailableParking[2].insert(vehicleParkingLocation);
        }

        mVehicleParkingLocation.erase(id);
        delete mParkingVehicles[id];
        mParkingVehicles.erase(id);
    }

    void printParkingSpaceAndParkedVehicles() {
        cout << "Vehicle id to parking id" << endl;
        for (auto itr = mVehicleParkingLocation.begin(); itr != mVehicleParkingLocation.end(); itr++) {
            cout << itr->first << " " << itr->second << endl;
        }
    }

   private:
    int mId;
    // Data and state are seperated
    unordered_map<int, Vehicle*> mParkingVehicles;    // id to instance
    unordered_map<int, ParkingSpace*> mParkingSpace;  // id to instance
    // available capacity to id
    unordered_map<int, set<int>> mAvailableParking;
    // Vehicle id to parking id
    unordered_map<int, int> mVehicleParkingLocation;
};

int main(int argc, char* argv[]) {
    setup(argc, argv);
    // int T;
    // cin >> T;
    // for (int test_case = 1; test_case <= T; test_case++) {
    // }

    ParkingLot* myParkingLot = new ParkingLot(1);
    ParkingSpace* parkingSpace1 = new ParkingSpace(1, 2);
    ParkingSpace* parkingSpace2 = new ParkingSpace(2, 1);

    myParkingLot->addParkingSpace(parkingSpace1);
    myParkingLot->addParkingSpace(parkingSpace2);

    TwoWheeler* bike1 = new TwoWheeler(1, 2);
    myParkingLot->park((Vehicle*)bike1);
    myParkingLot->printParkingSpaceAndParkedVehicles();

    TwoWheeler* bike2 = new TwoWheeler(2, 2);
    myParkingLot->park((Vehicle*)bike2);
    myParkingLot->printParkingSpaceAndParkedVehicles();

    TwoWheeler* bike3 = new TwoWheeler(3, 2);
    myParkingLot->park((Vehicle*)bike3);
    myParkingLot->printParkingSpaceAndParkedVehicles();

    myParkingLot->removeVehicle(1);
    myParkingLot->printParkingSpaceAndParkedVehicles();

    TwoWheeler* bike4 = new TwoWheeler(4, 2);
    myParkingLot->park((Vehicle*)bike4);
    myParkingLot->printParkingSpaceAndParkedVehicles();

    TwoWheeler* bike5 = new TwoWheeler(5, 2);
    myParkingLot->park((Vehicle*)bike5);
    myParkingLot->printParkingSpaceAndParkedVehicles();
    return 0;
}
