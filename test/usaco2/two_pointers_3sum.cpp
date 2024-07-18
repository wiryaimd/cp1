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

    /*
        3SUM
            similar like 2SUM but this find 3 var
        
        sol
            add main loop for checking each i, and check with two pointers (same approach)
    */

    int n, x;
    std::cin >> n >> x;

    std::pair<int, int> a[n];
    for(int i = 0; i < n; i++){
        int ai;
        std::cin >> ai;
        a[i] = std::make_pair(ai, i);
    }

    std::sort(a, a + n);

    for(int i = 0; i < n; i++){
        int l = 0, r = n - 1;
        while(l < r){
            if(i == l){
                l++;
                continue;
            }
            if(i == r){
                r--;
                continue;
            }

            if(a[i].first + a[l].first + a[r].first == x){
                std::cout << a[i].second + 1 << " " << a[l].second + 1<< " " << a[r].second + 1 << std::endl;
                return 0;
            }

            if(a[i].first + a[l].first + a[r].first < x){
                l++;
            }else{
                r--;
            }
        }
    }

    std::cout << "IMPOSSIBLE" << std::endl;

    return 0;
}