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

    int t;
    std::cin >> t;
    while(t--){
        int n, m, k;
        std::cin >> n >> m >> k;

        std::string s;
        std::cin >> s;

        int swim = 0;
        int jump = 0;
        bool pass = true;
        for(int i = 0; i < n; i++){
            if(s[i] == 'L'){
                jump = 0;
                continue;
            }

            jump++;
            if(jump >= m){
                swim++;
                if(s[i] == 'C' || swim > k){
                    pass = false;
                    break;
                }
            }
        }

        std::cout << (pass ? "YES" : "NO") << std::endl;
    }

    return 0;
}