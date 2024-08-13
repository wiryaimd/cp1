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
    std::cin >> n;

    std::set<std::string> a;
    for(int i = 0; i < n; i++){
        std::string s;
        std::cin >> s;
        a.insert(s);

        auto pos = std::distance(a.begin(), a.find(s));
        std::cout << pos + 1 << std::endl;
    }

    return 0;
}