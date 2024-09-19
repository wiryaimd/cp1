
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

int main(){

    int t;
    std::cin >> t;
    while(t--){
        int x;
        std::string s;
        std::cin >> s >> x;

        std::string w(s.length(), '1');
        for(int i = 0; i < s.length(); i++){
            if(s[i] - '0' == 0){
                if(i - x >= 0) w[i - x] = '0';
                if(i + x < s.length()) w[i + x] = '0';
            }
        }

        bool valid = true;
        for(int i = 0; i < s.length(); i++){
            if(s[i] - '0'){
                bool possb = false;
                if(i - x >= 0 && w[i - x] - '0') possb = true;
                if(i + x < s.length() && w[i + x] - '0') possb = true;

                if(!possb){
                    valid = false;
                    break;
                }
            }
        }

        std::cout << (valid ? w : "-1") << std::endl;
    }

    return 0;
}