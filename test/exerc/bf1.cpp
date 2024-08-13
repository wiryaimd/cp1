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

    int t;
    std::cin >> t;
    while(t--){
        int n;
        std::cin >> n;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            int a;
            std::cin >> a;
            cnt += a % 3;
        }

        if(cnt % 2 == 0 || cnt % 3 == 0){
            std::cout << "YES" << std::endl;
        }else{
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}