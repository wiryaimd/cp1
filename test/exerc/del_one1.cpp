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

    std::string s1, s2;
    std::cin >> s1 >> s2;

    for(int i = 0; i < s1.length(); i++){
        std::string tmp = s1;
        tmp.erase(i, 1);
        if(tmp == s2){
            std::cout << "Tentu saja bisa!" << std::endl;
            return 0;
        }
    }

    std::cout << "Wah, tidak bisa :(" << std::endl;

    return 0;
}