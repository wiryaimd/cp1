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

// dp tabulation approach

int main(){

    // std::function<int(int, int, int, int)> f = [&](int idx, int ops, int z, int left) -> int{
    //         if(ops == 0) {
    //             return 0;
    //         }

    //         if(dp[ops][z][left] != -1) return dp[ops][z][left];

    //         int ans = arr[idx + 1] + f(idx + 1, ops - 1, z, 0);

    //         if(idx > 0 and !left and ops > 0 and z > 0) {
    //             ans = max(ans, arr[idx - 1] + f(idx - 1, ops - 1, z - 1, 1));
    //         }

    //         return dp[ops][z][left] = ans;
    // };

    // cout << arr[0] + f(0, k, z, 0) << endl

    
    /*
        inline void solve() {
        cin >> n >> k >> z;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            memset(dp[i], -1, sizeof dp[i]);
        }
        dp[0][0] = a[1];
        for (int i = 1; i <= k; ++i) {
            dp[i][0] = dp[i-1][0]+a[1+i];
            for (int j = 1; j <= z; ++j) {
            int p = 1+i-j-j;
            if (p < 1) break;
            if (dp[i-1][j] != -1)
                dp[i][j] = max(dp[i][j], dp[i-1][j]+a[p]);
            if (dp[i-1][j-1] != -1)
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]+a[p]);
            }
        }
        int res = 0;
        for (int i = 0; i <= z; ++i) {
            res = max(res, dp[k][i]);
        }
        cout << res << endl;
        }
    */

   /*
        f[100010][6][2];
        while(t1--){
            ans=0;
            scanf("%d%d%d",&n,&k,&mx);
            for(i=1;i<=n;i++)scanf("%d",&a[i]);
            for(i=0;i<=k;i++)
            for(j=0;j<=mx;j++)f[i][j][0]=f[i][j][1]=-2e9;
            f[0][0][0]=a[1];
            for(i=0;i<k;i++){
                for(j=0;j<=mx;j++){
                    x=i+1-j*2;
                    if(x<1)continue;
                    f[i+1][j][0]=max(f[i+1][j][0],max(f[i][j][0],f[i][j][1])+a[x+1]);
                    if(x>1&&j<mx)f[i+1][j+1][1]=max(f[i+1][j+1][1],f[i][j][0]+a[x-1]);
                }
            }
            for(j=0;j<=mx;j++)ans=max(ans,max(f[k][j][0],f[k][j][1]));
            printf("%d\n",ans);
        }
   */
    

    return 0;
}