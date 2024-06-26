#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

using ll = long long;

int main(){

    int t;
    std::cin >> t;
    for(int i = 0; i < t; i++){
        int n, m;
        std::cin >> n >> m;
        int top = n - 1, left = m - 1, right = 0, bot = 0;
        for(int j = 0; j < n; j++){
            std::string s;
            std::cin >> s;
            for(int k = 0; k < m; k++){
                if(s[k] == '#'){
                    top = std::min(top, j);
                    left = std::min(left, k);
                    right = std::max(right, k);
                    bot = std::max(bot, j);
                }
            }
        }
        int x = left + ((right - left) / 2) + 1;
        int y = top + ((bot - top) / 2) + 1;
        std::cout << y << " " << x << std::endl;
    }

    return 0;
}