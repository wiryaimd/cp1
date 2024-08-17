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

std::map<std::tuple<int, int, std::vector<bool>, bool>, int> mp;
int f(int total, int step, std::vector<std::pair<int, char>>& d, std::vector<bool> used, std::pair<int, char> prev, int h, bool ypass){
    std::tuple<int, int, std::vector<bool>, bool> key = std::make_tuple(total, step, used, ypass);
    if(mp.count(key)) return mp[key];
    if(step == r){
        if(total > h){
            return 1;
        }
        return 0;
    }

    int cnt = 0;
    for(int i = 0; i < d.size(); i++){
        if(used[i]) continue;

        int score = d[i].first;
        if(prev.second == 'P'){
            score *= 2;
        }else if(prev.second == 'L'){
            score /= 2;
        }

        if(prev.second == 'Y') ypass = true;
        if(ypass) score += y;

        used[i] = true;
        cnt += f(total + score, step + 1, d, used, d[i], h, ypass || prev.second == 'Y');
        used[i] = false;
    }

    mp[key] = cnt;
    return cnt;
}

int main(){

    std::cin >> tmp >> x;
    std::cin >> n >> r >> y >> j;

    std::vector<std::pair<int, char>> d;
    for(int i = 0; i < n; i++){
        int p;
        char c;
        std::cin >> p >> c;
        d.push_back({p, c});
    } 

    for(int i = 0; i < j; i++){
        int h;
        std::cin >> h;

        mp.clear();
        int cnt = f(0, 0, d, std::vector<bool>(n, false), {0, '0'}, h, false);

        std::cout << cnt << std::endl;
    }


    return 0;
}