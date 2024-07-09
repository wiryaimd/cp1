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

    /*
        
        the things is at ps[i][j] its the sum total rectangle i x j,
        then, to insert each i j value, we can use 

        ps[i][j] = ps[i - 1][j] + ps[i][j - 1] + x // sum total area before row i, and before col j
        and
        ps[i][j] -= ps[i - 1][j - 1] // its subtracted because this area have been added two times, so decrease one time

        also
            to find total area of x1, y1, x2, y2, where x1 < x2 and y1 < y2. you can use
            total = ps[y2][x2] - ps[y1 - 1][x2] - ps[y2][x1 - 1] + ps[y1 - 1][x1 - 1];

            where theres also +ps[y1 - 1][x1 - 1]; because area at ps[y1][x1] have been subtracted two times

            careful where to place y and x as row or column
    */

    int n;
    std::cin >> n;
    std::vector<std::vector<int>> ps(n + 1, std::vector<int>(n + 1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x;
            std::cin >> x;

            ps[i][j] = ps[i - 1][j] + ps[i][j - 1] + x;
            ps[i][j] -= ps[i - 1][j - 1];
        }
    }

    for(int i = 1; i <= n; i++){ // 2d prefix sum result
        for(int j = 1; j <= n; j++){
            std::cout << ps[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}