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
int res = 0;

void f(std::vector<std::vector<int>>& a, int row, int col, int target){
    if(row < 0 || row >= a.size() || col < 0 || col >= a[0].size()){
        return;
    }
    
    if(visited[row][col]){
        return;
    }
	
	if(a[row][col] != target){
		return;
	}

    visited[row][col] = true;
	res++;
    
    for(int i = 0; i < 4; i++){
        int x = dx[i] + col;
        int y = dy[i] + row;
        f(a, y, x, target);
    }
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
	
    int maxx = 0;
    for(int i = 0; i < n; i++){
       for(int j = 0; j < m; j++){
           f(a, i, j, a[i][j]);
           maxx = std::max(maxx, res);
           res = 0;
       }
    }
	
    std::cout << maxx * (maxx - 1) << std::endl;
    
    return 0;
}