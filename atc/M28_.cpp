/*
 * Prob: #
 * File Created: Wednesday, 5th June 2024 9:14:56 pm
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
        prefix sum approach

        given n arr with xi val, and
        given k

        find most max sum of K adjecent value, 
        where K adjecent is sum of expected value 1 to xi
            nb. 1 to xi is 1+2+3+..+xi where we can use n*(n+1)/2
            and because finding expected(average) value
            then we can /n
                where the formula will be n*(n+1)/2/n == (n+1) / 2
        
        because its K adjecent, then we can use prefix sum to get i-th sum
        with ith = s[i] - s[i - k] / 2
    */

    int n, k;
    std::cin >> n >> k;

    int s[n + 1];
    s[0] = 0;
    for(int i = 1; i <= n; i++){
        int a;
        std::cin >> a;
        //get prefix sum
        s[i] = s[i - 1] + a + 1; // + 1 because ther formula for 1 to xi is (n+1)/2 (we /2 later)
        debug(s[i]);
    }

    double maxx = 0;
    for(int i = 1; i <= n; i++){
        if(i >= k){ // no need +1 because prefix sum s[] already start at 1 and i = 1
            debug(i);
            debug(s[i]);
            debug(s[i] - s[i - k]); br;
            double curr = (double)(s[i] - s[i - k]) / 2;
            if(curr > maxx){ // find max
                maxx = curr;
            }
            // maxx = std::max(maxx, (s[i] - s[i - k]) / 2);
        }
    }

    // std::cout << maxx << std::endl;
    printf("%.12lf\n", maxx);


    /*
        other solution

        cin >> n >> k;
        vector<ll>dl(n);
        for(ll i=0; i<n; i++)cin >> dl[i];

        ll st = 0;
        for(ll i=0; i<k; i++)st+=dl[i];
        // cout << st << endl;

        ll sum_max=st;

        for(ll i=1; i<=n-k; i++){
            st+=dl[i+k-1]-dl[i-1];
            chmax(sum_max,st);
            
        }
    */

   /*
    other sol (also prefix sum):
    vector<int> p(n);
    for (auto&& e : p) {
        cin >> e;
    }
    vector<double> cum(n + 1);
    for (int i = n; i--; ) {
        cum[i] = 0.5 * (1 + p[i]) + cum[i + 1];
    }
    double res = 0;
    for (int i = 0; i + k <= n; ++i) {
        res = max(res, cum[i] - cum[i + k]);
    }
    cout << res << '\n';
   */

    return 0;
}