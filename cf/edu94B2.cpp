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
        ll p, f;
        std::pair<ll, ll> pl, pr;
        std::cin >> p >> f;
        std::cin >> pl.first >> pr.first;
        std::cin >> pl.second >> pr.second;

        if(f > p) std::swap(p, f);
        if(pl.second > pr.second) std::swap(pl, pr);
        ll minn;
        int more = 0;
        ll cnt = 0;
        if(pl.second == pr.second){
            minn = 0;
        }else{
            if(p / pl.second > pl.first){
                more = (p - (pl.first * pl.second)) / pr.second;
                cnt += more;
                minn = std::min((p - (p - (pl.first * pl.second)) + (more * pr.second)) / (pr.second - pl.second), pr.first);
                minn = std::min(minn, pl.first);
            }else{
                minn = std::min((p % pl.second) / (pr.second - pl.second), pr.first);
            }
        }

        cnt += std::min(p / pl.second, pl.first);
        debug(cnt);
        pl.first -= cnt - minn;
        debug(pl.first);
        pr.first -= minn + more;
        debug(pr.first);

        ll minnr = std::min(f / pl.second, pl.first);
        debug(minnr);
        cnt += minnr;
        f -= minnr * pl.second;
        cnt += std::min(f / pr.second, pr.first);
        std::cout << cnt << std::endl;
        debug(cnt);
    }

    return 0;
}