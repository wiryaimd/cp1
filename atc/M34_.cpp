// #include<iostream>
// #include<algorithm>
// #include<vector>
// #include<map>
// #include<set>
// #include<cmath>

// #define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
// #define br std::cerr << std::endl;

// int main(){

//     int n, k;
//     std::cin >> n >> k;
//     int minn = INT32_MAX;

//     int ni[n];
//     for(int i = 0; i < n; i++){
//         std::cin >> ni[i];
//         minn = std::min(minn, ni[i]);
//     }

//     int cnt = 0, cntk = 1;
//     bool pass = false;
//     for(int i = 0; i < n; i++){
//         debug(cntk);
//         if(cntk > k){
//             if(!pass){
//                 debug("luls");
//                 cnt++;
//             }
//             pass = false;
//             cntk = 1;
//         }
//         cntk++;

//         if(ni[i] == minn){
//             pass = true;
//             debug(minn);
//         }

//     }

//     if(!pass) cnt++; // ini true tadi karena 0 last
//     debug(cnt);
//     debug(n);
//     debug(k);

//     std::cout << std::ceil((double)(n + cnt) / k) << std::endl;

//     return 0;
// }