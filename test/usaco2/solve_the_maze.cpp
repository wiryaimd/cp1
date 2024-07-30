/*
 * Prob: #
 * File Created: Tuesday, 30th July 2024 3:02:21 pm
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

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int n, m;

void f(int r, int c, bool maze[51][51], std::vector<std::vector<bool>>& visit){
    // debug(visit[0][0]);
    // debug("cek");
    if(r < 0 || c < 0 || r >= n || c >= m) return;
    if(maze[r][c]) return;
    if(visit[r][c]) return;

    visit[r][c] = true;

    f(r + 1, c, maze, visit);
    f(r - 1, c, maze, visit);
    f(r, c + 1, maze, visit);
    f(r, c - 1, maze, visit);
}

int main(){

    int t;
    std::cin >> t;

    for(int l = 0; l < t; l++){
        std::cin >> n >> m;

        bool maze[51][51] = {{false}};
        std::vector<std::pair<int, int>> good;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                char a;
                std::cin >> a;

                if(a == 'G'){
                    good.push_back({i, j});
                }

                if(a == 'B'){
                    if(j + 1 < m){
                        maze[i][j + 1] = true;
                    }

                    if(j - 1 >= 0){
                        maze[i][j - 1] = true;
                    }

                    if(i + 1 < n){
                        maze[i + 1][j] = true;
                    }

                    if(i - 1 >= 0){
                        maze[i - 1][j] = true;
                    }
                }

                if(maze[i][j]) continue;

                maze[i][j] = a == '#';
            }
        }

        bool possb = true;
        std::vector<std::vector<bool>> visit(n, std::vector<bool>(m, false));
        f(n - 1, m - 1, maze, visit);

        for(int i = 0; i < good.size(); i++){
            if(!visit[good[i].first][good[i].second]){
                possb = false;
                break;
            }
            // bool visit[51][51] = {{false}};
            // bool pass = f(good[i].first, good[i].second, maze, visit);
            // if(!pass){
            //     possb = false;
            //     break;
            // }
        }

        std::cout << (possb ? "YES" : "NO") << std::endl;
    }

    return 0;
}