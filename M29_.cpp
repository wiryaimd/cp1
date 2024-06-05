#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

int main(){

    std::string s, t;
    std::cin >> s >> t;

    std::sort(s.begin(), s.end());
    std::sort(t.begin(), t.end(), std::greater<char>());
    std::reverse(t.begin(), t.end());

    // debug(s.compare(t) < 0);
    std::cout << (s.compare(t) < 0 ? "Yes" : "No") << std::endl;
    
    return 0;
}