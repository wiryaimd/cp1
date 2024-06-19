#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

int main(){

    // freopen("M36.in", "r", stdin);

    int n, x;
    std::cin >> n >> x;
    int a[n];

    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }
    
    std::sort(a, a + n);

    int minn = INT32_MAX;
    int tmp = a[0];
    for(int i = 1; i < n; i++){
        minn = std::min(minn, std::abs(a[i] - tmp));
        debug(minn);
        tmp = a[i];
    }

    if(n == 1){
        minn = std::abs(a[0] - x);
    }

    int curr = a[0];
    while(std::abs(curr - x) % minn != 0){
        double sq = sqrt(minn);
        double sqr = (int) sq;
        debug(sq - sqr);
        // debug(sqr);
        // if((double)sq != (int)sqr){
        //     debug("not eq");
        //     break;
        // }
        minn = sqr;

        if(minn == 1){
            std::cout << 1 << std::endl;
            return 0;
        }
    }

    for(int i = 1; i < n; i++){
        debug(a[i]);
        debug(curr);
        debug(a[i] - curr); br;
        if((a[i] - curr) % minn != 0){
            minn = sqrt(minn);
            i--;
            if(minn == 1){
                break;
            }
            continue;
        }

        curr = a[i];
    }

    std::cout << minn << std::endl; // res always between min and sqrt(min) ??

    return 0;
}