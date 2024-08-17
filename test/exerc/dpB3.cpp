#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<cstring>
#include<numeric>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

using ll = long long;

int main(){

    int n, k;
    std::cin >> n >> k;

    int w[k], p[k];
    for(int i = 0; i < k; i++){
        std::cin >> w[i] >> p[i];
    }

    std::vector<std::vector<ll>> dp(k + 1, std::vector<ll>(n + 1, 0));
    // std::vector<std::vector<int>> used(k, std::vector<int>(n));
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= n; j++){
            if(j - w[i - 1] >= 0){ // (con 1.1)
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + p[i - 1]);
                // used[i][j] = w[i - 1];
            }else{
                dp[i][j] = dp[i - 1][j];
                // used[i][j] = w[i - 1];
            }
        }
    }

    // for (int i = 0; i <= k; i++){
    //     for (int j = 0; j <= n; j++){
    //         std::cout << dp[i][j] << " ";
    //     }
    //     br;
    // }

    // debug(dp[k][n]);
    std::vector<int> res;

    int j = n;
    for(; j > 0; j--){
        if(dp[k][j] != dp[k][j - 1]){
            break;
        }
    }

    int x = j;
    int curr = k;
    while(x >= 0){ // backtracking method
        if(dp[curr][x] != dp[curr - 1][x]){ // when dp[i] != dp[i - 1] which is taking w[i - 1] from condition in if(j - w[i - 1] >= 0) (con 1.1)
            // debug(w[curr - 1]);
            // debug(curr);
            res.push_back(curr);
            x -= w[curr - 1];
        }
        curr--;

        if(curr == 0){
            break;
        }
    }

    std::sort(res.begin(), res.end());
    for(int i = 0; i < res.size(); i++) std::cout << res[i] << std::endl;

    return 0;
}