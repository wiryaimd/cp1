#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

int main(){

    /*
        WA 1 testcase, try find em
    */

    int n, k;
    std::cin >> n >> k;
    int ai[n];
    int minn = INT32_MAX;
    for(int i = 0; i < n; i++){
        std::cin >> ai[i];
        minn = std::min(minn, ai[i]);
    }

    int cnt = 0, ck = 1;
    bool pass = true;
    for(int i = 0; i < n; i++){
        debug(ck);
        if(ck > k - 1){
            if(!pass){
                debug("hem");
                cnt++;
            }
            ck = 1;
            pass = true;
        }
        ck++;

        if(ai[i] != minn){
            pass = false;
        }
    }

    if(!pass && n != k) cnt++;

    std::cout << cnt << std::endl;

    return 0;
}