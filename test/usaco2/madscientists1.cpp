#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

using ll = long long;

int main(){

    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);

    /*
        greedy problem and solution (its not bruteforce)
        because it only take specific optimal solution to get total cnt
    */

    int n;
    std::string a, b;

    std::cin >> n >> a >> b;
    int cnt = 0;

    bool diff = false;
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]){
            diff = true;
            continue;
        }

        if(diff){
            cnt++;
            diff = false;
        }
    }

    if(diff){
        cnt++;
    }

    std::cout << cnt << std::endl;


    return 0;
}