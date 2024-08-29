#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<cstring>
#include<numeric>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

using ll = long long;

int main(){

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t--){
        int n, k;
        std::cin >> n >> k;

        int a[n];
        for(int i = 0; i < n; i++){
            std::cin >> a[i];
        }

        std::sort(a, a + n);
        ll minn = a[n - 1];
        ll maxx = minn;
        ll m = minn;
        for(int i = 0; i < n - 1; i++){
            int div = (minn - a[i]) / k;
            if(div % 2 == 1){
                div++;
            }

            ll curr = a[i] + (div * k);
            m = std::min(m, curr);
            maxx = std::max(maxx, std::max(curr, minn));
        }
        // debug(maxx);
        // debug(m);
        if(maxx - m >= k){
            // debug("hem");
            std::cout << -1 << std::endl;
            continue;
        }

        // debug(maxx);
        std::cout << maxx << std::endl;
    }

    return 0;
}

/*
other sol

int t;
cin>>t;
while(t--) {
    int n,k;
    cin>>n>>k;
    for(int i=1; i<=n; ++i)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1; i<=n; ++i)
        a[i]+=(a[n]+k-1-a[i])/(k*2)*k*2;
    sort(a+1,a+n+1);
    if(a[n]-a[1]+1>k) cout<<-1<<endl;
    else cout<<a[n]<<endl;
}
return 0;
*/