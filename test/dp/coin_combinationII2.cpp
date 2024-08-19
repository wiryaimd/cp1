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

    // knapsack problem

    int n, x;
    std::cin >> n >> x;

    int coins[n];
    for(int i = 0; i < n; i++){
        std::cin >> coins[i];
    }

    std::vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= x; j++){
            if(j - coins[i] >= 0){ // tiap coin[i] satu persatu dipakai untuk dihitung ke dp[j] untuk tiap dp[j - coins[i]]
                dp[j] += dp[j - coins[i]];
                // debug(dp[j - coins[i]]);
            }
        }

        for(int k = 0; k <= x; k++){
            debug(dp[k]);
        }
        br;
    }

    return 0;
}