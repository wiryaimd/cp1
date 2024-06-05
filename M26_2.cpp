#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

int main(){

    int n;
    std::cin >> n;
    std::vector<unsigned long long> a(n);

    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }
    
    unsigned long long curr = a[0];
    int cnt = 1;

    bool incr = false;
    bool tmp = incr;
    for(int i = 1; i < n; i++){
        if(curr > a[i]){
            tmp = incr;
            incr = false;
        }else if(curr < a[i]){
            tmp = incr;
            incr = true;
        }

        if(tmp != incr){
            debug(curr);
            debug(a[i]);br;
            cnt++;
        }
        debug(a[i]);

        curr = a[i];
    }

    // if(incr){
    //     cnt++;
    // }

    std::cout << cnt << std::endl;

    return 0;
}