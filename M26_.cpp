// #define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
// #define br std::cerr << std::endl;

// #include<iostream>

// int main(){

//     int n;
//     std::cin >> n;

//     int a[n];
//     for(int i = 0; i < n; i++){
//         std::cin >> a[i];
//     }

//     int curr = a[0];
//     bool inc = true;
//     int cnt = 0;
//     for(int i = 1; i < n; i++){
//         if(curr == a[i]){
//             curr = a[i];
//             continue;
//         }
//         debug(curr < a[i] && inc);
//         debug(inc);
//         debug(a[i]);
//         debug(curr); br;
//         if(curr < a[i] && inc){
//             curr = a[i];
//             continue;
//         }

//         if(curr > a[i] && inc){
//             curr = a[i];
//             cnt++;
//             inc = false;
//             continue;
//         }

//         if(curr > a[i] && !inc){
//             curr = a[i];
//             continue;
//         }

//         if(curr < a[i] && !inc){
//             curr = a[i];
//             cnt++;
//             inc = true;
//             continue;
//         }
//     }

//     std::cout << cnt << std::endl;

//     return 0;
// }