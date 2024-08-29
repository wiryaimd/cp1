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
        int n, k;
        std::cin >> n >> k;

        int a[k];

        int maxx = 0;
        int pos = 0;
        for(int i = 0; i < k; i++){
            std::cin >> a[i];
            if(a[i] > maxx){
                maxx = a[i];
                pos = i;
            }
        }

        ll cnt = 0;
        for(int i = 0; i < k; i++){
            if(i == pos) continue;
            cnt += (a[i] - 1) + a[i];
        }

        std::cout << cnt << std::endl;
    }

    return 0;
}