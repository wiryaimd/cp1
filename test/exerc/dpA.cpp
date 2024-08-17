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
    std::cin >> n;

    int coins[n];
    for(int i = 0; i < n; i++){
        std::cin >> coins[i];
    }

    std::cin >> k;

    std::vector<int> dp(k + 1, 1e5 + 7);
    dp[0] = 0;
    for(int i = 1; i <= k; i++){
        for(int c : coins){
            if(i - c >= 0) dp[i] = std::min(dp[i], dp[i - c] + 1);
        }
    }

    std::cout << dp[k] << std::endl;

    return 0;
}