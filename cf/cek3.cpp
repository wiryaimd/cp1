#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

int main(){

    int t;
    std::cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        std::cin >> n;
        
        long cnt = 0;
        for(int j = 0; j < n - 1; j++){
            int a;
            std::cin >> a;
            cnt += a;
        }

        std::cout << -1 * cnt << std::endl;
    }

    return 0;
}