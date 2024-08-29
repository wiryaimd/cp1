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
        int a[3] = {0};
        std::cin >> a[0] >> a[1] >> a[2];

        for(int i = 0; i < 5; i++){
            std::sort(a, a + 3);
            a[0]++;
        }

        std::cout << a[0] * a[1] * a[2] << std::endl;
    }

    return 0;
}