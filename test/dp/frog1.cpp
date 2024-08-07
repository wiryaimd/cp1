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

/*
    Frog problem
*/

int n;
std::vector<int> h;

const int INF = 1e9 + 7;
int cnt = 0;

// naive approach without dp
int f(int jump){
    if(jump + 1 == n){
        return 0;
    }

    if(jump + 2 == n){
        return std::abs(h[jump] - h[jump + 1]);
    }

    int one = std::abs(h[jump] - h[jump + 1]) + f(jump + 1);
    int two = std::abs(h[jump] - h[jump + 2]) + f(jump + 2);

    // debug(h[jump]);
    // // debug(cnt);
    // debug(one);
    // debug(two);
    // br;

    return std::min(one, two);
}

// using memoization (dp approach)
int fdp(std::vector<bool>& ready, std::vector<int>& dp, int jump){
    if(jump + 1 == n) return 0;
    if(jump + 2 == n) return std::abs(h[jump] - h[jump + 1]);
    if(ready[jump]) return dp[jump]; // use the optimized data when it have been calculated

    int minn = std::min(
        std::abs(h[jump] - h[jump + 1]) + fdp(ready, dp, jump + 1),
        std::abs(h[jump] - h[jump + 2]) + fdp(ready, dp, jump + 2)
    );

    ready[jump] = true;
    dp[jump] = minn; // only store its most optimized result (which is most smallest)

    return minn;
}

int main(){

    std::cin >> n;
    h.resize(n);

    std::vector<bool> ready(n, false);
    std::vector<int> dp(n);

    for(int i = 0; i < n; i++){
        std::cin >> h[i];
        // debug(h[i]);
    }

    int res = fdp(ready, dp, 0);
    std::cout << res << std::endl;

    // debug(res);
    // debug(cnt);    

    return 0;
}