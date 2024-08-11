/*
 * Prob: Go Home
 * File Created: Sunday, 23rd June 2024 10:08:50 am
 * Author: Wiryaimd
 */

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

    /*
        given x
        find its AP(n) >= x where AP(n) (or n) must atleast greater or equal than x

        sol
            x = n * (n + 1) / 2
            known value is x, and want to find its n, then use linear equation and quadratic formula

            it'l be
            n = (-1 + sqrt(1 + 8x)) / 2

        other sol:
            see _2.cpp
    */

    ll x;
    std::cin >> x;

    ll n = std::ceil((double)(-1.0 + sqrt(1 + 8 * x)) / 2);
    // ll rem = x - (n * (n + 1) / 2);

    std::cout << n << std::endl;

    return 0;
}