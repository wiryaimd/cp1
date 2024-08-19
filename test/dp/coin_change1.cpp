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

int INF = 1e9 + 7;
int coins[3] = {1, 3, 4};
// int coins[3] = {6, 7, 8};

const int target = 88;
int dp[target + 1];
bool ready[target] = {false};

// coin change problem
// without memoization (non dp)
int f(int x){
    if(x < 0) return INF; // use INF instead of INT32_MAX, because we need +1 in f(x-c) + 1 that may lead integer size
    if(x == 0) return 0;

    int minn = INF;
    for(int c : coins){
        minn = std::min(minn, f(x - c) + 1);
    }
    return minn;
}

// with memoization (dp approach)
int f2(int x){
    // base case, when target already equal or greater than total added coin
    if(x < 0) return INF;
    if(x == 0) return 0;

    if(ready[x]) return dp[x]; // when already calculated then return the value

    debug(x);
    int minn = INF;
    // this recursive will make tree-like process when visualized
    for(int c : coins){
        // x - c will calculate all possibilities in this avaialable coins[] until equal to 0 or less than 0
        // +1 to increase how much coin needed for target x 
        minn = std::min(minn, f2(x - c) + 1);
        debug(x);
        debug(minn);
    }

    dp[x] = minn; // stored in dp[x] to get most min coin when need to get x
    ready[x] = true; // store state which x value have been calculated

    return minn;
}

int main(){

    // int res = f2(target);
    // debug(res);

    dp[0] = 0;
    for(int i = 1; i <= target; i++){ // count all possible target from i to target
        dp[i] = INF; // default INF, when all contained coin value more than target, then no solution and the output will be INF
        for(int c : coins){
            if(i - c >= 0){
                dp[i] = std::min(dp[i], dp[i - c] + 1); // if dp[i - c] + 1 can be smallest, then replace old dp[i]
            }
        }
    }

    for(int i = 0; i <= target; i++){
        debug(dp[i]);
    }

    // eg. when ouput INF when int coins[3] = {6, 7, 8}; const int target = 5;
    debug(dp[target]);

    


    return 0;
}