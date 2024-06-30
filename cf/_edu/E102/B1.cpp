/*
 * Prob: string lcm
 * File Created: Wednesday, 26th June 2024 5:29:55 pm
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
        using lcm approach
    */

    int t;
    std::cin >> t;
    for(int i = 0; i < t; i++){
        std::string a, b;
        std::cin >> a >> b;
        
        int k = a.length() * b.length() / std::__gcd(a.length(), b.length());
        std::string as, bs;
        for(int j = 0; j < k / a.length(); j++){
            as.append(a);
        }
        for(int j = 0; j < k / b.length(); j++){
            bs.append(b);
        }

        if(as == bs){
            std::cout << as << std::endl;
        }else{
            std::cout << -1 << std::endl;
        }

    }

    return 0;
}