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

    int n, k;
    std::cin >> n >> k;

    int a[n];
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    std::vector<int> dp(n, INT32_MAX);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= k; j++){
            // debug(i - j);
            if(i - j >= 0){
                // debug(std::abs(a[i - j] - a[i]));
                dp[i] = std::min(dp[i], dp[i - j] + std::abs(a[i - j] - a[i]));
            }
        }
    }

    // for(int i = 0; i <= n; i++){
    //     debug(dp[i]);
    // }

    std::cout << dp[n - 1] << std::endl;

    return 0;
}