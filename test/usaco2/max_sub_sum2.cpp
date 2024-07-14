#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<numeric>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

using ll = long long;

int main(){

    int n;
    std::cin >> n;
    
    ll a[n];
    std::vector<ll> ps(n + 1, 0);
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
        ps[i + 1] = ps[i] + a[i];
    }

    ll maxx = ps[1];
    ll minn = 0;
    for(int i = 0; i < n; i++){
        maxx = std::max(maxx, ps[i + 1] - minn);
        minn = std::min(minn, ps[i + 1]);
    }

    // debug(minn);
    // debug(maxx);
    std::cout << maxx << std::endl;

    return 0;
}