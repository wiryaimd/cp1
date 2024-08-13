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

    std::vector<std::string> a;
    for(int i = 0; i < n; i++){
        std::string s;
        std::cin >> s;
        a.push_back(s);

        std::sort(a.begin(), a.end());
        auto pos = std::find(a.begin(), a.end(), s);
        std::cout << pos - a.begin() + 1 << std::endl;
    }

    return 0;
}