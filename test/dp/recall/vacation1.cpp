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

    int n;
    std::cin >> n;

    int a[n], b[n], c[n];
    for(int i = 0; i < n; i++){
        std::cin >> a[i] >> b[i] >> c[i];
    }

    std::vector<std::vector<int>> dp(n, std::vector<int>(3, 0));
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];
    for(int i = 1; i < n; i++){
        dp[i][0] = std::max(dp[i - 1][1], dp[i - 1][2]) + a[i];
        dp[i][1] = std::max(dp[i - 1][0], dp[i - 1][2]) + b[i];
        dp[i][2] = std::max(dp[i - 1][0], dp[i - 1][1]) + c[i];
    }

    int maxx = 0;
    for(int i = 0; i < 3; i++){
        maxx = std::max(maxx, dp[n - 1][i]);
    }

    std::cout << maxx << std::endl;

    return 0;
}