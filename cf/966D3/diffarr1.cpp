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

    int q;
    std::cin >> q;

    int a[6] = {0};
    int ori[6] = {1, 2, 3, 4, 5};

    for(int i = 0; i < q; i++){
        int l, r, x;
        std::cin >> l >> r >> x;

        a[l] += x;
        a[r + 1] -= x;
    }

    for(int i = 1; i < 6; i++){
        a[i] = a[i] + a[i - 1];
    }

    for(int i = 0; i < 6; i++){
        debug(a[i]);
    }


    return 0;
}