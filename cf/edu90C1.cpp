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

        int len = s.length();
        ll res = len;
        int curr = 0;
        for(int i = 0; i < len; i++){
            if(s[i] == '+'){
                curr++;
            }else{
                curr--;
            }

            if(curr < 0){
                res += (ll)i + 1;
                curr = 0;
            }
        }

        std::cout << res << std::endl;
    }

    return 0;
}