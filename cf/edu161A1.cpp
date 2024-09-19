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
        std::string a, b, c;
        std::cin >> n >> a >> b >> c;

        bool ans = false;
        for(int i = 0; i < n; i++){
            if(c[i] != a[i] && c[i] != b[i]){
                ans = true;
                break;
            }
        }

        std::cout << (ans ? "YES" : "NO") << std::endl;
    }

    return 0;
}