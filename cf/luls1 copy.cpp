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

        // if(f > p) std::swap(p, f);
        if(pl.second > pr.second) std::swap(pl, pr);
        if(f % pl.second == 0 && pl.second * pl.first >= f) std::swap(p, f);
        ll minn;
        ll cnt2 = 0;
        if(pl.second == pr.second){
            minn = 0;
        }else{
            if(p / pl.second > pl.first){
                int more = (p - (pl.first * pl.second)) / pr.second;
                // debug(more);
                cnt2 += more;
                ll minn2 = std::min(((p - (pl.first * pl.second)) - (more * pr.second)) / (pr.second - pl.second), std::min(pr.first, pl.first));
                // debug(minn2);
                // minn2 = std::min(minn, pl.first);
                cnt2 += pl.first;
                pl.first -= pl.first - minn2;
                // debug(pl.first);
                pr.first -= more + minn2;
                // debug(pr.first);

                ll minnr2 = std::min(f / pl.second, pl.first);
                // debug(minnr2);
                cnt2 += minnr2;
                f -= minnr2 * pl.second;
                cnt2 += std::min(f / pr.second, pr.first);
                // debug(cnt2);
                std::cout << cnt2 << std::endl;
                continue;
            }else{
                minn = std::min((p % pl.second) / (pr.second - pl.second), pr.first);
            }
        }

        ll cnt = p / pl.second;
        pl.first -= cnt - minn;
        pr.first -= minn;

        ll minnr = std::min(f / pl.second, pl.first);
        cnt += minnr;
        f -= minnr * pl.second;
        cnt += std::min(f / pr.second, pr.first);
        std::cout << cnt << std::endl;
    }

    return 0;
}