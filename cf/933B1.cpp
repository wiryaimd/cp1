/*
 * Prob: #
 * File Created: Friday, 6th September 2024 10:44:52 am, 13min
 * Author: Wiryaimd
 */


#ifndef ONLINE_JUDGE
#include "../debug.hpp"
#else
#define debug(...)
#define debugArr(...)
#endif

#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<cstring>
#include<numeric>

using ll = long long;
const ll INF = 1e18 + 7;

int main(){

    int t;
    std::cin >> t;
    while(t--){
        int n;
        std::cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            std::cin >> a[i];
        }

        bool pass = true;
        for(int i = 0; i < n - 2; i++){
            if(a[i] < 0){
                pass = false;
                break;
            }
            if(a[i] == 0) continue;

            a[i + 1] -= a[i] * 2;
            a[i + 2] -= a[i];
            a[i] = 0;
        }

        for(int i = 0; i < n; i++){
            if(a[i] != 0){
                pass = false;
                break;
            }
        }

        std::cout << (pass ? "YES" : "NO") << std::endl;
    }

    return 0;
}