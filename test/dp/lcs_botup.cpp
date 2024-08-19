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

    /*
        lcs

        when char s1[i] equal with s2[j] then increment +1 from last dp[i - 1][j - 1].
        otherwise get max of dp[i - 1][j] and dp[i][j - 1]
    */

    std::string s1, s2;
    std::cin >> s1 >> s2;

    std::vector<std::vector<int>> dp(s1.length() + 1, std::vector<int>(s2.length() + 1, 0));
    for(int i = 1; i <= s1.length(); i++){
        for(int j = 1; j <= s2.length(); j++){
            if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else{
                dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    std::cout << dp[s1.length()][s2.length()];

    return 0;
}