/*
 * Prob: kupon berhadiah
 * File Created: Tuesday, 13th August 2024 12:35:36 pm
 * Author: Wiryaimd
 */

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

int main(){

    int n, x;
    std::cin >> n >> x;

    int minn = INT32_MAX;
    int res;
    for(int i = 0; i < n; i++){
        int a;
        std::cin >> a;
        int dif = std::abs(a - x);
        if(dif == minn){
            res = std::min(res, a);
        }else if(dif < minn){
            minn = dif;
            res = a;
        }
    }

    std::cout << res << std::endl;

    return 0;
}