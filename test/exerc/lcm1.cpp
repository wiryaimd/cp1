/*
 * Prob: pasar rakyat
 * File Created: Tuesday, 13th August 2024 12:26:13 pm
 * Author: Wiryaimd
 */


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

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}

int main(){

    int n;
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    int curr = lcm(a[0], a[1]);
    for(int i = 2; i < n; i++){
        curr = lcm(curr, a[i]);
    }

    std::cout << curr << std::endl;

    return 0;
}