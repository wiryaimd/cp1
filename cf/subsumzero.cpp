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

    // find numbers of subarray that sum equal to zero

    int n;
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++){
        std::cin >> a[i]; // each ai may negative
    }

    ll ps = 0;
    ll cnt = 0;
    std::map<int, int> mp;
    mp[0] = 1;
    for(int i = 0; i < n; i++){
        ps += a[i];
        cnt += mp[ps];
        mp[ps]++;
    }

    std::cout << cnt << std::endl;

    return 0;
}