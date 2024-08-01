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

// int fc(std::vector<int> a, int target){
//     int fast = target;
//     int slow = target;
//     while(true){
//         slow = a[slow];
//         fast = a[a[fast]];
//         if(slow == fast) break;
//     }

//     slow = target;
//     while(fast != slow){
//         slow = a[slow];
//         fast = a[fast];
//     }

//     int cnt = 1;
//     fast = a[slow];
//     while(slow != fast){
//         fast = a[fast];
//         cnt++;
//     }

//     return cnt;
// }

// int main(){

//     int n;
//     std::cin >> n;

//     std::vector<int> a(n);
//     for(int i = 0; i < n; i++){
//         int x;
//         std::cin >> x;
//         x--;
//         a[i] = x;
//     }

//     for(int i = 0; i < n; i++){
//         int res = fc(a, i);
//         std::cout << res << std::endl;
//     }
        

//     return 0;
// }