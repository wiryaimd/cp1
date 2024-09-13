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
        int n, k, z;
        std::cin >> n >> k >> z;

        int a[n + 1];
        for(int i = 1; i <= n; i++){
            std::cin >> a[i];
        }
        std::vector<std::vector<std::vector<int>>> dp(k + 1, std::vector<std::vector<int>>(6, std::vector<int>(2, -1)));
        dp[0][0][0] = a[1];
        
        for(int i = 0; i < k; i++){
            for(int j = 0; j <= z; j++){
                int pos = i + 1 - j * 2;
                debug(pos);
                if(pos < i) continue;
                
                dp[i + 1][j][0] = std::max(dp[i + 1][j][0], std::max(dp[i][j][0], dp[i][j][1]) + a[pos + 1]);
                if(pos > 1 && j < z){
                    dp[i + 1][j + 1][1] = std::max(dp[i + 1][j + 1][1], dp[i][j][0] + a[pos - 1]);
                }
            }
        }

        int res = 0;
        // debug(dp);
        for(int i = 0; i <= z; i++){
            // debug(dp[k][i]);
            res = std::max(res, std::max(dp[k][i][0], dp[k][i][1]));
        }

        std::cout << res << std::endl;
        // debug(res);
    }

    return 0;
}