#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<numeric>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

using ll = long long;

int main(){

    int n, w;
    std::cin >> n >> w;

    int val[n], weight[w];
    for(int i = 0; i < n; i++){
        std::cin >> weight[i] >> val[i];
    }

    std::vector<std::vector<ll>> dp(n + 1, std::vector<ll>(w + 1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= w; j++){
            // if(i == 0 || j == 0) continue;
            if(j - weight[i - 1] >= 0){
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - weight[i - 1]] + val[i - 1]);
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= w; j++){
            std::cout << dp[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << dp[n][w] << std::endl;

    return 0;
}