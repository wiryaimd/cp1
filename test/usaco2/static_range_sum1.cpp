#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

using ll = long long;

int main(){

    // straight forward prefix sum

    int n, q;
    std::cin >> n >> q;

    std::vector<ll> ps(n + 1, 0);
    for(int i = 1; i <= n; i++){
        std::cin >> ps[i];
        ps[i] = ps[i] + ps[i - 1]; // atau
        // ps[i] += ps[i - 1]; // new ps[i] plus ps sebelumnya (ps[i - 1])
    }

    // other ps sum 
    // int a[n];
    // for(int i = 0; i < n; i++){
    //     std::cin >> a[i];
    // }

    // ll ps[n + 1];
    // ps[0] = 0;
    // for(int i = 0; i < n; i++){
    //     ps[i + 1] = (ll) ps[i] + a[i];
    // }

    for(int i = 0; i < q; i++){
        int l, r;
        std::cin >> l >> r;
        ll sum = ps[r] - ps[l];
        std::cout << sum << std::endl;
    }

    return 0;
}