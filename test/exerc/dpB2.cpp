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

    int n, w;
    std::cin >> w >> n;

    int val[n], weight[w];
    for(int i = 0; i < n; i++){
        std::cin >> weight[i] >> val[i];
    }

    std::vector<std::vector<ll>> dp(n + 1, std::vector<ll>(w + 1, 0));
    std::vector<std::vector<int>> used(n + 1, std::vector<int>(w + 1));
    for(int i = 1; i <= n; i++){
        int pos;
        for(int j = 1; j <= w; j++){
            // if(i == 0 || j == 0) continue;
            int prev = dp[i - 1][j - weight[i - 1]] + val[i - 1];
            if(j - weight[i - 1] >= 0 && dp[i - 1][j] < prev){
                dp[i][j] = prev;
                used[i][j] = weight[i - 1];
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    

    // int g = w;
    // int ix = n;
    // debug(n);
    // while(g > 0){
    //     debug(used[ix][g]);
    //     g -= used[ix][g];
    //     if(used[ix][g] == 0){
    //         break;
    //     }
    //     ix--;
    // }

    std::cout << dp[n][w] << std::endl;

    return 0;
}