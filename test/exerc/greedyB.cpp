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

    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> a(n);
    for(int i = 0; i < n; i++){
        std::cin >> a[i].first >> a[i].second;
    }

    std::sort(a.begin(), a.end(), [](std::pair<int, int>& a, std::pair<int, int>& b){
        return a.first + a.second < b.first + b.second;
    });

    int cnt = 1;
    std::pair<int, int> curr = a[0];
    for(int i = 1; i < n; i++){
        if(curr.first + curr.second > a[i].first){ // notice that first + second > a[i].first. not second > a[i].first
            continue;
        }
        cnt++;
        curr = a[i];
    }

    std::cout << cnt << std::endl;

    return 0;
}