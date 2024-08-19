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

int main(){

    int n;
    std::cin >> n;

    std::pair<int, int> a[n], b[n], c[n];
    for(int i = 0; i < n; i++){
        std::cin >> a[i].first >> b[i].first >> c[i].first;
        a[i].second = 1;
        b[i].second = 2;
        c[i].second = 3;
    }

    int cnt = 0;
    int last = -1;
    for(int i = 0; i < n; i++){
        std::vector<std::pair<int, int>> v = {a[i], b[i], c[i]};
        std::sort(v.begin(), v.end(), [](std::pair<int, int> x, std::pair<int, int> y){
            return x.first > y.first;
        });

        // debug(v[0].first);

        std::pair<int, int> t = v[0];
        if(last == v[0].second){
            t = v[1];
        }
        cnt += t.first;
        last = t.second;
    }

    std::cout << cnt << std::endl;

    return 0;
}