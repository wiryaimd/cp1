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

    std::vector<std::pair<int, int>> v;
    for(int i = 0; i < n; i++){
        int a, d;
        std::cin >> a >> d;
        v.push_back({a, d});
    }

    std::sort(v.begin(), v.end(), [](std::pair<int, int>& a, std::pair<int, int>& b){
        return a.first < b.first;
    });

    ll curr = 0;
    ll maxx = 0;
    for(int i = 0; i < v.size(); i++){
        curr += v[i].first;
        maxx += v[i].second - curr;
    }

    std::cout << maxx << std::endl;


    return 0;
}