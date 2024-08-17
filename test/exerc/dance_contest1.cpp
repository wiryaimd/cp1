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

std::string tmp;
int x, n, r, y, j;

int memo[11][26][2];

void f(int total, int step, std::vector<std::pair<int, char>>& d, std::vector<bool> used, std::pair<int, char> prev, int h, int& cnt, bool ypass){
    if(step == r){
        if(total > h){
            cnt++;
        }
        return;
    }

    // debug(r);
    // debug(step);
    // debug(total);

    for(int i = 0; i < d.size(); i++){
        if(used[i]) continue;

        int m = memo[i][prev.second - 'A'][ypass || prev.second == 'Y'];
        if(m != -1){
            used[i] = true;
            f(total + m, step + 1, d, used, d[i], h, cnt, ypass || prev.second == 'Y');
            used[i] = false;
            continue;
        }

        used[i] = true;

        int score = d[i].first;
        if(prev.second == 'P'){
            score *= 2;
        }else if(prev.second == 'L'){
            score /= 2;
        }

        if(prev.second == 'Y') ypass = true;
        if(ypass) score += y;
        // debug(score);
        memo[i][prev.second - 'A'][ypass] = score;
        f(total + score, step + 1, d, used, d[i], h, cnt, ypass || prev.second == 'Y');
        used[i] = false;
    }
}

int main(){
    std::cin >> tmp >> x;
    std::cin >> n >> r >> y >> j;

    // std::memset(memo, -1, sizeof(memo));

    std::vector<std::pair<int, char>> d;
    for(int i = 0; i < n; i++){
        int p;
        char c;
        std::cin >> p >> c;
        d.push_back({p, c});
    } 

    for(int i = 0; i < j; i++){
        std::memset(memo, -1, sizeof(memo));
        int h;
        std::cin >> h;

        int cnt = 0;
        f(0, 0, d, std::vector<bool>(n, false), {0, '0'}, h, cnt, false);

        std::cout << cnt << std::endl;
    }

    return 0;
}