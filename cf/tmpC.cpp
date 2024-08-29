#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<cstring>
#include<numeric>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

using ll = long long;

int main(){

    int t;
    std::cin >> t;

    std::string con[4] = {"00", "50", "25", "75"};
    while(t--){
        std::string a;
        std::cin >> a;

        int cnt = 0;

        std::string a1 = a;
        std::string a2 = a;
        while(true){
            int len1 = a1.length();
            int len2 = a2.length();

            bool found = false;
            // debug(a1.substr(len1 - 2));
            // debug(a2.substr(len2 - 2));
            for(int i = 0; i < 4; i++){
                if(a1.substr(len1 - 2) == con[i] || a2.substr(len2 - 2) == con[i]){
                    found = true;
                    break;
                }
            }

            if(found){
                break;
            }

            if(a1[len1 - 1] == '0'){
                a1.erase(a1.begin() + len1 - 2);
            }else{
                a1.erase(a1.begin() + len1 - 1);
            }

            if(a2[len2 - 1] == '5'){
                a2.erase(a2.begin() + len2 - 2);
            }else{
                a2.erase(a2.begin() + len2 - 1);
            }
            cnt++;
        }

        std::cout << cnt << std::endl;
    }

    return 0;
}