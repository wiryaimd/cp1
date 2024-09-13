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

        std::string res;
        std::map<char, char> comp;
        std::map<char, int> alp;
        comp['S'] = 'R';
        comp['P'] = 'S';
        comp['R'] = 'P';

        for(int i = 0; i < s.length(); i++){
            alp[s[i]]++;
        }

        char c;
        int maxx = 0;
        for(std::pair<char, int> p : alp){
            if(p.second > maxx){
                maxx = p.second;
                c = p.first;
            }
        }

        std::string ans(s.length(), comp[c]);
        std::cout << ans << std::endl;
    }

    return 0;
}