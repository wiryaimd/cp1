/*
 * Prob: #
 * File Created: Sunday, 9th June 2024 7:43:59 am
 * Author: Wiryaimd
 */

#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

int main(){

    int n;
    std::cin >> n;

    int n4 = 0, n2 = 0, odd = 0;
    for(int i = 0; i < n; i++){
        int a;
        std::cin >> a;

        if(a % 4 == 0){
            n4++;
        }else if(a % 2 == 0){
            n2++;
        }else{
            odd++;
        }
    }

    if(n4 + 1 == odd && n2 == 0){
        std::cout << "Yes" << std::endl;
    }else if(odd > n4){
        std::cout << "No" << std::endl;
    }else{
        std::cout << "Yes" << std::endl;
    }

    return 0;

    /*
        others sol:

        int main(){

            int n;
            std::cin >> n;

            int cnt = 0;
            for(int i = 0; i < n; i++){
                int a;
                std::cin >> a;

                if(a % 4 == 0){
                    cnt += 2;
                }else if(a % 2 == 0){
                    cnt++;
                }
            }

            if(cnt >= n/2*2){ // make n/2 floored div, then multp by 2
                std::cout << "Yes" << std::endl;
            }else{
                std::cout << "No" << std::endl;
            }

            return 0;
        }
    */
}