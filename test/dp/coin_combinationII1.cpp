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
        (double counting prob)
        given target x, and n coins with n[i] value
        count number of combination that the sum equal to x, with unique combination (different with coin combination 1 prob)

        sol
            the things that not sum total coins above dp[i + 1] instead, sum the previous one eg. dp[i - 1][j] // cmiiw

            eg target = 5
            eg coins = {1, 2, 5}
            use 2d dp,
            dp[3][] can only use {5} coins
            dp[2][] can only use {2, 5} coins
            dp[1][] can use {1, 2, 5} coins

            it can reversed as
            dp[1][] = {1}
            dp[2][] = {1, 2}
            dp[3][] = {1, 2, 5}

            it will make no duplicate counted for each row in dp, where 
            dp[2][] += dp[2 - 1][] will count dp[1] which is can only use {1} coins

    */
 
    int n, x;
    std::cin >> n >> x;
 
    int coins[n];
    for(int i = 0; i < n; i++){
        std::cin >> coins[i];
    }
 
    std::vector<std::vector<int>> dp(n, std::vector<int>(x + 1, 0));
    for(int i = 0; i < n; i++){
        dp[i][0] = 1;
    }
 
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= x; j++){
            if(j - coins[i] >= 0){
                dp[i][j] += dp[i][j - coins[i]];
            }
            if(i - 1 >= 0){
                dp[i][j] += dp[i - 1][j];
            }
        }
    }
 
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j <= x; j++){
    //         std::cout << dp[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
 
 
    std::cout << dp[n - 1][x] << std::endl;
 
    return 0;
}