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

int f(int x, int a[50], int n){
    if(x >= n) return 0;

    int r = std::abs(a[x] - a[x + 1]) + f(x + 1, a, n);
    int m = std::abs(a[x] - a[x + 2]) + f(x + 2, a, n);
    return std::min(r, m);
}

int main(){

    int n;
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    std::vector<int> dp(n, INT32_MAX);
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        dp[i] = dp[i - 1] + std::abs(a[i] - a[i - 1]);
        if(i - 2 >= 0){
            dp[i] = std::min(dp[i], dp[i - 2] + std::abs(a[i] - a[i - 2]));
        }
    }

    for(int i = 0; i < n; i++){
        std::cout << dp[i] << " ";
    }
    br;
    std::cout << dp[n - 1] << std::endl;

    return 0;
}