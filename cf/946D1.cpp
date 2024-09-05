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

    int t;
    std::cin >> t;
    while(t--){
        int n;
        std::string s;

        std::cin >> n >> s;
        if(s.length() == 2 && s[0] != s[1]){
            std::cout << "NO" << std::endl;
            continue;
        }

        std::vector<int> alp[26];
        for(int i = 0; i < n; i++){
            alp[s[i] - 'A'].push_back(i);
        }

        std::vector<std::pair<int, int>> pair;
        auto& south = alp['S' - 'A'];
        auto& north = alp['N' - 'A'];
        while(north.size()){
            if(south.size() == 0) break;
            pair.push_back({south[0], north[0]});
            south.erase(south.begin());
            north.erase(north.begin());
        }

        auto& west = alp['W' - 'A'];
        auto& east = alp['E' - 'A'];
        while(east.size()){
            if(west.size() == 0) break;
            pair.push_back({west[0], east[0]});
            west.erase(west.begin());
            east.erase(east.begin());
        }

        if(south.size() % 2 == 1 || north.size() % 2 == 1 || west.size() % 2 == 1 || east.size() % 2 == 1){
            std::cout << "NO" << std::endl;
            continue;
        }

        std::string res(n, ' ');
        bool gilir = false;
        for(int i = 0; i < pair.size(); i++){
            res[pair[i].first] = gilir ? 'R' : 'H';
            res[pair[i].second] = gilir ? 'R' : 'H';
            gilir = !gilir;
        }

        int a[4] = {'N', 'E', 'W', 'S'};
        for(int i = 0; i < 4; i++){
            auto curr = alp[a[i] - 'A'];
            for(int j = 0; j < curr.size(); j++){
                if(j >= curr.size() / 2){
                    res[curr[j]] = 'H';
                }else{
                    res[curr[j]] = 'R';
                }
            }
        }

        std::cout << res << std::endl;
    }

    return 0;
}