#include<bits/stdc++.h>
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));
#define endl "\n"
using namespace std;
#define int long long
#define ld long double
#define pb(e) push_back(e)
#define sv(a) sort(a.begin(),a.end())
#define all(x) x.begin(),x.end()
#define debug(x) cout<<#x<<" "<<x<<endl;
#define ff first 
#define ss second
#define mk make_pair
#define mt make_tuple
#define eb emplace_back
#define gcd(a,b) __gcd(a,b)
#define lb lower_bound
#define ub upper_bound
#define cin(v) for(auto &i:v){cin>>i;}
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
int lcm(int a,int b){
    return a*(b/(__gcd(a,b)));
}
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){          
    return (a.second < b.second);
}
bool cmp(const pair<int,int> &a, const pair<int,int> &b){
    if(a.ss!=b.ss) return a.ss<b.ss;
    return a.ff<b.ff;
}
void print(vector<int> v){
    for(auto i: v) cout<<i<<" ";
    cout<<endl;
}
void print(set<int > v){
    for(auto i: v) cout<<i<<" ";
    cout<<endl;
}
void print(multiset<int > v){
    for(auto i: v) cout<<i<<" ";
    cout<<endl;
}
void print(map<int,int > v){
    for(auto i: v) cout<<i.ff<<" "<<i.ss<<endl;;
}
bool prime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
 
string bin(int num) 
{ 
    string str; 
      while(num){ 
      if(num & 1) // 1 
        str+='1'; 
      else // 0 
        str+='0'; 
      num>>=1; // Right Shift by 1   
    }    
    reverse(all(str));
    return str; 
}
int dis(int a,int b,int c,int d) {
    return((a-c)*(a-c)+(b-d)*(b-d));
}
int fact(int n){
    if(n==1) return 1;
    int a=1,md=1e9+7;
    while(n>0){
        a=(a*n)%md;
        n--;
    }
    return a;
}
int mex(map<int,int> &mp){
    int n=mp.size();
    for(int i=0;i<=n;i++){
        if(mp[i]==0) return i;
    }
}
int pw(int a,int b){
    int ans=1;
    while(b--){
        ans*=a;
    }
    return ans;
}
int isSubstring(string s1, string s2)
{
    // using find method to check if s1 is
    // a substring of s2
    if (s2.find(s1) != string::npos)
        return s2.find(s1);
    return -1;
}
int binexp(int a,int b){
    const int mod = 1e9 + 7;
    if(b==0) return 1;
    int res=binexp(a,b/2);
    if(b&1) return (a*((res*res)%mod))%mod;
    else return (res*res)%mod;
}
int f(string s,string t,int i,int j,vector<vector<int>> dp){
    if(j==t.size() ) return s.size()-i;
    else if(i==s.size()) return 0;
    if(s[i]==t[j]) return f(s,t,i+1,j+1,dp);
    else return min(1+f(s,t,i+1,j+1,dp),1+f(s,t,i+1,j,dp));

}


int f(int i,int j,vector<int> &v,vector<vector<int>> &dp){
    if(i==v.size()) return 0;
    int ntake=f(i+1,j,v,dp);
    int take=0;
    if(j==0 || v[i]>v[j-1]){
        take=1+f(i+1,i+1,v,dp);
    }
    return max(ntake,take);


}
signed main(){
    fastread();
    int tc=1;
    // cin>>tc;
    while(tc--){
        const int mod = 1e9 + 7,md=998244353;
        int a=0,b=0,c=0,d=0,x=0,y=0,z=0,l=0,n=0,m=0,q=0,p=1,r=0,k=0,h=0;
        string s,t;
        cin>>n;
        vector<vector<int>> v(n,vector<int> (3));
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++) cin>>v[i][j];
        }
        vector<vector<int>> dp(n,vector<int> (3,0));
        dp[0][0]=v[0][0];
        dp[0][1]=v[0][1];
        dp[0][2]=v[0][2];
        for(int i=1;i<n;i++){
            dp[i][0]=v[i][0]+max(dp[i-1][1],dp[i-1][2]);
            dp[i][1]=v[i][1]+max(dp[i-1][0],dp[i-1][2]);
            dp[i][2]=v[i][2]+max(dp[i-1][1],dp[i-1][0]);
        }
        cout<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
        


        
        
        

        
        
    }
}