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

    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    int n;
    std::cin >> n;

    std::vector<ll> v(n + 1, 0);
    for(int i = 1; i <= n; i++){
        std::cin >> v[i];
        v[i] = v[i] + v[i - 1];
    }

    int maxx = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            ll sum = v[j] - v[i];
            if(sum % 7 == 0){
                maxx = std::max(maxx, j - i);
            }
        }
    }
    std::cout << maxx << std::endl;

    return 0;
}