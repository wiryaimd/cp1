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
        int a, b;
        std::cin >> a >> b;
        if(a == 0 && b == 0){
            std::cout << "YES" << std::endl;
            continue;
        }
        
        if(a % 2 == 0 && (b % 2 == 1 || b == 0)){
            if(a == 0){
                std::cout << "NO" << std::endl;
                continue;
            }

            std::cout << "YES" << std::endl;
        }else{
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}