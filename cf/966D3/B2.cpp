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
        std::cin >> n;

        int a[n + 2] = {0};

        int x;
        std::cin >> x;
        a[x] = 1;

        bool valid = true;
        for(int i = 1; i < n; i++){
            int ai;
            std::cin >> ai;
            if(a[ai]){
                valid = false;
                continue;
            }

            if(a[ai - 1] || a[ai + 1]){
                a[ai] = 1;
                continue;
            }

            valid = false;
        }

        std::cout << (valid ? "YES" : "NO") << std::endl;
    }

    return 0;
}