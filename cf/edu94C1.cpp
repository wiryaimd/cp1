
#ifndef ONLINE_JUDGE
#include "../debug.hpp"
#else
#define debug(...)
#define debugArr(...)
#endif

#define br std::cerr << std::endl;

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

int main(){ // also correct ans

    int t;
    std::cin >> t;
    while(t--){
        int x;
        std::string s;
        std::cin >> s >> x;

        std::string w(s.length(), '1');
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '0'){
                if(i - x >= 0) w[i - x] = '0';
                if(i + x < s.length()) w[i + x] = '0';
            }
        }

        bool valid = true;
        for(int i = 0; i < s.length(); i++){
            bool l = false, r = false;
            if(s[i] == '1'){
                if(i - x >= 0){
                    l = w[i - x] - '0';
                }

                if(i + x < s.length()){
                    r = w[i + x] - '0';
                }

                if(!(l || r)){
                    valid = false;
                    break;
                }
            }
        }

        std::cout << (valid ? w : "-1") << std::endl;
    }

    return 0;
}