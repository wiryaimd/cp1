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

    int t;
    std::cin >> t;
    for(int i = 0; i < t; i++){
        int x[3];
        std::cin >> x[0] >> x[1] >> x[2];
        
        std::sort(x, x + 3);
        int total = std::abs(x[1] - x[0]) + (x[2] - x[1]);
        std::cout << total << std::endl;
    }

    return 0;
}