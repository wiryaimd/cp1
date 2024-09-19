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
        ll minn;
        if(pl.second == pr.second){
            minn = 0;
        }else{
            minn = std::min((p % pl.second) / (pr.second - pl.second), pr.first);
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