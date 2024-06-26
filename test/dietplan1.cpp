#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<numeric>
#include<queue>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

using ll = long long;

int main(){

    int n, m, k;
    std::cin >> n >> m >> k;

    // std::priority_queue<> // use this instead

    std::vector<int> v;
    int maxx = 0;
    int cnt = 0;

    int total = 0;
    for(int i = 0; i < n; i++){
        int x;
        std::cin >> x;

        total += x;
        if(total > m && k == 0){
            break;
        }

        v.push_back(x);

        std::sort(v.begin(), v.end());
        maxx = v[v.size() - 1];

        cnt++;
        if(total >= m && k > 0){
            total -= maxx;
            v.erase(v.end() - 1);
            k--;
        }
        
        if(k == 0 && total > m){
            break;
        }
    }

    std::cout << cnt << std::endl;

    return 0;
}