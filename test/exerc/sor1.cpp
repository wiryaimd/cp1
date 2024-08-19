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

    std::vector<std::string> a(n);
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end(), [](std::string& a, std::string& b){
        if(a.length() == b.length()) return a.compare(b) <= 0;
        return a.length() < b.length();
    });

    for(int i = 0; i < n; i++){
        std::cout << a[i] << std::endl;
    }

    return 0;
}