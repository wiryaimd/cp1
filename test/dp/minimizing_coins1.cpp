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

const int INF = 1e9 + 7;

// same as coin change

// std::vector<int> coins;

// int f(int x){
//     if(x < 0) return INF;
//     if(x == 0) return 0;

//     int minn = INF;
//     for(int u : coins){
//         minn = std::min(minn, f(x - u) + 1);
//     }
//     return minn;
// }

int main(){

    int n, x;
    std::cin >> n >> x;
    // coins.resize(n)

    int coins[n];
    for(int i = 0; i < n; i++){
        std::cin >> coins[i];
    }

    // int a = f(x);
    // debug(a);

    std::vector<int> dp(x + 1, INF); // tabulation (when iterative) (instead of memoization in recursive)
    dp[0] = 0;
    for(int i = 1; i <= x; i++){
        for(int u : coins){
            if(i - u >= 0){
                dp[i] = std::min(dp[i], dp[i - u] + 1);
            }
        }
    }

    std::cout << (dp[x] == INF ? -1 : dp[x]) << std::endl;

    return 0;
}