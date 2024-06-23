/*
 * Prob: #
 * File Created: Sunday, 23rd June 2024 2:10:50 pm
 * Author: Wiryaimd
 */


#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
#include<map>
#include<set>
#include<cmath>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

using ll = long long;

int main(){

    /*
        given n data w xi

        insert each ith to new var at the end position, then reverse the order
        do it until all n data

        sol
            you can push head and tail sequentially so it no need to reverse each time
            reverse only after all data inserted when n is even (because it will reverse n even times)
    */

    int n;
    std::cin >> n;

    std::deque<int> deq;
    // deq.push_front();
    // deq.push_back();

    std::vector<int> a;
    for(int i = 0; i < n; i++){
        int x;
        std::cin >> x;
        if(i % 2 == 0){ 
            a.insert(a.begin(), x); // or use deque<> for push head and push tail
        }else{
            a.push_back(x);
        }
    }

    if(n % 2 == 0){
        std::reverse(a.begin(), a.end());
    }

    for(int i = 0; i < n; i++){
        std::cout << a[i];
        if(i < n - 1){
            std::cout << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}