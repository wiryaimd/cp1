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
        int ai[n];
        for(int j = 0; j < n; j++){
            std::cin >> ai[j];
        }

        // debug(ai[n -1]);
        // debug(ai[1]);
        bool valid = false;
        if(ai[n - 1] - ai[1] == 0){
            if(ai[n - 1] != ai[0]){
                std::cout << "YES" << std::endl;
                std::string b(n - 2, 'B');
                std::cout << "RR" << b << std::endl;
            }else{
                std::cout << "NO" << std::endl;
            }
        }else{
            std::cout << "YES" << std::endl;
            std::string b(n - 1, 'B');
            std::cout << 'R' << b << std::endl;
        }
    }

    return 0;
}