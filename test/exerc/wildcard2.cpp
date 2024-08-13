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

    int n;
    std::string s;
    
    std::cin >> s >> n;
    int ask = s.find('*');

    for(int i = 0; i < n; i++){
        std::string a;
        std::cin >> a;

        if(s.size() - 1 > a.size()) continue;
        if(s.substr(0, ask) == a.substr(0, ask) && s.substr(ask + 1) == a.substr(a.size() - (s.size() - ask - 1))){
            std::cout << a << std::endl;
        }
    }

    return 0;
}