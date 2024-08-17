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
    std::cin >> n;

    std::vector<int> x(n), y(n);
    for(int i = 0; i < n; i++){
        std::cin >> x[i];
    }

    for(int i = 0; i < n; i++){
        std::cin >> y[i];
    }

    std::sort(x.begin(), x.end());
    std::sort(y.begin(), y.end(), std::greater<int>());

    long long cnt = 0;
    for(int i = 0; i < n; i++){
        cnt += (long long) x[i] * y[i]; // need to notice that cast to long long because input up to 100k
    }

    std::cout << cnt << std::endl;

    return 0;
}