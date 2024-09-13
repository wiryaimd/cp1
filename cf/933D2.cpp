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

    // ((i % n) + n) % n) or
    // (i + n) % n
    debug(((-2 % 5) + 5)); // for negative only
    debug(((-1 % 12) + 12) % 12); // work for negative and positive


    int t;
    std::cin >> t;
    while(t--){
        int n, m, x;
        std::cin >> n >> m >> x;

        std::map<int, bool> mp;
        std::vector<int> num(n);
        std::iota(num.begin(), num.end(), 1);

        std::vector<int> curr;
        int r0;
        char c0;
        std::cin >> r0 >> c0;

        int l = x - r0;
        int r = x + r0;
        if(c0 == '?'){
            curr.push_back(num[(l % n + n) % n]);
            curr.push_back(num[(r % n + n) % n]);
        }

        if(c0 - '0'){
            curr.push_back(num[(l % n + n) % n]);
        }else{
            curr.push_back(num[(r % n + n) % n]);
        }

        for(int u : curr){
            // res.insert(u);
        }

        for(int i = 1; i < m; i++){
            int r;
            char c;
            std::cin >> r >> c;

            std::vector<int> tmp;
            for(int u : curr){
                if(mp[u]){
                    continue;
                }

                mp[u] = true;
                if(c == '?'){
                    tmp.push_back(num[(l % n + n) % n]);
                    tmp.push_back(num[(r % n + n) % n]);
                }

                if(c0 - '0'){
                    curr.push_back(num[(l % n + n) % n]);
                }else{
                    curr.push_back(num[(r % n + n) % n]);
                }
            }

            curr = tmp;
        }
    }

    return 0;
}