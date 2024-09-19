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

    //dp i
    int t;
    std::cin >> t;
    while(t--){
        int n, d;
        std::cin >> n >> d;

        int c[n];
        for(int i = 0; i < n; i++){
            std::cin >> c[i];
        }

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(d + 1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= d; j++){
                dp[i][j] = std::min(dp[i][j - 1], dp[i - 1][j]) + c[i - 1] * (j * j);
            }
        }

        debug(dp);
    }

    return 0;
}