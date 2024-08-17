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

std::vector<int> memo(1e5 + 7, -1);
int f(std::vector<int>& coins, int x){
    if(x == 0) return 0;
    if(x < 0) return 1e5 + 7;
    if(memo[x] != -1) return memo[x];

    int minn = 1e5 + 7;
    for(int i = 0; i < coins.size(); i++){
        minn = std::min(minn, f(coins, x - coins[i]) + 1);
    }
    memo[x] = minn;
    
    return minn;
}

int main(){

    int n, k;
    std::cin >> n;

    std::vector<int> coins(n);
    for(int i = 0; i < n; i++){
        std::cin >> coins[i];
    }

    std::cin >> k;
    int res = f(coins, k);

    std::cout << res << std::endl;

    return 0;
}