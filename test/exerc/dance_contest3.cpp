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

std::vector<int> res;

void f(int total, int step, std::vector<std::pair<int, char>>& d, std::vector<bool> used, std::pair<int, char> prev, bool ypass){
    if(step == r){
        res.push_back(total);
        return;
    }

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
        f(total + score, step + 1, d, used, d[i], ypass || prev.second == 'Y');
        used[i] = false;
    }
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

    f(0, 0, d, std::vector<bool>(n, false), {0, '0'}, false);
    std::sort(res.begin(), res.end());

    for(int i = 0; i < j; i++){
        int h;
        std::cin >> h;

        int ans = -1;
        int l = 0; r = res.size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(res[mid] > h){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        if(ans == -1) {
            std::cout << 0 << std::endl;
            continue;
        }

        std::cout << res.size() - ans << std::endl;
    }

    return 0;
}