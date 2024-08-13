/*
 * Prob: #
 * File Created: Tuesday, 13th August 2024 12:49:28 pm
 * Author: Wiryaimd
 */


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

    int n, m, k;
    std::cin >> n >> m >> k;

    int a[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cin >> a[i][j];
        }
    }

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    std::vector<std::pair<int, int>> res;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int cnt = 1;
            for(int d = 0; d < 4; d++){
                int cx = j + dx[d];
                int cy = i + dy[d];
                if(cx < 0 || cx >= m || cy < 0 || cy >= n) continue;
                cnt = cnt * a[cy][cx];
            }
            if(cnt == k){
                res.push_back({j + 1, i + 1});
            }
        }
    }

    if(res.size() == 0){
        std::cout << 0 << " " << 0 << std::endl;
        return 0;
    }

    std::sort(res.begin(), res.end());
    std::cout << res[0].second << " " << res[0].first << std::endl;

    return 0;
}