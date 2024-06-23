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

    //unsolved

    int t;
    std::cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        std::string s;

        std::cin >> n >> s;

        if(n < 2){
            std::cout << s << std::endl;
            continue;
        }

        // bool z = false;
        // for(int j = 0; j < n; j++){
        //     if(s[j] == '0'){
        //         z = true;
        //         break;
        //     }
        // }

        // if(z) {
        //     std::cout << "0" << std::endl;
        //     continue;
        // }

        int minn = INT32_MAX;
        for(int j = 0; j < n - 1; j++){
            minn = std::min(minn, std::stoi(s.substr(j, 2)));
        }
        debug(minn);

        long long total = 0;
        for(int j = 0; j < n; j++){
            if(s[j] == '1') continue;
            if(s[j] == '0') total = 0;
            total += s[j] - '0';
        }

        std::cout << total << std::endl;
    }

    return 0;
}