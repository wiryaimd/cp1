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

        int a[n];
        for(int i = 0; i < n; i++){
            a[i] = s[i] - '0';
        }

        std::vector<int> ps(n + 1, 0);
        for(int i = 1; i <= n; i++){    
            ps[i] = ps[i - 1] + a[i - 1];
        }

        // ps[r] - ps[l - 1] = r - l + 1
        // ps[r] - r = ps[l - 1] - (l - 1)
        std::map<int, int> freq;
        freq[0] = 1;
        ll cnt = 0;
        ll psx = 0;
        for(int i = 0; i < n; i++){
            psx += a[i];
        
            // Calculate prefix_sum - index
            int prefix_diff = psx - (i + 1);
            
            // Check how many times this prefix_diff has occurred before
            if (freq.find(prefix_diff) != freq.end()) {
                cnt += freq[prefix_diff];
            }
            
            // Update the count of this prefix_diff in the hashmap
            freq[prefix_diff]++;
        }

        for(std::pair<int, int> u : freq){
            debug(u.first);
            debug(u.second);
        }

        std::cout << cnt << std::endl;
        debug(ps);
    }

    return 0;
}