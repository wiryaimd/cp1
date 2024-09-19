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
    
    // freopen("162b2.in", "r", stdin);
    // freopen("162b2.out", "w", stdout);

    int t;
    std::cin >> t;
    while(t--){
        int n, k;
        std::cin >> n >> k;

        std::vector<std::pair<int, int>> p(n);
        int h[n];
        for(int i = 0; i < n; i++){
            std::cin >> h[i];
        }

        for(int i = 0; i < n; i++){
            int pos;
            std::cin >> pos;
            p[i] = {std::abs(pos), h[i]};
        }

        std::sort(p.begin(), p.end());
        int move = 0;
        bool posb = true;
        for(int i = 0; i < n; i++){
            if(p[i].second <= 0) continue;

            if(p[i].first - move <= 0){
                posb = false;
                break;
            }

            int curr = k;
            if(k >= p[i].second){
                move++;

                curr -= p[i].second;
                int j = i + 1;
                bool more = false;
                while(curr != 0 && j < n){
                    more = true;
                    p[j].second -= curr;
                    curr = std::min(curr - p[j].second, 0);
                    j++;
                }

                if(more) i = j - 2;
            }else{
                move += p[i].second / k;
                if(p[i].second % k != 0){
                    move++;
                    if(i + 1 < n) {
                        p[i + 1].second -= k - (p[i].second % k);
                    }
                }
            }
        }

        if(p[n - 1].first - move < 0) posb = false;

        std::cout << (posb ? "YES" : "NO") << std::endl;
    }

    return 0;
}