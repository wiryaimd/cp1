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

    std::vector<int> dp(n + 1, 0);
    dp[0] = 1; // or dp[0] = 0 for using base case
    dp[1] = 1;
    for(int i = 2; i < n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    for(int i = 0; i < n; i++){
        debug(dp[i]);
    }

    std::cout << dp[n - 1] << std::endl;

    return 0;
}