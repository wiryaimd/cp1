#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

using ll = long long;

int main(){

    int t;
    std::cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        std::cin >> n;

        int a[n];
        int maxx = 0;
        int cnt = 0;
        long long total = 0;
        for(int j = 0; j < n; j++){
            std::cin >> a[j];

            maxx = std::max(maxx, a[j]);
            total += a[j];

            long long tmp = total - maxx;
            if(tmp == maxx){
                cnt++;
            }
        }   
        std::cout << cnt << std::endl;
    }

    return 0;
}