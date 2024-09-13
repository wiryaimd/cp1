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

std::map<std::tuple<int, int, int, bool>, int> memo;
int f(std::vector<int>& a, int i, int k, int z, bool left){
    if(k == 0){
        return 0;
    }

    auto t = std::make_tuple(i, k, z, left);
    if(memo[t]) return memo[t];

    int res;
    if(z > 0){
        if(left){
            res = f(a, i + 1, k - 1, z, false) + a[i];
        }else{
            res = std::max(f(a, i - 1, k - 1, z - 1, true), f(a, i + 1, k - 1, z, false)) + a[i];
        }
    }else{
        res = f(a, i + 1, k - 1, z, false) + a[i];
    }

    memo[t] = res;
    return res;
}

int main(){

    int t;
    std::cin >> t;
    while(t--){
        int n, k, z;
        std::cin >> n >> k >> z;

        std::vector<int> a(n);
        for(int i = 0; i < n; i++){
            std::cin >> a[i];
        }

        ll cnt = a[0];
        cnt += f(a, 1, k, z, false);

        std::cout << cnt << std::endl;
        memo.clear();
    }

    return 0;
}