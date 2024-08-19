#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<cstring>
#include<numeric>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

using ll = long long;

int main(){

    int n;
    ll l;
    std::cin >> n >> l;

    std::vector<ll> v;
    v.push_back(l);
    for(int i = 0; i < n; i++){
        int b;
        std::cin >> b;

        ll curr = v[b - 1] / 2;
        v.insert(v.begin() + b, curr);
        v[b - 1] = curr;
    }

    for(int i = 0; i < v.size(); i++){
        std::cout << v[i] << std::endl;
    }


    return 0;
}