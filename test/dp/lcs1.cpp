#ifndef ONLINE_JUDGE
#include "../../debug.hpp"
#else
#define debug(...)
#define debugArr(...)
#endif

#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<cstring>
#include<numeric>

using ll = long long;
const ll INF = 1e18 + 7;

int f(std::string a, std::string b, int i, int j){
    if(i == a.length()) return 0;
    if(j == b.length()) return 0;

    if(a[i] == b[j]) {
        return f(a, b, i + 1, j + 1) + 1;
    }else{
        return std::max(f(a, b, i + 1, j), f(a, b, i, j + 1));
    }
}

int main(){

    std::string s1, s2;
    std::cin >> s1 >> s2;

    // debug(f(s1, s2, 0, 0));

    std::vector<std::vector<int>> dp(s1.length() + 1, std::vector<int>(s2.length() + 1, 0));
    for(int i = 1; i <= s1.length(); i++){
        for(int j = 1; j <= s2.length(); j++){
            if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else{
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    debug(dp);

    std::cout << dp[s1.length()][s2.length()] << std::endl;

    return 0;
}