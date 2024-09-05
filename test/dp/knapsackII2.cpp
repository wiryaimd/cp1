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
const ll INF = INT32_MAX;

int main(){

    ll n, w;
    std::cin >> n >> w;

    int weight[n], v[n];
    int maxv = 0;
    for(int i = 0; i < n; i++){
        std::cin >> weight[i] >> v[i];
        maxv += v[i];
    }

    std::vector<std::vector<ll>> dp(n + 1, std::vector<ll>(maxv + 1, INF)); // careful LLONGMAX + some int can lead exceed size
    for(int i = 0; i <= n; i++){
        dp[i][0] = 0;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= maxv; j++){
            if(j - v[i - 1] >= 0){
                dp[i][j] = std::min(dp[i - 1][j], dp[i - 1][j - v[i - 1]] + weight[i - 1]);
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    int res = 0;
    for(int i = 0; i <= maxv; i++){
        if(dp[n][i] <= w){
            debug(dp[n][i]);
            res = i;
        }
    }

    std::cout << res << std::endl;

    return 0;
}