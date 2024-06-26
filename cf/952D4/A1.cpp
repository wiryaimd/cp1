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
        std::string a, b;
        std::cin >> a >> b;

        char a0 = a[0];
        char b0 = b[0];
        a[0] = b0;
        b[0] = a0;

        std::cout << a << " " << b << std::endl;
    }

    return 0;
}