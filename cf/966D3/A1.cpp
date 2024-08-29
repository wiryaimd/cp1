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
        std::string a;
        std::cin >> a;

        if(a.length() <= 2){
            std::cout << "NO" << std::endl;
            continue;
        }

        if(a.substr(0, 2) == "10"){
            if(a.length() == 3 && (a[2] == '0' || a[2] == '1')){
                std::cout << "NO" << std::endl;
            }else{
                if(a[2] == '0'){
                    std::cout << "NO" << std::endl;
                    continue;
                }
                int x = std::stoi(a.substr(2));
                if(x >= 2){
                    std::cout << "YES" << std::endl;
                }else{
                    std::cout << "NO" << std::endl;
                }
            }
            continue;
        }

        std::cout << "NO" << std::endl;
    }

    return 0;
}