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
    std::cin >> n >> w;

    int val[n], weight[w];
    for(int i = 0; i < n; i++){
        std::cin >> weight[i] >> val[i];
    }

    std::vector<ll> dp(w + 1, 0);
    for(int i = 0; i < n; i++){
        for(int j = w; j >= weight[i]; j--){ // flying table approach
            // if(j - weight[i] >= 0){
                dp[j] = std::max(dp[j], val[i] + dp[j - weight[i]]);
            // }
        }
    }

    for(int i = 0; i <= w; i++){
        debug(dp[i]);
    }

    std::cout << dp[w] << std::endl;

    return 0;
}