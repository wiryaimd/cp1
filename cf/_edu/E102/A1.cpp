/*
 * Prob: replacing elements
 * File Created: Wednesday, 26th June 2024 5:10:56 pm
 * Author: Wiryaimd
 */


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

    /*
        given data ai, and val x
        check if all a[i] can lower than x when you can change a[i] = a[j] + a[k] when its higher, and i, j, k cannot same

        sol:
        notice that you only need to check most [0] and [1] smallest value, if they both added and lower than x, then its possible, otherwise no
        also, check if theres no ai value exceed, then just directly print possible (yes)
    */

    int t;
    std::cin >> t;
    for(int i = 0; i < t; i++){
        int n, x;
        std::cin >> n >> x;
        int a[n];
        bool exceed = false;
        for(int j = 0; j < n; j++){
            std::cin >> a[j];
            if(a[j] > x){
                exceed = true;
            }
        }

        if(!exceed){
            std::cout << "YES" << std::endl;
            continue;
        }

        std::sort(a, a + n);
        if(a[0] + a[1] <= x){
            std::cout << "YES" << std::endl;
        }else{
            std::cout << "NO" << std::endl;
        }
    }
    

    return 0;
}