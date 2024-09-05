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
        ll m, x;
        std::cin >> m >> x;

        ll c[m], h[m];
        int maxxh = 0;

        for(int i = 0; i < m; i++){
            std::cin >> c[i] >> h[i];
            maxxh += h[i];
        }

        int maxx = 0;
        std::vector<std::vector<ll>> dp(m + 1, std::vector<ll>(maxxh + 1, INF));
        for(int i = 0; i < m; i++){
            dp[i][0] = 0;
        }        

        for(int i = 1; i <= m; i++){
            for(int j = 0; j <= maxxh; j++){
                if(j - h[i - 1] >= 0 && dp[i - 1][j - h[i - 1]] + c[i - 1] <= (i - 1) * x){
                    dp[i][j] = std::min(dp[i - 1][j], dp[i - 1][j - h[i - 1]] + c[i - 1]);
                }else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        debug(dp);
        for(int i = 0; i <= maxxh; i++){
            if(dp[m][i] <= (m - 1) * x){
                maxx = i;
            }
        }

        std::cout << maxx << std::endl;
        debug(maxx);
    }

    return 0;
}