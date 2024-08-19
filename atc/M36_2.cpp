#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

int main(){

    /*
        given ai value with start point at x

        find maximum D value that each ai can jump by D

        eg. 1 7 11 where x = 3 the max D value is 2 because
            3, 1, 3, 5, 7, 9, 11 (each jump 2)
    */

    int n, x;
    std::cin >> n >> x;

    int res = 0;
    for(int i = 0; i < n; i++){
        int a;
        std::cin >> a;
        res = std::__gcd(res, abs(x - a)); // using gcd to find its most greatest divisible ()
        // debug(res);
    }

    std::cout << res << std::endl;
    

    return 0;
}