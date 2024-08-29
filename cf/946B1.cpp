/*
 * Prob: #
 * File Created: Thursday, 29th August 2024 3:10:18 pm, 11mins code
 * Author: Wiryaimd
 */


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

    int t;
    std::cin >> t;
    while(t--){
        int n;
        std::string s;
        std::cin >> n >> s;

        bool alp[26] = {false};
        for(int i = 0; i < n; i++){
            alp[s[i] - 'a'] = true;
        }

        std::string sorted = "";
        for(int i = 0; i < 26; i++){
            if(alp[i]) sorted += 'a' + i;
        }

        int len = sorted.length();
        std::map<char, char> pair;
        for(int i = 0; i < len / 2; i++){
            pair[sorted[i]] = sorted[len - i - 1];
            pair[sorted[len - i - 1]] = sorted[i];
        }

        std::string res;
        for(int i = 0; i < n; i++){
            if(pair[s[i]] == '\0'){
                res += s[i];
                continue;
            }
            res += pair[s[i]];
        }

        std::cout << res << std::endl;
    }

    return 0;
}