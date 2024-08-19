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

int main(){

    int n;
    std::string s;
    std::cin >> s >> n;

    for(int i = 0; i < n; i++){
        std::string a;
        std::cin >> a;

        bool valid = true;
        int last = 0;
        for(int j = 0; j < s.length(); j++){
            last = j;
            if(s[j] == '*'){
                break;
            }

            if(j >= a.size()){
                valid = false;
                break;
            }

            if(s[j] != a[j]){
                valid = false;
                break;
            }
        }

        if(!valid){
            continue;
        }

        // debug(last);
        // debug(s.substr(last + 1));
        // debug(a.substr(a.size() - (s.size() - last - 1)));
        if(s.substr(last + 1) != a.substr(a.size() - (s.size() - last - 1))){
            valid = false;
        }

        if(valid){
            std::cout << a << std::endl;
            // debug(a);
        }
    }

    return 0;
}