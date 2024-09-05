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
        int x;
        std::cin >> x;
        int maxx = 1;
        int y = 1;
        for(int i = 1; i < x; i++){
            int gcd = std::__gcd(x, i) + i;
            if(gcd > maxx){
                maxx = gcd;
                y = i;
            }
        }
        std::cout << y << std::endl;
    }

    return 0;
}