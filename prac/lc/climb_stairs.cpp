// #include<iostream>

// using namespace std;

// class Solution {
// public:
//     int res = 0;
//     void rec(int n, int cnt){
//         if(cnt > n){
//             return;
//         }

//         if(cnt == n){
//             res++;
//             return;
//         }

//         rec(n, cnt + 1);
//         rec(n , cnt + 2);
//     }

//     int climbStairs(int n) {
//         rec(n, 0);
//         cout << res << endl;
//         return res;
//     }
// };

// int main(){

//     Solution sol;
//     sol.climbStairs(45);

    
//     return 0;
// }