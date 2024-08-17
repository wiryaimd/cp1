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

int main(){

    std::string tmp;
    int x, n, r, y, j;

    std::cin >> tmp >> x;
    std::cin >> n >> r >> y >> j;

    std::vector<int> pos(n);
    std::vector<std::pair<int, char>> d(n);
    std::iota(pos.begin(), pos.end(), 0);

    for(int i = 0; i < n; i++){
        std::cin >> d[i].first >> d[i].second;
    }

    std::vector<int> res;
    while(std::next_permutation(pos.begin(), pos.end())){
        int total = 0;
        bool ypass = false;
        char prev = '0';
        for(int i = 0; i < r; i++){
            int score = d[pos[i]].first;
            if(prev == 'P'){
                score *= 2;
            }else if(prev == 'L'){
                score /= 2;
            }

            if(d[pos[i]].second == 'Y') ypass = true;
            if(ypass) score += y;

            prev = d[pos[i]].second;
            total += score;
        }

        res.push_back(total);
    }

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