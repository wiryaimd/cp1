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

        int n = s.length();
        int num[10] = {0};
        for(int i = 0; i < n; i++){
            num[s[i] - '0']++;
        }

        int maxx = 0;
        for(int i = 0; i < 10; i++){
            maxx = std::max(maxx, num[i]);
        }
        int res = n - maxx;

        // valid cyclic shift when input "0000" (all same), or "454545" (alternating and its even)

        // some input may be have hidden alternating character like 251232512325 for alternating "25"
        // so, just generate all possible alternating character then find its most max alternating
        // if all number is same, it already handled by num[s[]]++
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){ // for possible alternating i (first), and j (second)
                if(i == j) continue;

                int cnt = 0;
                bool f = true;
                for(char c : s){
                    if(f && i == c - '0'){
                        cnt++;
                        f = !f;
                    }else if(!f && j == c - '0'){
                        cnt++;
                        f = !f;
                    }
                }

                if(cnt % 2 == 1) cnt--;

                res = std::min(res, n - cnt);
            }
        }
 
        std::cout << res << std::endl;
    }
 
    return 0;
}