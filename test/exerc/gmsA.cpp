#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<cstring>
#include<numeric>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

using ll = long long;

int main(){

    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    //nb. care the case where b == 0, or c == 0 after previous calc

    int cnt = 0;
    cnt += std::ceil(a / 3.0);
    if(b == 0){
        if(c != 0){
            c -= std::min((3 - (a % 3)) % 3, c);
        }else{
            d -= std::min((3 - (a % 3)) % 3, d);
        }
    }

    cnt += std::ceil(b / 3.0);
    if(c == 0){
        d -= std::min((3 - (b % 3)) % 3, d);
    }else{
        c -= std::min((3 - (b % 3)) % 3, c);
    }

    cnt += std::ceil(c / 3.0);
    cnt += std::ceil(d / 3.0);

    std::cout << cnt << std::endl;

    return 0;
}