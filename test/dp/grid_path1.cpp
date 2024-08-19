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

int cnt = 0;

int f(int x, int y, int n, bool path[1001][1001]){
    if(x >= n || x < 0 || y >= n || y < 0) return 0;
    if(x == n - 1 && y == n - 1) return 1;
    if(path[x][y]) return 0;

    return f(x + 1, y, n, path) + f(x, y + 1, n, path);
}

int main(){

    int n;
    std::cin >> n;

    bool path[1001][1001];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char a;
            std::cin >> a;
            path[i][j] = a == '*';
        }
    }

    int res = f(0, 0, n, path);
    std::cout << res << std::endl;

    return 0;
}