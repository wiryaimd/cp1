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

    int dx[4] = {0, -1, 1, 0};
    int dy[4] = {-1, 0, 0, 1};

    for(int i = 0; i < t; i++){
        int n, m;
        std::cin >> n >> m;

        int mtx[n][m];
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                std::cin >> mtx[j][k];
            }
        }

        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                int curr = mtx[j][k];
                bool big = true;
                int maxx = 0;
                for(int d = 0; d < 4; d++){
                    int rx = j + dx[d];
                    int cx = k + dy[d];
                    if(rx < 0 || rx >= n || cx < 0 || cx >= m) continue;

                    maxx = std::max(maxx, mtx[rx][cx]);
                    
                    if(curr < mtx[rx][cx]){
                        big = false;
                    }
                }

                if(big){
                    mtx[j][k] = maxx;
                }
            }
        }

        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                std::cout << mtx[j][k];
                if(k < m - 1){
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
        }
    }

    return 0;
}