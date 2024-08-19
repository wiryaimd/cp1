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

    int n;
    std::cin >> n;

    std::vector<long long> dp(n + 1, 0);
    dp[0] = 1; // base case

    for(int i = 1; i <= n; i++){ // count how much number of solution from i = 1 until N
        for(int j = 1; j <= 6; j++){ // loop up to 6 to count number solution from [i - j]
            if(i - j >= 0){
                dp[i] += (dp[i - j]); // add by last number of solution
                // or
                // dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
        dp[i] %= MOD;
    }

    std::cout << dp[n] << std::endl;

    return 0;
}