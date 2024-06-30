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

    int a[n];
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    int ps[n];
    std::partial_sum(a, a + n, ps); // easy way to make prefix sum
    for(int i = 0; i < n; i++){
        debug(ps[i]);
    }

    int px[n];
    std::partial_sum(a, a + n, px, std::multiplies<int>()); // multiply prefix sum (instead of summing)
    for(int i = 0; i < n; i++){
        debug(px[i]);
    }

    return 0;
}