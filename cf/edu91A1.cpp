#ifndef ONLINE_JUDGE
#include "../debug.hpp"
#else
#define debug(...)
#define debugArr(...)
#endif

#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<cstring>
#include<numeric>

using ll = long long;
const ll INF = 1e18 + 7;

int n;
int a[1001];

bool f(){ // TLE, O(n^3)
    for(int i = 0; i < n - 2; i++){
        for(int j = i + 1; j < n - 1; j++){
            if(a[i] < a[j]){
                for(int k = j + 1; k < n; k++){
                    if(a[j] > a[k]){
                        std::cout << "YES" << std::endl;
                        std::cout << i + 1 << " " << j + 1 << " " << k + 1 << std::endl;
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main(){

    int t;
    std::cin >> t;

    while(t--){
        std::cin >> n;
        for(int i = 0; i < n; i++){
            std::cin >> a[i];
        }

        if(f()){
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}