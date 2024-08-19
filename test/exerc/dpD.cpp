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

std::map<std::string, int> memo;
bool found = false;
int res = 0;

int f(std::string s){
    if(found) return 1;

    int n = s.length();
    if(n == 1) return 1;
    if(memo[s]) return memo[s];

    // debug(s);

    bool valid = true;
    for(int i = 0; i < n / 2; i++){
        if(s[i] != s[n - i - 1]){
            valid = false;
            break;
        }
    }

    if(valid){
        found = true;
        res = n;
        return n;
    }

    int maxx = 0;
    for(int i = 0; i < n; i++){
        std::string tmp = s;
        tmp.erase(tmp.begin() + i);
        int maxx = std::max(maxx, f(tmp));
    }

    memo[s] = maxx;

    return maxx;
}

int main(){

    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++){
        std::string s;
        std::cin >> s;
        f(s);
        std::cout << res << std::endl;
    }

    return 0;
}