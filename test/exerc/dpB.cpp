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

    int n, k;
    std::cin >> n >> k;

    int weight[k], price[k];
    for(int i = 0; i < k; i++){
        std::cin >> weight[i] >> price[i];
    }
    
    std::vector<int> dp(n + 1, 0);
    std::vector<int> wmax(k);
    for(int i = 0; i < k; i++){
        for(int j = n; j >= 0; j--){ // to prevent dp[j - weight[i]] counted by previous j = 0 .. n (count from j last first for dp[j])
            if(j - weight[i] >= 0){
                int prev = dp[j - weight[i]] + price[i];
                if(prev > dp[j]){
                    dp[j] = prev;
                    wmax[i] = weight[i];
                }
                // dp[j] = std::max(dp[j], dp[j - weight[i]] + price[i]);
            }
        }
    }

    std::cout << dp[n] << std::endl;

    return 0;
}