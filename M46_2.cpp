/*
 * Prob: #
 * File Created: Sunday, 23rd June 2024 5:11:59 pm
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
        given string s contain 3 alphabet 'a', 'b', 'c'

        check if any substring of s not contains palindrome when it 'permuted'
        
        eg. abac = YES
            it contain palindrome 'aba' but we can permute to make it like 'abca'

        eg2. aba = NO
            aab
            baa 
            still palindrome

        sol
            because it only contain 3 alphabet, then
            it should make each other letter ordered sequentially(alternately) so it will not palindrome.
            we can do this with check differ of total letter[] not more than 1

    */

    std::string s;
    std::cin >> s;

    int alp[3] = {0};
    for(int i = 0; i < s.length(); i++){
        alp[s[i] - 'a']++;
    }

    int maxx = 0;
    int minn = s.length();
    for(int i = 0; i < 3; i++){
        minn = std::min(minn, alp[i]);
        maxx = std::max(maxx, alp[i]);
    }

    if(maxx - minn > 1){
        std::cout << "NO" << std::endl;
    }else{
        std::cout << "YES" << std::endl;
    }

    return 0;
}