#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

using ll = long long;

int main(){

    ll K, A, B;
    std::cin >> K >> A >> B;

    ll ret=1;
	if(A+2>=B)
	{
		ret+=K;
	}
	else
	{
		ll z=std::min(K,A-1);
        debug(z);
		ret+=z;
		K-=z;
        debug(K);
		ret+=(B-A)*(K/2);
        debug((B-A)*(K/2));
		ret+=K%2;
        debug(K%2);
	}

    std::cout << ret << std::endl;

    return 0;
}