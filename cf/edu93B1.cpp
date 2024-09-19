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

        std::vector<int> v;
        bool last = false;
        int cnt = 0;
        for(int i = 0; i < s.length(); i++){
            if(last && s[i] - '0' == 0){
                v.push_back(cnt);
                last = false;
                cnt = 0;
                continue;
            }

            if(s[i] - '0'){
                last = true;
                cnt++;
            }
        }

        v.push_back(cnt);

        std::sort(v.begin(), v.end(), std::greater<int>());
        int res = 0;
        bool skip = true;
        for(int i = 0; i < v.size(); i++){
            skip = !skip;
            if(skip) {
                continue;
            }

            res += v[i];
        }

        std::cout << res << std::endl;
    }

    return 0;
}