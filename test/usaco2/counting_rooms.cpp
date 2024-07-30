/*
 * Prob: #
 * File Created: Tuesday, 30th July 2024 2:41:15 pm
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

bool visit[1007][1007];
int n, m;

void f(int r, int c, bool rooms[1007][1007]){
    if(r < 0 || r >= n || c < 0 || c >= m) return;
    if(rooms[r][c]) return;
    if(visit[r][c]) return;

    visit[r][c] = true;

    f(r + 1, c, rooms);
    f(r - 1, c, rooms);
    f(r, c + 1, rooms);
    f(r, c - 1, rooms);
}

int main(){

    std::cin >> n >> m;
    bool rooms[1007][1007];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char a;
            std::cin >> a;

            rooms[i][j] = a == '#';
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visit[i][j] && !rooms[i][j]){
                cnt++;
                f(i, j, rooms);
            }
        }
    }

    std::cout << cnt << std::endl;

    return 0;
}