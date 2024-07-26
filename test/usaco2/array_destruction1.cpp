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

    int t;
    std::cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        std::cin >> n;
        n *= 2;

        std::vector<int> a(n);
        for(int j = 0; j < n; j++){
            std::cin >> a[j];
        }

        std::sort(a.begin(), a.end());

        int x = a[n - 1];
        debug(x);

        int p = 0;
        int pair = a[p];
        while(p < n - 2){
            std::vector<int> tmp = a;
            tmp.erase(find(tmp.begin(), tmp.end(), tmp[p]));
            tmp.erase(find(tmp.begin(), tmp.end(), x));

            bool pass = false;
            debug(p);
            while(tmp.size() > 0){
                int l = 0, r = tmp.size();
                bool found = false;
                while(l < r){
                    debug(a[l]); 
                    debug(a[r]);
                    if(a[l] + a[r] == x){
                        x = std::max(a[l], a[r]);
                        found = true;
                        debug("found");
                        break;
                    }

                    if(a[l] + a[r] < x){
                        l++;
                    }else{
                        r--;
                    }
                }

                if(!found){
                    p++;
                    x = a[n - 1];
                    break;
                }

                debug(tmp.size());
                tmp.erase(find(tmp.begin(), tmp.end(), tmp[l]));
                tmp.erase(find(tmp.begin(), tmp.end(), tmp[r]));

                if(tmp.size() == 0){
                    pass = true;
                }
            }

            if(pass){
                std::cout << "ngok " << p << std::endl;
                break;
            }
        }
    }

    return 0;
}