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

    int n, q;
    std::cin >> n >> q;
    std::vector<std::vector<ll>> ps(n + 1, std::vector<ll>(n + 1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char x;
            std::cin >> x;

            int a = x == '*';

            ps[i][j] = ps[i - 1][j] + ps[i][j - 1] + a;
            ps[i][j] -= ps[i - 1][j - 1];
        }
    }

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         std::cout << ps[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    for(int i = 0; i < q; i++){
        int x1, y1, x2, y2;
        std::cin >> y1 >> x1 >> y2 >> x2;

        // careful where to place x and y as row or column
        ll total = ps[y2][x2] - ps[y1 - 1][x2] - ps[y2][x1 - 1] + ps[y1 - 1][x1 - 1];
        std::cout << total << std::endl;
    }


    return 0;
}