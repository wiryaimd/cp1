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

    // find numbers of subarray that the elements filled with zero

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    long long cnt = 0;
    int z = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 0){
            z++;
        }else{
            if(z > 0){
                cnt += z * (z + 1) / 2;
                z = 0;
            }
        }
    }

    if(z > 0) cnt += z * (z + 1) / 2;

    std::cout << cnt << std::endl;

    return 0;
}