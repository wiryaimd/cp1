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

int dp[55][55];

/*
    given string s, you can remove 0 or more char so that you can get most longest palindrome

    sol
        using LCS which is this case similar to with finding its s1, and s2 subsequence
        and to check palindrome use lcs(s1 == reverse(s1)) which will check most longest subsequence that s1 equal with its reverse (palindrome)
*/

int f(int pos1, int pos2, std::string s1, std::string s2){
    if(pos1 == 0|| pos2 == 0) return 0;
    if(dp[pos1][pos2] != -1) return dp[pos1][pos2];

    if(s1[pos1 - 1] == s2[pos2 - 1]){
        // int curr = f(pos1 - 1, pos2 - 1, s1, s2) + 1; 
        // dp[pos1][pos2] = curr; // you can directly add f() to dp[][] instead of storing to int curr first
        dp[pos1][pos2] = f(pos1 - 1, pos2 - 1, s1, s2) + 1; 
        return dp[pos1][pos2];
    }

    // int maxx = std::max(f(pos1 - 1, pos2, s1, s2), f(pos1, pos2 - 1, s1, s2)); // same
    dp[pos1][pos2] = std::max(f(pos1 - 1, pos2, s1, s2), f(pos1, pos2 - 1, s1, s2));
    return dp[pos1][pos2];
}

int main(){

    int n;
    std::cin >> n;
    while(n--){
        std::string s;
        std::cin >> s;

        memset(dp, -1, sizeof(dp));

        std::string tmp = s;
        std::reverse(tmp.begin(), tmp.end());

        int res = f(s.length(), tmp.length(), s, tmp);
        std::cout << res << std::endl;
    }

    return 0;
}