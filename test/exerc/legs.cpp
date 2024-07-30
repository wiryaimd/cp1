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

    int t;
    std::cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        std::cin >> n;
        int rem = n % 4;
        n /= 4;
        std::cout << n + (rem / 2) << std::endl;
    }

    return 0;
}