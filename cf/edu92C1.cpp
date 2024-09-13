#ifndef ONLINE_JUDGE
#include "../debug.hpp"
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
 
int main(){
 
    int t;
    std::cin >> t;
    while(t--){
        std::string s;
        std::cin >> s;
 
        std::map<std::string, int> mp;
        for(int i = 0; i < s.length() - 2; i++){
            std::string tmp = s.substr(i, 2);
            debug(tmp);

            mp[tmp]++;
            if(s[i + 2] == s[i + 1] && s[i] == s[i + 1]){
                i += 1;
            }
        }
 
        int num[10] = {0};
        for(int i = 0; i < s.length(); i++){
            num[s[i] - '0']++;
        }
 
        int maxx = 0;
        for(int i = 0; i < 10; i++){
            maxx = std::max(maxx, num[i]);
        }
 
        int maxxu = 0;
        for(std::pair<std::string, int> u : mp){
            maxxu = std::max(maxxu, u.second * 2);
        }
        debug(maxxu);
        debug(maxx);
        int res = s.length() - std::max(maxxu, maxx);
 
        std::cout << res << std::endl;
    }
 
    return 0;
}