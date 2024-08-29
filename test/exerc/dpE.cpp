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
    std::cin >> n; // matrix size
    n++;

    int a[n];
    for(int i = 0; i < n; i++){ // so need input n + 1 for r,c size
        std::cin >> a[i];
    }

    std::vector<std::vector<int>> dp(n, std::vector<int>(n, INT32_MAX));
    for(int i = 0; i < n; i++){ // eg. input = 4, then row = 4 + 1 = 5
        dp[i][i] = 0; // init diagonal to 0
    }

    // zero-index not used because start i = 1
    for(int l = 2; l < n; l++){
        for(int i = 1; i < n - l + 1; i++){
            int j = i + l - 1;
            debug(i);

            for(int k = i; k < j; k++){
                dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k + 1][j] + (a[i - 1] * a[k] * a[j]));
                /*
                    using formula above and using k to make so can form parentheses like
                                       dp[i][k] + dp[k + 1][j]
                    A x (B x C x D) -> dp[1][1] + dp[2][4]
                    (A x B) (C x D) -> dp[1][2] + dp[3][4]
                    (A x B x C) x D -> dp[1][3] + dp[4][4] 
                    etc.. which is this   i <= k < j
                */

               // when i == j eg. dp[1][1] then dp[][] == 0
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cout << dp[i][j] << " ";
        }
        std::cout << std::endl;
    }

    debug(dp[1][n - 1]);

    return 0;
}