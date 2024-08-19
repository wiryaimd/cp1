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

    // longest increasing subsequence (LIS)

    int n;
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    int maxx = 0;
    std::vector<int> dp(n, 1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(a[j] < a[i]){
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }

        maxx = std::max(maxx, dp[i]);
    }
    std::cout << maxx << std::endl;
    
    return 0;
}