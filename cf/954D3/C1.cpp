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

    int t;
    std::cin >> t;
    for(int i = 0; i < t; i++){
        int n, m;
        std::string s;

        std::cin >> n >> m >> s;
        int mi[m];
        for(int j = 0; j < m; j++){
            std::cin >> mi[j];
        }

        std::string c;
        std::cin >> c;

        std::sort(mi, mi + m);
        std::sort(c.begin(), c.end());

        int l = 0, r = m - 1;
        
        for(int k = 0; k < m - 1; k++){
            if(mi[k] == mi[k + 1]){
                s[mi[k] - 1] = c[r];
                r--;
            }else{
                s[mi[k] - 1] = c[l];
                l++;
            }
        }

        s[mi[m - 1] - 1] = c[l]; // jingan, jangan s[n - 1] kocak
        std::cout << s << std::endl;
    }

    return 0;
}