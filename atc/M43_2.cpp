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

    // ll x;
    // std::cin >> x;

    // ll n = 1;
    // ll cnt = 0;
    // while(true){
    //     cnt += n;
    //     debug(cnt);
    //     if(cnt + n + 1 >= x){
    //         break;
    //     }
    //     n++;
    // }

    // // ll sn = n * (n + 1) / 2;
    // ll res;
    // if(x - cnt < n + 1){
    //     res = n + (x - cnt);
    // }else{
    //     n++;
    //     res = n + (x - cnt);
    // }

    // std::cout << n << std::endl;

    // just use iteration to find its Sn when n >= x

    ll x;
    std::cin >> x;
    ll n = 0;
    ll ans = 0;
    while (n < x) n += ++ans;
    std::cout << ans << std::endl;

    return 0;
}