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
        given n and k
        you should make ai+ai+ai+..+n that the total is k

        find minimum possible maximum (make its maximum as small as possible) value of ai, that can be make

        sol:
            the value will between k/n and the most maximum will be ceil(k/n) when k > n.
            
            when k < n, we need to get its k multiplier so k is 'slightly' greater than n, using k * ceil(n/k)
                here ceil(n/k) to get most slightly of multiplier k value
    */

    int t;
    std::cin >> t;
    for(int i = 0; i < t; i++){
        int n, k;
        std::cin >> n >> k;
        int res;
        if(k < n){
            int up = k * std::ceil((double)n / k);
            res = std::ceil((double)up / n);
            // neet to know that ceil() still return double instead of int, then need to cast it to round up (also same as floor())
            // std::cout << (int)std::ceil((double)up / n) << std::endl;
        }else{
            // std::cout << (int)std::ceil((double)k / n) << std::endl;
            res = std::ceil((double)k / n);
        }
        std::cout << res << std::endl;
    }

    return 0;
}