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

    int n, c;
    std::cin >> n >> c;
    std::vector<std::string> a;

    for(int i = 0; i < n; i++){
        std::string s;
        std::cin >> s;

        a.push_back(s);
    }

    while(true){
        bool pass = true;
        int maxx = 0;
        for(int i = 0; i < a.size(); i++){
            // debug(a[i]);
            if(a[i].find('0') == std::string::npos){
                // debug(a[i]);

                a.erase(a.begin() + i);
                pass = false;
                maxx = i;

                i--;
            }
        }

        for(int i = 0; i < c; i++){
            for(int j = 0; j < maxx; j++){
                if(a[maxx - j - 1][i] - '0'){
                    a[maxx - j - 1][i] = '0';
                    for(int k = maxx - j - 1; k < a.size(); k++){
                        if(k + 1 == a.size()){
                            a[k][i] = '1';
                            break;
                        }

                        if(a[k + 1][i] - '0'){
                            a[k][i] = '1';
                            break;
                        }
                    }
                }
            }
        }

        if(pass){
            break;
        }
    }

    for(int i = a.size(); i < n; i++){
        std::cout << std::string(c, '0') << std::endl;
    }

    for(int i = 0; i < a.size(); i++){
        std::cout << a[i] << std::endl;
    }

    return 0;
}