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

std::vector<int> memo(1001, -1);
int f(int x){
    if(x < 4){
        return 0;
    }

    if(memo[x] != -1) return memo[x];

    int cnt = std::max(x / 4, f(x / 4)) + std::max(x / 3, f(x / 3)) + std::max(x / 2, f(x / 2));
    memo[x] = cnt;
    return memo[x];

}

// vector<int> dp;
// int tukar(int x){
//     if(x==0) return 0;
//     if(dp[x]!=-1) return dp[x];
//     int a, b, c;
//     a=tukar(x/2);
//     b=tukar(x/3);
//     c=tukar(x/4);
//     int best=a+b+c;
//     dp[x]=max(x, best);
//     return dp[x];
// }

int main(){

    int n;
    std::cin >> n;

    int maxx = std::max(n, f(n));
    std::cout << maxx << std::endl;

    return 0;
}