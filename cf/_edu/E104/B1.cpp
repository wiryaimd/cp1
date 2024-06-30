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

    /*
        given N spots for two cat A and B,
        each hours, cat A will sleep from spot N..1 and cat B will sleep from spot 1..N
        theres will some intersect in some spot and cat A always take that spot and B will skip that spot (+1 spot)

        find at where cat B after K hour
    */

    int t;
    std::cin >> t;
    for(int i = 0; i < t; i++){
        int n, k;
        std::cin >> n >> k;

        if(n % 2 == 0){ // if n is even then, cats A and B will never intersect each other
            int res = ((k - 1) % n) + 1; // get position between k % n
            std::cout << res << std::endl;
        }else{
            /*
                theres a pattern when how much A and B intersect each others
                it depend on how much size of N

                eg.
                when N is 3 there will be always 1 gap until meet intersection (3 / 2)
                when N is 5 there will be always 2 gap until meet intersection (5 / 2)
                (actually there will be gap-1, because k/gap, but nvm)
            */
            int gap = n / 2;


            k--; // for skip n[0] cuz it always not intersect with A and B, and also for (k - 1) % n + 1

            // count from k + how much gap passed after K times, then find its below N (using % n)
            int res = ((k + (k / gap)) % n) + 1;
            std::cout << res << std::endl;
        }
    }

    return 0;
}