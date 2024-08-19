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

const int MOD = 1e9 + 7;

int f(int cnt, int n){
    if(cnt > n) return 0;
    if(cnt == n) return 1;
    debug(cnt);

    int c = 0;
    for(int i = 1; i <= 6; i++){
        c += f(cnt + i, n);
    }
    return c;
}

long long fdp(std::vector<bool>& ready, std::vector<long long>& dp, int cnt, int n){
    if(cnt > n) return 0;
    if(cnt == n) return 1;

    // debug(cnt);

    if(ready[cnt]) return dp[cnt];

    long long c = 0;
    for(int i = 1; i <= 6; i++){
        c += fdp(ready, dp, cnt + i, n);
        // or use
        // c = (c + fdp(ready, dp, cnt + i, n)) % MOD;
    }

    c = c % MOD;
    
    // debug(c);
    ready[cnt] = true;
    dp[cnt] = c;

    return c;
}

int main(){

    int n;
    std::cin >> n;

    std::vector<bool> ready(n + 1, false);
    std::vector<long long> dp(n + 1);
    dp[0] = 0;

    long long res = fdp(ready, dp, 0, n);
    std::cout << res << std::endl;
    // debug(res);

    return 0;
}