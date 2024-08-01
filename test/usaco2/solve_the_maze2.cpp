#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<numeric>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

using ll = long long;

int n, m;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int main(){

    // dfs bfs approach instaed of using flood fill
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

        std::vector<std::vector<bool>> visit(n, std::vector<bool>(m, false));

        // bfs approach
        std::queue<std::pair<int, int>> q;
        q.push({n - 1, m - 1});
        while(!q.empty()){
            std::pair<int, int> p = q.front();
            q.pop();

            if(visit[p.first][p.second] || maze[p.first][p.second]) continue;
            visit[p.first][p.second] = true;

            for(int i = 0; i < 4; i++){
                int x = dx[i] + p.first;
                int y = dy[i] + p.second;
                if(x < 0 || x >= n || y < 0 || y >= m) continue;
                q.push({x, y});
            }
        }

        bool pass = true;
        for(int i = 0; i < good.size(); i++){
            if(!visit[good[i].first][good[i].second]){
                pass = false;
                break;
            }
        }

        std::cout << (pass ? "YES" : "NO") << std::endl;
    }


    return 0;
}