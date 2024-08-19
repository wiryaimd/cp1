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

    int n, q;
    std::cin >> n >> q;

    std::map<std::string, std::string> mp;
    for(int i = 0; i < n; i++){
        std::string name, num;
        std::cin >> name >> num;
        mp[name] = num;
    }

    for(int i = 0; i < q; i++){
        std::string qi;
        std::cin >> qi;
        if(mp.find(qi) == mp.end()){
            std::cout << "NIHIL" << std::endl;
            continue;
        }
        
        std::cout << mp[qi] << std::endl;
    }

    return 0;
}