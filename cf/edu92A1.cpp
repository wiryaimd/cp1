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
        int l, r;
        std::cin >> l >> r;
        if((ll)l * 2 > r){
            std::cout << -1 << " " << -1 << std::endl;
            continue;
        }

        std::cout << l << " " << l * 2 << std::endl;
    }

    return 0;
}