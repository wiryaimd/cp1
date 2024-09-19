#ifndef ONLINE_JUDGE
#include "../debug.hpp"
#else
#define debug(...)
#define debugArr(...)
#endif

#define br std::cerr << std::endl;

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
        std::map<ll, ll> mp;
        for(int i = 0; i < n; i++){
            std::cin >> a[i];
            mp[a[i]]++;
        }

        ll res = 0;
        ll total = 0;
        for(std::pair<ll, ll> p : mp){
            if(p.second >= 3){
                res += (p.second * (p.second - 1) * (p.second - 2)) / 6; // nCr when 3 side is same
            }

            if(p.second >= 2){
                res += ((p.second * (p.second - 1)) / 2) * total; // nCr when 2 side same multiply* previous total a_-1
            }

            total += p.second;
        }

        std::cout << res << std::endl;
    }

    return 0;
}