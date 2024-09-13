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
        int n;
        std::string s;
        std::cin >> n >> s;

        int cnt = 0;
        for(int i = 0; i < n - 2;){
            if(s.substr(i, 5) == "mapie" && i + 5 < n){
                cnt++;
                i += 5;
                continue;
            }else if(s.substr(i, 3) == "map" || s.substr(i, 3) == "pie"){
                cnt++;
                i += 3;
                continue;
            }
            i++;
        }

        std::cout << cnt << std::endl;
    }

    return 0;
}