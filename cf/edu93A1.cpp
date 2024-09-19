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
        
        if(a[0] + a[1] <= a[n - 1]) {
            std::cout << "1 2 " << n << std::endl;
        }else{
            std::cout << -1 << std::endl;
        }
    }

    return 0;
}