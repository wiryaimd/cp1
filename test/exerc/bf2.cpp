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

bool f(std::vector<int>& a, std::vector<int> curr){
    bool valid = true;
    for(int i = 0; i < a.size(); i++){
        // if(curr[i] != a[i]){
        //     valid = false;
        //     break;
        // }
        
        if(curr[i] > a[i]){
            return false;
        }
    }

    if(valid) return true;

    int score[3] = {0, 1, 3};
    bool res = false;
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < 3; j++){
            curr[i] += score[j];
            res |= f(a, curr);
        }
    }
    return res;
}

int main(){

    int t;
    std::cin >> t;
    while(t--){
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        std::vector<int> curr(n, 0);
        for(int i = 0; i < n; i++){
            std::cin >> a[i];
        }

        bool posb = f();
        std::cout << (posb ? "YES" : "NO") << std::endl;
    }

    return 0;
}