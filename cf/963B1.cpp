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

        int a[n];
        ll maxx = 0;
        int even = 0;
        for(int i = 0; i < n; i++){
            std::cin >> a[i];

            if(a[i] % 2 == 0){
                even++;
            }else{
                if(a[i] > maxx){
                    maxx = a[i];
                }
            }
        }

        if(even == n || even == 0){
            std::cout << 0 << std::endl;
            continue;
        }

        std::sort(a, a + n);

        bool worst = false;
        for(int i = 0; i < n; i++){
            if(a[i] % 2 == 0){
                if(maxx > a[i]){
                    maxx += a[i];
                }else{
                    worst = true;
                    break;
                }
            }
        }

        if(worst){
            std::cout << even + 1 << std::endl;
        }else{
            std::cout << even << std::endl;
        }
    }

    return 0;
}