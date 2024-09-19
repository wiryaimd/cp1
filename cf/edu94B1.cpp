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
        int p, f;
        // total weapon, capt each
        std::pair<int, int> pl, pr;
        // int ltotal, rtotal, lw, rw;
        std::cin >> p >> f;
        std::cin >> pl.first >> pr.first;
        std::cin >> pl.second >> pr.second;
        // std::cin >> ltotal >> rtotal >> lw >> rw;

        // if(rc > lc) std::swap(lc, rc);
        // if(rtotal > ltotal) std::swap(ltotal, rtotal);

        // if(f > p) std::swap(p, f);
        if(pl.second > pr.second) std::swap(pl, pr);
        debug(pl, pr);
        int minn;
        int cnt = 0;
        if(pl.second == pr.second){
            minn = 0;
        }else{
            if(p / pl.second > pl.first){
                minn = (p - (pl.first * pl.second)) / pr.second;
                cnt += minn;
            }else{
                minn = std::min((p % pl.second) / (pr.second - pl.second), pr.first);
            }
        }

        debug(minn);
        cnt += std::min(p / pl.second, pl.first);
        debug(cnt);
        pl.first -= std::min(cnt - minn, 0);
        debug(pl.first);
        pr.first -= minn;

        int minnr = std::min(f / pl.second, pl.first);
        debug(minnr);
        cnt += minnr;
        // pr.first -= std::min(minnr, pr.first);
        f -= minnr * pl.second;
        cnt += std::min(f / pr.second, pr.first);
        // int rem = f - (pr.second * minnr);
        // cnt += rem / 
        debug(cnt);
    }

    return 0;
}