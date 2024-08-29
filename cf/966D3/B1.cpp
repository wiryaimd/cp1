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
        int n;
        std::cin >> n;

        std::set<int> st;

        int f;
        std::cin >> f;
        st.insert(f);

        bool valid = true;
        for(int i = 1; i < n; i++){
            int a;
            std::cin >> a;
            auto pos = st.upper_bound(a);

            int l, r;
            if(pos == st.end()){
                r = -1;
            }else{
                r = *pos;
            }

            if(pos == st.begin()){
                l = -1;
            }else{
                l = *std::prev(pos);
            }

            if(l == a - 1 || r == a + 1){
                st.insert(a);
                continue;
            }

            valid = false;
        }

        if(valid){
            std::cout << "YES" << std::endl;
        }else{
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}