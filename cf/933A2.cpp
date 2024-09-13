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
        int n, m, k;
        std::cin >> n >> m >> k;
        int b[n], c[m];

        for(int i = 0; i < n; i++){
            std::cin >> b[i];
        }

        for(int i = 0; i < m; i++){
            std::cin >> c[i];
        }

        ll cnt = 0;
        for(int i = 0; i < n; i++){
            int r = 0;
            for(int j = 0; j < m; j++){
                if(c[j] <= k - b[i]) r++;
            }
            cnt += r;
        }

        std::cout << cnt << std::endl;
    }

    return 0;
}