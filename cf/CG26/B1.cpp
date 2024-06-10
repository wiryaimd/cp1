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

    int t;
    std::cin >> t;
    for(int i = 0; i < t; i++){
        ll x;
        std::cin >> x;
        std::string s = std::to_string(x);
        int len = s.length();
        if(s[len - 1] == '9'){
            std::cout << "NO" << std::endl;
            continue;
        }

        bool zero = false;
        for(int j = 1; j < len - 1; j++){
            if(s[j] == '0'){
                zero = true;
                break;
            }
        }
        if(zero) {
            std::cout << "NO" << std::endl;
            continue;
        }

        // debug(len);
        std::string a(len - 1, '5');
        std::string b(len - 1, '9');
        ll ax = std::stoull(a) * 2;
        ll bx = std::stoull(b) * 2;
        // debug(a);
        // debug(b);
        // debug(ax);
        // debug(bx);
        if(x >= ax && x <= bx){
            std::cout << "YES" << std::endl;
        }else{
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}