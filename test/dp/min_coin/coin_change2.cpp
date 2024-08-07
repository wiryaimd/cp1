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

int main(){

    int x = 5;
    int coins[3] = {1, 3, 4};

    int dp[x + 1];
    int first[x + 1];

    dp[0] = 0;
    for(int i = 1; i <= x; i++){
        dp[i] = INF;
        for(int c : coins){
            if(i - c >= 0 && dp[i - c] + 1 < dp[i]){
                dp[i] = dp[i - c] + 1;
                first[i] = c;
            }
        }
    }

    debug(dp[x]);

    // construct which coin used for that optimal solution
    int n = x;
    while(n > 0){
        debug(first[n]);
        n -= first[n];
    }

    // count how much possible solution
    std::vector<int> count(x + 1, 0);
    count[0] = 1;
    for(int i = 1; i <= x; i++){
        for(int c : coins){
            if(i - c >= 0){
                count[i] += count[i - c];
            }
        }
    }

    for(int i = 0; i <= x; i++){
        debug(count[i]);
    }
    br;
    debug(count[x]); // result


    return 0;
}