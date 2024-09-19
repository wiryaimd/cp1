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
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        for(int i = 0; i < n; i++){
            std::cin >> a[i];
        }

        std::vector<int> psl(n), psr(n);
        psl[0] = 0;
        psl[1] = 1;
        for(int i = 1; i < n - 1; i++){
            int l = a[i] - a[i - 1];
            int r = a[i + 1] - a[i];
            if(r > l){
                psl[i + 1] = psl[i] + r;
            }else{
                psl[i + 1] = psl[i] + 1;
            }
        }

        std::reverse(a.begin(), a.end());

        psr[0] = 0;
        psr[1] = 1;
        for(int i = 1; i < n - 1; i++){
            int l = a[i - 1] - a[i];
            int r = a[i] - a[i + 1];
            if(r > l){
                psr[i + 1] = psr[i] + r;
            }else{
                psr[i + 1] = psr[i] + 1;
            }
        }

        int q;
        std::cin >> q;
        for(int i = 0; i < q; i++){
            int x, y;
            std::cin >> x >> y;
            if(x < y){
                std::cout << psl[y - 1] - psl[x - 1] << std::endl;
            }else{
                std::cout << psr[n - y] - psr[n - x] << std::endl;
            }
        }
    }

    return 0;
}