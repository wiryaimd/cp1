#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

int main(){

    int n;
    std::cin >> n;

    int h[n];
    for(int i = 0; i < n; i++){
        std::cin >> h[i];
    }

    int cnt = 0;
    for(int i = 0; i < n; i++){
        while(h[i] > 0){ // using while h[i] > 0 to check each ith still not zero, then loop from i to n
            for(int j = i; j < n; j++){
                if(h[j] == 0){
                    break;
                }

                h[j]--;
            }

            cnt++;
        }
    }

    std::cout << cnt << std::endl;

    return 0;
}