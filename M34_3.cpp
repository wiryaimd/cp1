#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

int main(){

    /*
        given xi value and K
        find how much need to replace xi value with minimum value between its k sequence length, to make all value same

        the things that replacing around k sequence with minimum will always take the minimum == 1,
        which is we can just count using ceil(cnt_minimum / (k - 1))
        step
            - find most minimum
            - count how much non minimum val contain in xi
            - count the result using ceil(cnt / (k - 1))
    */

    int n, k;
    std::cin >> n >> k;
    int ai[n];
    int minn = INT32_MAX;
    for(int i = 0; i < n; i++){
        std::cin >> ai[i];
        minn = std::min(minn, ai[i]);
    }

    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(ai[i] != minn){
            cnt++;
        }
    }

    std::cout << ceil((double)cnt / (k - 1)) << std::endl;

    return 0;
}