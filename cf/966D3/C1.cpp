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
    while(t--){
        int n, m;
        std::cin >> n;

        int a[n];
        for(int i = 0; i < n; i++){
            std::cin >> a[i];
        }

        std::cin >> m;
        for(int i = 0; i < m; i++){
            std::string s;
            std::cin >> s;

            if(n != s.length()){
                std::cout << "NO" << std::endl;
                continue;
            }

            bool valid = true;

            std::map<int, std::pair<bool, int>> mp;
            std::map<int, bool> mp2;
            for(int j = 0; j < s.length(); j++){
                bool used = mp[s[j] - 'a'].first;
                int v = mp[s[j] - 'a'].second;
                if(used){
                    if(v != a[j]){
                        valid = false;
                        break;
                    }
                }else{
                    if(mp2[a[j]]){
                        valid = false;
                        break;
                    }else{
                        mp[s[j] - 'a'] = {true, a[j]};
                        mp2[a[j]] = true;
                    }
                }
            }

            std::cout << (valid ? "YES" : "NO") << std::endl;
        }
    }
    

    return 0;
}