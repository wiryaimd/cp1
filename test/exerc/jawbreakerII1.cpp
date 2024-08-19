#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<cstring>
#include<numeric>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

using ll = long long;

std::vector<std::vector<bool>> visited(26, std::vector<bool>(26, false));
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

std::map<std::pair<int, int>, int> mp;

int f(std::vector<std::vector<int>>& a, int row, int col, int target){
    if(row < 0 || row >= a.size() || col < 0 || col >= a[0].size()){
        return 0;
    }

    std::pair<int, int> p = {row, col};
    if(mp[p]){
        // debug(mp[p]);
        return mp[p];
    }
    
    if(visited[row][col]){
        return 0;
    }
	
	if(a[row][col] != target){
		return 0;
	}

    visited[row][col] = true;

    int cnt = 1;
    for(int i = 0; i < 4; i++){
        int x = dx[i] + col;
        int y = dy[i] + row;
        int curr = f(a, y, x, target);
        mp[{y, x}] = curr;
        cnt += curr;
    }

    debug(cnt);
    return cnt;
}

int main(){
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cin >> a[i][j];
        }
    }
    
    // int b, k;
    // std::cin >> b >> k;
	
	// int x = a[b][k];
	
    int maxx = 0;
    for(int i = 0; i < n; i++){
       for(int j = 0; j < m; j++){
            int cnt = f(a, i, j, a[i][j]);
            // visited = std::vector<std::vector<bool>>(26, std::vector<bool>(26, false));
            for(auto& k : visited){
                std::fill(k.begin(), k.end(), false);
            }

            // debug(cnt);
            maxx = std::max(maxx, cnt);
       }
    }
	
    std::cout << maxx * (maxx - 1) << std::endl;
    
    return 0;
}