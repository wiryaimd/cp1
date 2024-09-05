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
        ll a, b, c;
        std::cin >> a >> b >> c;
        ll l, r;
        if(a < c){
            l = 1;
            if(a * b <= c){
                r = -1;
            }else{
                r = b;
            }
        }else{
            l = -1;
            r = b;
        }

        std::cout << l << " " << r << std::endl;
    }

    return 0;
}