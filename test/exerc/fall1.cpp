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
    debug(n);
    debug(c);

    std::vector<std::string> a(n);
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    // debug(n);

    for(int i = n - 1; i >= 0; i--){
        bool line = true;
        for(int j = 0; j < c; j++){
            if(!(a[i][j] - '0')){
                line = false;
                break;
            }
        }
        debug(line);

        if(line){
            a.erase(a.begin() + i);
            for(int j = 0; j < c; j++){
                int curr = 1;
                for(int k = 0; k < i; k++){
                    if(a[k][j] - '0'){
                        a[k][j] = '0';
                        a[i - curr][j] = '1';
                        curr++;
                    }
                }
            }
            i++;
        }
    }

    for(int i = n - 1; i >= 0; i--){
        if(i >= a.size()){
            std::string s(c, '0');
            std::cout << s << std::endl;
            continue;
        }

        std::cout << a[a.size() - i] << std::endl;
    }

    return 0;
}