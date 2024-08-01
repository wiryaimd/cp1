/*
 * Prob: #
 * File Created: Wednesday, 31st July 2024 3:17:26 pm
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

// floyd cycle problem and solve using its approach
// find each i-th data using floyd cycle

int fc(std::vector<int> a, int target){
    int fast = target;
    int slow = target;
    while(true){
        slow = a[slow];
        fast = a[a[fast]];
        if(slow == fast) break;
    }

    slow = target;
    while(fast != slow){
        slow = a[slow];
        fast = a[fast];
    }

    return slow;
}

int main(){

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for(int i = 0; i < n; i++){
        int x;
        std::cin >> x;
        x--; // 1-index based input
        a[i] = x;
    }

    for(int i = 0; i < n; i++){
        int res = fc(a, i) + 1;
        std::cout << res << std::endl;
    }
        

    return 0;
}