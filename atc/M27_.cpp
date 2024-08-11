/*
 * Prob: #
 * File Created: Wednesday, 5th June 2024 8:08:18 pm
 * Author: Wiryaimd
 */

#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

int main(){

    int n;
    std::string s, t;
    std::cin >> n >> s >> t;

    int k = 0;
    for(int i = 0; i < n; i++){
        // debug(i);
        // debug(k); br;
        if(s[i] == t[k]){
            k++;
        }else{
            i -= k;
            k = 0;
        }
    }

    std::cout << n + n - k << std::endl;

    return 0;
}