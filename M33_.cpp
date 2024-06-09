#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

int main(){

    std::string s;
    std::cin >> s;

    std::string res;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'B'){
            if(res.length() == 0) continue;
            res.pop_back();
            continue;
        }

        res.push_back(s[i]);
    }

    std::cout << res << std::endl;

    return 0;
}