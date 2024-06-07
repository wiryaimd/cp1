#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
 
#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
 
int main(){
 
    int t;
    std::cin >> t;
 
    for(int i = 0; i < t; i++){
        int n;
        std::cin >> n;
 
        int curr;
        std::cin >> curr;
        int minn = INT32_MAX;
        for(int j = 1; j < n; j++){
            int a;
            std::cin >> a;
            minn = std::min(minn, std::max(curr, a));
            curr = a;
        }
 
        std::cout << minn - 1 << std::endl;
    }
 
    return 0;
}