#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<numeric>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

// inline keyword used for optimizing performance by reducing function call overhead etc..
template<class T> inline bool chmax(T& a, T& b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmin(T& a, T&b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}

using ll = long long;

int main(){

    int n;
    std::cin >> n;

    int a[n][3];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            std::cin >> a[i][j];
        }
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(3, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                if(j == k) continue;
                // dp[i][j] = std::max(dp[i][j], dp[i - 1][k] + std::max(a[i], std::max(b[i], c[i])));
                dp[i][k] = std::max(dp[i][k], dp[i - 1][j] + a[i - 1][k]);
            }
        }
    }

    std::cout << std::max(dp[n][0], std::max(dp[n][1], dp[n][2])) << std::endl;

    return 0;
}