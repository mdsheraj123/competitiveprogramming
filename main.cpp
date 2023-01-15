/*
author: a_natural
//////////////
Use long long instead of long always.
printf("%.2lf", double_value);  // 4.00
*/
///////////////////////////////////////////////////////////////
// #include <bits/stdc++.h>
#include <assert.h>
#include <cxxabi.h>     //Demangling type name so that it is human-readable
#include <float.h>      //DBL_MAX
#include <math.h>       //ceil/floor
#include <semaphore.h>  //sem_t m;sem_init(&m, 0, 1);sem_destroy(&m);sem_wait(&m);sem_post(&m);
#include <time.h>       //clock_t clock() //CLOCKS_PER_SEC
#include <unistd.h>     //sleep(10) in seconds

#include <algorithm>  //max/min //lower_bound/upper_bound //binary_search //reverse //next_permutation
#include <bitset>     //(c & a).any() //access like array
#include <chrono>     //system time
#include <climits>    //INT_MIN //LLONG_MAX
#include <condition_variable>
#include <cstdlib>  //rand() //srand()
#include <cstring>  //provides functions for dealing with C-style strings — null-terminated arrays of characters.
#include <deque>
#include <fstream>  //fstream fio("sample.txt",ios::trunc|ios::out|ios::in);fio<<line;getline(fio,line);fio.close();
#include <functional>
#include <iomanip>  //cout<<setprecision(5); contain functions to manipulate i/o format.
#include <iostream>
#include <list>     //doubly linked list //variable.sort(vector like compare);
#include <map>      //sorts by key
#include <memory>   //unique_ptr/shared_ptr/weak_ptr
#include <mutex>    //mutex n;n.lock();n.unlock();
#include <numeric>  //gcd //there will be sqiggly red line but no compilation error
#include <queue>    //priority_queue <int, vector<int>, greater<int>> minHeap; (priority_queue default is max heap)
#include <set>      //sorts by value
#include <stack>
#include <string>
#include <thread>  //thread my_thread(runner, 10, " ready");my_thread.join();
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define endl "\n"  // cout << "Line 1..." << flush; for interactive programs
using namespace std;

// struct comp {
//     bool operator()(int a, int b) const {
//         return a < b;  // true means a definitely before b
//     }
// };

// struct customHash {
//     size_t operator()(tuple<int, int> a) const {
//         return 100;
//     }
// };

void setup() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef I_AM_DEBUGGING
    freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    cout << "c++ version is " << __cplusplus << endl;
#ifdef __clang__
    cout << "clang++ " << __clang_major__ << "." << __clang_minor__ << "." << __clang_patchlevel__ << endl;
#elif _MSC_VER
    cout << "MSVC " << _MSC_VER << endl;
#else
    cout << "g++ " << __GNUC__ << "." << __GNUC_MINOR__ << "." << __GNUC_PATCHLEVEL__ << endl;
#endif
#endif
}
///////////////////////////////////////////////////////////////

int main() {
    setup();
    // int T;
    // cin >> T;
    // for (int test_case = 1; test_case <= T; test_case++) {
    // }

    int n;
    cin >> n;

    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<long long> prefixSum(n);
    for (int i = 0; i < n; i++) {
        prefixSum[i] = (long long)a[i] * b[i];
        if (i >= 1) {
            prefixSum[i] += prefixSum[i - 1];
        }
    }
    long long answer = prefixSum[n - 1];

    vector<long long> reversePrefixSum1(n);  // center at i
    vector<long long> reversePrefixSum2(n);  // center at i+0.5

    for (int center = 0; center < n; center++) {
        memset(reversePrefixSum1.data(), 0, sizeof(long long) * n);
        memset(reversePrefixSum2.data(), 0, sizeof(long long) * n);

        for (int distance = 0; center - distance >= 0 && center + distance < n; distance++) {
            reversePrefixSum1[center - distance] = (long long)a[center + distance] * b[center - distance];
            reversePrefixSum1[center + distance] = (long long)a[center - distance] * b[center + distance];
        }
        for (int j = 1; j < n; j++) {
            reversePrefixSum1[j] += reversePrefixSum1[j - 1];
        }
        //////////////
        for (int distance = 1; center - distance + 1 >= 0 && center + distance < n; distance++) {
            reversePrefixSum2[center - distance + 1] = (long long)a[center + distance] * b[center - distance + 1];
            reversePrefixSum2[center + distance] = (long long)a[center - distance + 1] * b[center + distance];
        }
        for (int j = 1; j < n; j++) {
            reversePrefixSum2[j] += reversePrefixSum2[j - 1];
        }

        //////////////

        for (int distance = 1; distance < n; distance++) {
            long long sum = 0;
            if (center - distance >= 0 && center + distance < n) {
                if (center - distance == 0) {
                    sum += reversePrefixSum1[center + distance];
                } else {
                    sum += prefixSum[center - distance - 1];
                    sum += reversePrefixSum1[center + distance] - reversePrefixSum1[center - distance - 1];
                }
                sum += prefixSum[n - 1] - prefixSum[center + distance];
                answer = max(answer, sum);
            }
            sum = 0;
            if (center - distance + 1 >= 0 && center + distance < n) {
                if (center - distance + 1 == 0) {
                    sum += reversePrefixSum2[center + distance];
                } else {
                    sum += prefixSum[center - distance];
                    sum += reversePrefixSum2[center + distance] - reversePrefixSum2[center - distance];
                }
                sum += prefixSum[n - 1] - prefixSum[center + distance];
                answer = max(answer, sum);
            }
        }
    }

    cout << answer << endl;

    return 0;
}