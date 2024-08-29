#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<cstring>
#include<numeric>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

using ll = long long;

int main(){

    int t;
    std::cin >> t;
    while(t--){
        int n;
        std::cin >> n;

        int a[n];
        for(int i = 0; i < n; i++){
            std::cin >> a[i];
        }

        std::string s;
        std::cin >> s;

        ll ps[n + 1];
        ps[0] = 0;
        for(int i = 1; i <= n; i++){
            ps[i] = (ll)ps[i - 1] + a[i - 1];
        }

        ll total = 0;

        int l = 0, r = n - 1;
        std::vector<std::pair<int, int>> p;
        while(l < r){
            if(s[l] == 'L' && s[r] == 'R'){
                total += ps[r + 1] - ps[l];
                // p.push_back({l, r + 1});
                l++;
                r--;
                continue;
            }

            if(s[l] != 'L') l++;
            if(s[r] != 'R') r--;
        }

        // for(int i = 0; i < p.size(); i++){
            // debug(p[i].first);
            // debug(p[i].second); br;
        //     total += ps[p[i].second] - ps[p[i].first];
        // }

        std::cout << total << std::endl;
    }

    return 0;
}