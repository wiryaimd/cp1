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

    int n;
    std::cin >> n;
    int h[n];
    for(int i = 0; i < n; i++){
        std::cin >> h[i];
    }

    std::vector<int> dp(n, INT32_MAX);
    dp[0] = 0;

    // push dp approach (where we update future states based on the current state)
    // for(int i = 0; i < n - 1; i++){
    //     dp[i + 1] = std::min(dp[i + 1], dp[i] + std::abs(h[i] - h[i + 1]));
    //     if(i + 2 < n){
    //         dp[i + 2] = std::min(dp[i + 2], dp[i] + std::abs(h[i] - h[i + 2]));
    //     }
    // }

    // pull dp approach (where we calculate the current state based on past states)
    for(int i = 1; i <= n; i++){
        dp[i] = std::min(dp[i], dp[i - 1] + std::abs(h[i] - h[i - 1]));
        if(i - 2 >= 0){
            dp[i] = std::min(dp[i], dp[i - 2] + std::abs(h[i] - h[i - 2])); // compare cost jump frog h[i] with h[i - 2] + total last cost dp[i - 2]
        }
    }



    std::cout << dp[n - 1] << std::endl;


    return 0;
}