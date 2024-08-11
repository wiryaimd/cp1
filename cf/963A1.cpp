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

    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++){
        int n;
        std::string s;
        std::cin >> n >> s;

        std::vector<int> lett(4, 0);
        for(int j = 0; j < s.size(); j++){
            if(s[j] == '?') continue;
            lett[s[j] - 'A']++;
        }

        int cnt = 0;
        for(int j = 0; j < 4; j++){
            cnt += std::min(n, lett[j]);
        }

        std::cout << cnt << std::endl;
    }

    return 0;
}