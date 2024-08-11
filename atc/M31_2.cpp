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

    /*
        given xi val

        check if its possible for each xi * xi+1 is multiple of 4

        the things is
        if total of xi mod 4 have more than total odd value, then its possible
        and xi mod 2 (even number) can also possible to making multiple of 4
            eg. 2x2, 2x12, 2x14, etc
        
        then count only odd number and compare if its less than multiple 4 or not
    */

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

    if(n4 + 1 == odd && n2 == 0){ // + 1 because one xi mult of 4 can make two odd value be multiple of 4 (eg. 5 x 4 x 7)
        std::cout << "Yes" << std::endl;
    }else if(odd > n4){ // if odd more than n4 then not possible (eg. 3 x 4 x 5 x 7)
        std::cout << "No" << std::endl;
    }else{ // theres some n2 in this condition and total n4 still > odd (eg. 3 x 8 x 2 x 4 x 5 x 4 x 2)
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