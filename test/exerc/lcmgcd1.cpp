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

ll gcd(ll a, ll b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    return (a * b) / gcd(a, b);
}

int main(){

    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    ll m = lcm(b, d);
    ll a1 = a * (m / b);
    ll c1 = c * (m / d);
    ll res = gcd(a1 + c1, m);
    std::cout << (a1 + c1) / res << " " << (m / res) << std::endl;

    return 0;
}