#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        std::cin >> n;
        long long neg = 0, pl = 0;
        int ai[n];
        for(int j = 0; j < n; j++){
            std::cin >> ai[j];
            if(ai[j] < 0){
                neg += std::abs(ai[j]);
            }else{
                pl += ai[j];
            }
        }

        long long cnt = 0;
        bool pass = false;
        for(int j = 0; j < n; j++){
            // debug(pl);
            // debug(neg);

            if((pl >= neg || neg == 0)){
                if(ai[j] > 0){
                    pass = true;
                }
                // debug(ai[j]);br;
                if(pass){
                    cnt = std::abs(cnt);
                    cnt += ai[j];
                    continue;
                }
            }
            
            cnt += ai[j];
            neg -= std::abs(ai[j]);
            
            // debug(cnt);
        }

        // long long maxx = std::max(std::abs(neg), pl);
        std::cout << std::abs(cnt) << std::endl;
    }


    return 0;
}