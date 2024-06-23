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
        sort x data, find its each gap, store to arr,
        then sort the gap and count most smallest gap until n - x
    */

    int n, x;
    std::cin >> x >> n;

    std::vector<int> v(n);
    for(int i = 0; i < n; i++){
        std::cin >> v[i];
    }

    std::sort(v.begin(), v.end());

    std::vector<int> gap(n - 1); // gap size is n - 1 because gap use i+1 - i
    for(int i = 0; i < n - 1; i++){
        gap[i] = v[i + 1] - v[i];
        // debug(gap[i]);
    }

    std::sort(gap.begin(), gap.end());
    long long cnt = 0;
    for(int i = 0; i < n - x; i++){
        cnt += gap[i];

        {
            debug("cekk");
        }
    }

    std::cout << cnt << std::endl;

    return 0;
}