#ifndef ONLINE_JUDGE
#include "../debug.hpp"
#else
#define debug(...)
#define debugArr(...)
#endif

#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<cstring>
#include<numeric>

using ll = long long;
const ll INF = 1e18 + 7;

int main(){

    /*
    You are given a permutation p1,p2,…,pn. Recall that sequence of n
    integers is called a permutation if it contains all integers from 1 to n exactly once.

    Find three indices i, j and k such that:
    * 1 ≤ i < j < k ≤ n;
    * pi < pj and pj > pk.
    
    Or say that there are no such indices
    */

    int t;
    std::cin >> t;
    while(t--){
        int n;
        std::cin >> n;

        int a[n];
        for(int i = 0; i < n; i++){
            std::cin >> a[i];
        }

        bool no = true;
        for(int i = 1; i < n - 1; i++){
            int f1 = -1, f2 = -1;
            bool found1 = false, found2 = false;
            for(int j = i - 1; j >= 0; j--){
                if(a[j] < a[i]){
                    f1 = j + 1;
                    found1 = true;
                    break;
                }
            }

            for(int j = i + 1; j < n; j++){
                if(a[i] > a[j]){
                    f2 = j + 1;
                    found2 = true;
                    break;
                }
            }

            if(found1 && found2){
                std::cout << "YES" << std::endl;
                std::cout << f1 << " " << i + 1 << " " << f2 << std::endl;
                no = false;
                break;
            }
        }

        if(no) std::cout << "NO" << std::endl;
    }

    return 0;
}

/*
    o(n) solution
    we only need to check i, i - 1 and i + 1, it because if theres some answer then the ans will be between i, i-1, i+1,
    when there is no such triple (answer), the array will be descends to some point and ascends after that,
    so there is no answer

    for (int i = 1; i < n - 1; ++i) {
		if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
			cout << "YES" << endl;
			cout << i << ' ' << i + 1 << ' ' << i + 2 << endl;
			return;
		}
	}
*/