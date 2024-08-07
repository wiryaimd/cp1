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

    int n, x;
    std::cin >> n >> x;

    int coins[n];
    for(int i = 0; i < n; i++){
        std::cin >> coins[i];
    }

    std::vector<long long> dp(x + 1, 0);
    dp[0] = 1; // base case
    for(int i = 0; i < x; i++){ // topological order (i = 1; i <= x if pull dp approach)
        for(int u : coins){ // topo. order
            // if(i - u >= 0){
                // using i - u because to get how much solution we get when sum start with dp[ith - u], then dp[2th - u], then dp[3th - u] and so on
                // dp[i] += dp[i - u]; // relation


                // dp[i] += up to total u coins, store total dp[i] if use coin ith - u because it using pull dp, instead of push dp (eg. ith + u)
            // }

            if(i + u <= x){
                dp[i + u] += dp[i];
                // current i coin says that have M solution, then store in +u and get accumulate for [i + u] position coin
            }
        }
        dp[i] = dp[i] % MOD;
    }

    for(int i = 0; i < dp.size(); i++){
        debug(dp[i]);
    }

    std::cout << dp[x] << std::endl; // original problem

    return 0;
}