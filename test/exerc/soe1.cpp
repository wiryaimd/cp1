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

    int t;
    std::cin >> t;

    std::vector<int> prime;
    std::vector<bool> mark(1000000, true);

    for(int i = 2; i * i <= mark.size(); i++){
        if(mark[i]){
            for(int j = i * i; j <= mark.size(); j += i){
                mark[j] = false;
            }
        }
    }

    for(int i = 2; i <= mark.size(); i++){
        if(mark[i]) prime.push_back(i);
    }

    while(t--){
        int k;
        std::cin >> k;
        std::cout << prime[k - 1] << std::endl;
    }

    return 0;
}