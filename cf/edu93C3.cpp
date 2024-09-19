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

    /*
        given arr ai...an
        find numbers of subarray where sum of ps[r] - ps[l] = r - l + 1
    */

    int t;
    std::cin >> t;
    while(t--){
        int n;
        std::string s;
        std::cin >> n >> s;
        int a[n];
        for(int i = 0; i < n; i++){
            a[i] = s[i] - '0';
        }

        // ps[r] - ps[l] = r - l + 1
            // notice that current formula can be rearranged to be
        // ps[r] - r = ps[l] - l + 1 ====> r - l + 1
            // so we only need calculate o(n) times (instead of on^2)

        ll ps = 0;
        std::map<int, int> freq;
        freq[0] = 1; // case where freq[ps[i] - i]++ where ps[i] - i == 0, where i = 0
        for(int i = 0; i < n; i++){
            ps += a[i]; // as ps[r]
            freq[ps - (i + 1)]++; // count how much length r - l is same (frequent)
        }

        ll cnt = 0;
        for(std::pair<int, int> u : freq){
            debug(u.second);
            // where finding numbers of subarray, then this formula n * (n + 1) / 2 usually used
            cnt += (ll)u.second * (u.second - 1) / 2;
        }

        debug(cnt);
    }

    return 0;
}