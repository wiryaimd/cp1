#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

using ll = unsigned long long;

int main(){

    ll k, a, b;
    std::cin >> k >> a >> b;

    if(a >= b){
        std::cout << k << std::endl;
        return 0;
    }

    ll x = (k + 1) / a;
    debug(x);
    ll y = x * b;
    debug(y);
    ll z = (k + 1) % a;
    debug(z);
    ll r;
    if(z < x * 2){
        int tmp = ((x - z) * b);
        debug(tmp);
        r = y - tmp + z;
        debug("i");
    }else{
        r = y + (z - x);
        debug("e");
    }
    debug(r);

    std::cout << r << std::endl;

    return 0;
}