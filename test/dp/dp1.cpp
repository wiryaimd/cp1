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

    // given 2d data, count total possible path from 0,0 to n,m that only can move 'down' and 'right'
    int n = 3, m = 3;
    std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));

    // iterative version
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i + 1 < n) dp[i + 1][j] += dp[i][j]; // only count new process and not count same thing
            if(j + 1 < m) dp[i][j + 1] += dp[i][j];
        }
    }

    debug(dp[n - 1][m - 1]);

    return 0;
}