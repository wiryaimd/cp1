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
    std::cin >> n;

    std::vector<int> dp(n + 1, 0);
    for(int i = 1; i <= n; i++){ // my fff dp self sovl
        if(i / 2 >= 0 && i / 3 >= 0 && i / 4 >= 0){ // no need this condition because i / n not make negative and always 0.XXXX
            dp[i] = std::max(i, dp[i / 2] + dp[i / 3] + dp[i / 4]);
        }else{
            dp[i] = i;
        }
    }

    std::cout << dp[n] << std::endl;

    return 0;
}