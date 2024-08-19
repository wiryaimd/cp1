#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<numeric>
#include<cstring>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

using ll = long long;

const int SZ = 200;

int val[SZ];
int weight[SZ];
int n, w;

// bool visited[SZ][SZ] = {false};
ll memo[SZ][SZ];

ll f(int i, int capt){
    if(i == n) return 0;
    if(capt + weight[i] > w) return 0;
    if(memo[i][capt] != -1){
        debug(memo[i][capt]);
        return memo[i][capt];
    }

    // debug(weight[i]);

    ll one = f(i + 1, capt + weight[i]) + val[i];
    ll zero = f(i + 1, capt);

    memo[i][capt] = std::max(one, zero);
    // dp[i] = std::max(one, zero);
    // visited[i] = true;

    // debug(one);
    // debug(zero);

    return std::max(one, zero);
}

ll f2(int n, int w){
    if(n == 0 || w == 0) return 0;
    if(weight[n - 1] > w) return f2(n - 1, w);

    return std::max(f2(n - 1, w), f2(n - 1, w - weight[n - 1]) + val[n - 1]);
}

int main(){

    std::cin >> n >> w;

    std::memset(memo, -1, sizeof(memo));

    for(int i = 0; i < n; i++){
        std::cin >> weight[i] >> val[i];
    }

    ll res = f(0, 0); // same result
    // ll res = f2(n, w);
    std::cout << res << std::endl;

    return 0;
}