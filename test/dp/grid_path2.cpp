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

const int MOD = 1e9 + 7;

int main(){

    /*
        theres some position contain '*' which is blocked

        calculate the number of paths from the upper-left square to the 
        lower-right square and can only move right or down.
    */

    int n;
    std::cin >> n;

    std::vector<std::vector<bool>> path(n, std::vector<bool>(n, false));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char a;
            std::cin >> a;
            path[i][j] = a == '*';
        }
    }

    std::vector<std::vector<ll>> dp(n, std::vector<ll>(n + 1, 0));
    dp[0][0] = 1L; // base case
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= n; j++){
            if(path[i][j - 1]) continue; // path[][] blocked then skip and let dp[i][j] == 0

            dp[i][j] += dp[i][j - 1]; // count previous left dp[][j - 1] and
            if(i - 1 >= 0){
                dp[i][j] += dp[i - 1][j]; // count prvious top dp[i - 1][]
            }

            dp[i][j] %= MOD;
        }
    }

    std::cout << dp[n - 1][n] % MOD << std::endl;

    return 0;
}