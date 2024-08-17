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

    int n, b;
    std::cin >> n >> b;

    int a[n];
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    std::sort(a, a + n, std::greater<int>());
    int res = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        res++;
        cnt += a[i];
        if(cnt >= b){
            break;
        }
    }

    std::cout << res << std::endl;

    return 0;
}