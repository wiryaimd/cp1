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

int bs(std::vector<int>& a, int l, int r, int x){
    int mid = l + (r - l) / 2;
    while(l <= r){
        mid = l + (r - l) / 2;
        if(a[mid] == x){
            return mid;
        }

        if(a[mid] < x){
            l = mid + 1;
        }else{
            r = mid - 1;;
        }
    }

    return mid;
}

int main(){

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    int q;
    std::cin >> q;
    while(q--){
        int x, y;
        std::cin >> x >> y;
        int res = bs(a, 0, a.size() - 1, y) - bs(a, 0, a.size() - 1, x);
        std::cout << res << std::endl;
    }

    return 0;
}