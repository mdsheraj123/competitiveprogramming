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


int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    setup(argc, argv);
    ////////////////////////////////////////

    vector<int> powersOf2(31);
    powersOf2[0] = 1;
    powersOf2[1] = 2;
    for(int i=2;i<30;i++) {
        powersOf2[i] = powersOf2[i-1]*2;
    }

    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        int a,b,c;
        cin>>a>>b>>c;

        int leafNodes = 1;

        leafNodes+=a;

        if(leafNodes!=c) {
            cout<<-1<<endl;
        } else {
            // cout<<"Maybe possible"<<endl;

            if(a==0) {
                cout<<b<<endl;
                continue;
            }

            int power = -1;
            for(int i=29;i>=0;i--) {
                if(a>=powersOf2[i]) {
                    power = i;
                    break;
                }
            }

            int answer = power+1;

            int additional = a - (powersOf2[power]-1);

            int sameLevelSpaces = powersOf2[power] - additional;

            int nextLevelSpace = 2*additional+sameLevelSpaces;


            b-=sameLevelSpaces;

            while(b>0) {
                b-=nextLevelSpace;
                answer++;
            }

            cout<<answer<<endl;
        }



    }

    return 0;
}
