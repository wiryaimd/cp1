/*
 * Prob: array desctruction (*1700)
 * File Created: Thursday, 25th July 2024 11:34:54 am
 * Author: Wiryaimd
 */


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

int main(){

    /*
        given N data
        firstly, predict x that equal to sum of two elements in N
        delete that two values, then replace x with max of last two deleted elements before.
        do it repeatedly until N is empty

        check whether the N can be empty or not (print NO if cant)

        sol:
            seems like will work when using two pointer approach, but need more time processing

            otherwise use multiset, and notice that
            to predict x, first pair will always at biggest value, and we can find the second pair by brute force all possibilities
            it because x will replaced and other remainder element need to find that ai + aj == x
    */

    int t;
    std::cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        std::cin >> n;
        n *= 2;

        int a[n];
        for(int j = 0; j < n; j++){
            std::cin >> a[j];
        }

        std::sort(a, a + n);

        std::vector<std::pair<int, int>> res; // for answer later, store each process
        bool pass = false;
        for(int j = 0; j < n - 1; j++){
            int x = a[j] + a[n - 1]; // a[j] for try all possib + most biggest
            // debug(x);
            std::multiset<int> rem;
            res.clear();

            for(int k = 0; k < n; k++){
                rem.insert(a[k]); // recreate original N data
            }

            bool valid = true;
            while(rem.size() != 0){
                int maxx = *rem.rbegin();
                rem.erase(rem.find(maxx)); // erase pair1 (most max)

                if(rem.find(x - maxx) == rem.end()){ // if pair2 not found then try another pair a[j]
                    valid = false;
                    break;
                }

                rem.erase(rem.find(x - maxx)); // erase pair2 (x = pair1 + pair2) then (pair2 = x - pair1)
                res.push_back({x - maxx, maxx}); // store ans
                x = maxx; // replace new x (always its max)
            }

            if(valid){
                pass = true;
                std::cout << "YES" << std::endl;
                std::cout << a[j] + a[n - 1] << std::endl;
                for(int k = 0; k < res.size(); k++){
                    std::cout << res[k].first << " " << res[k].second << std::endl;
                }
                break;
            }
        }

        if(!pass){
            std::cout << "NO" << std::endl;
        }
        
    }

    return 0;
}