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

int lcs(int pos1, int pos2, std::string s1, std::string s2){
    if(pos1 == 0 || pos2 == 0) return 0;
    if(s1[pos1 - 1] == s2[pos2 - 1]){
        return lcs(pos1 - 1, pos2 - 1, s1, s2) + 1;
    }
    return std::max(lcs(pos1 - 1, pos2, s1, s2), lcs(pos1, pos2 - 1, s1, s2));
}

int main(){

    int n;
    std::cin >> n;
    while(n--){
        std::string s;
        std::cin >> s;

        std::string tmp = s;
        std::reverse(tmp.begin(), tmp.end());
        int maxx = lcs(s.length(), s.length(), s, tmp);
        std::cout << maxx << std::endl;
    }

    return 0;
}