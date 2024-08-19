#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

using ll = long long;
using ull = unsigned long long;

ll lcm(ll a, ll b){
    return std::abs(a * b) / std::__gcd(a, b);
}

int main(){

    /*
        given a, b, c, d find the total number from value A to B that cannot divided by C or D

        cons: a <= b <= 1e18

        sol:
            notice that A and B dont need to get divided by any multiplier of C or D,
            which is Cx1, Cx2, Cx3, and so on (same for D)
            then we can get the total non divisible of A and B by 
                C_total = (B/c - A/c)
                D_total = (B/d - A/d)
                total = C_total + D_total
            
            but theres some intersection between C and D
                eg. 5 and 4, the intersection is 20 (LCM)
                then, we can use LCM and count how much intersection from A to B
                using rem_lcm = B/lcm - A/lcm
         
            final res = total - rem_lcm

        nb. when dividing A eg. 6/2 = 3 we count 6 (2, 4, 6) as exception,
        but we want 6 to included in A to B (inclusive), then we need to -= 1 when a % c or d is even to make result valid
    */

    ull a, b;
    ll c, d;
    std::cin >> a >> b >> c >> d;

    ll mut = lcm(c, d);
    ll sz = b + 1 - a;
    ll div = ((b / c) - ((a / c) - (a % c == 0))) + ((b / d) - ((a / d)));
    ll res = sz - (div - ((b / mut) - (a / mut)));

    std::cout << res << std::endl;
    

    return 0;
}