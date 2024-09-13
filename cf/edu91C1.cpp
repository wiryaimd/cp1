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
        int n, x;
        std::cin >> n >> x;

        int a[n];
        for(int i = 0; i < n; i++){
            std::cin >> a[i];
        }

        std::sort(a, a + n, std::greater<int>());
        int cnt = 0;
        int pos = 1;
        int curr = a[0];
        for(int i = 1; i < n; i++){
            if(curr * pos >= x){
                cnt++;
                curr = a[i];
                pos = 1;
                continue;
            }

            curr = std::min(curr, a[i]);
            pos++;
        }

        if(curr * pos >= x) cnt++;

        std::cout << cnt << std::endl;
    }

    return 0;
}