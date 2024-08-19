// #include<iostream>
// #include<algorithm>
// #include<vector>
// #include<map>
// #include<set>
// #include<cmath>
// #include<cstring>
// #include<numeric>

// #define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
// #define br std::cerr << std::endl;

// using ll = long long;

// int main(){

//     int n, k;
//     std::cin >> n >> k;

//     int w[k], p[k];
//     for(int i = 0; i < k; i++){
//         std::cin >> w[i] >> p[i];
//     }

//     std::vector<std::vector<ll>> dp(k + 1, std::vector<ll>(n + 1, 0));
//     std::vector<std::vector<ll>> take(k + 1, std::vector<ll>(n + 1, 0));
//     for(int i = k; i > 0; i--){
//         for(int j = n; j >= 0; j--){
//             if(j - w[i - 1] >= 0){
//                 dp[i][j] = std::max(dp[i + 1][j], dp[i + 1][j - w[i - 1]] + p[i - 1]);
//                 take[i][j] = true;
//             }else{
//                 dp[i][j] = dp[i - 1][j];
//             }
//         }
//     }

//     // debug(dp[k][n]);
//     std::vector<int> res;

//     int j = n;
//     // for(; j > 0; j--){
//     //     if(dp[k][j] != dp[k][j - 1]) break;
//     // }
//     // for(int i = n - 1; i >= 0; i--){
//     //     if(dp[k][i] == dp[k][n]){
//     //         j = i;
//     //     }
//     // }

//     for(int i = k; i > 0; i--){
//         if(take[i][j]){
//             debug(i);
//             j -= w[i - 1];
//         }
//         // if(j - w[i - 1] >= 0 && dp[i][j] == dp[i - 1][j - w[i - 1]] + p[i - 1]){
//         //     j -= w[i - 1];
//         //     res.push_back(i);
//         // }
//     }

//     std::sort(res.begin(), res.end());

//     for(int i = 0; i < res.size(); i++){
//         std::cout << res[i] << std::endl;
//     }


//     return 0;
// }