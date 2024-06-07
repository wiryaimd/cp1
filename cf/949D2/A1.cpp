#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

int main(){

    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++){
        int l, r;
        std::cin >> l >> r;
        int res = (int)log2(r);
        std::cout << res << std::endl;
    }

    return 0;
}