#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

int main(){

    int t;
    std::cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        std::cin >> n;
        long long neg = 0, pl = 0;
        long long cnt1 = 0;
        for(int j = 0; j < n; j++){
            int a;
            std::cin >> a;
            if(a < 0){
                neg += std::abs(a);
            }else{
                pl += a;
            }
        }

        long long maxx = std::max(std::abs(neg), pl);
        std::cout << maxx << std::endl;
    }

    return 0;
}