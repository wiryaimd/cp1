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
        int n, k;
        std::cin >> n >> k;
        int h[n];
        for(int i = 0; i < n; i++){
            std::cin >> h[i];
        }

        std::vector<ll> a(n + 1, 0);
        for(int i = 0; i < n; i++){
            int x;
            std::cin >> x;
            a[std::abs(x) - 1] += h[i]; // make as 0-based using -1
        }

        ll curr = 0;
        bool posb = true;
        for(int i = 0; i < n; i++){ // use i as how much monster move passed for each shoot
            curr += k; // add k ammo for each shoot
            if(a[i] > curr){
                posb = false;
                break;
            }else{
                curr -= a[i]; // remaining ammo also still stored in curr + k for each move
            }
        }

        std::cout << (posb ? "YES" : "NO") << std::endl;
    }

    return 0;
}