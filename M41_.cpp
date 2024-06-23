/*
 * Prob: Shrinking
 * File Created: Friday, 21st June 2024 6:37:47 pm
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

int main(){

    /*
        not really solved, observe more for this prob
    */

    std::string s;
    std::cin >> s;

    int res = s.length();
    for(int i = 0; i < 26; i++){
        int cnt = 0;
        int maxx = 0;
        for(int j = 0; j < s.length(); j++){
            if('a' + i == s[j]){
                br;
                cnt = 0;
            }else{
                debug((char)'a' + i);
                cnt++;
            }
            debug(cnt);

            maxx = std::max(maxx, cnt);
        }
        res = std::min(res, maxx);
    }

    std::cout << res << std::endl;

    return 0;
}