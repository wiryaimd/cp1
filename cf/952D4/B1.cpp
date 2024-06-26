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
        int n;
        std::cin >> n;

        if(n == 3) {
            std::cout << 3 << std::endl;
            continue;
        }

        std::cout << 2 << std::endl;
    }

    return 0;
}