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

    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    // int total = std::max(b, d) - std::min(a, c);
    // std::cout << total << std::endl;

    int total = (b - a) + (d - c);  // the sum of the two intervals

    // get intersection between (a, b) and (c, d)
	int intersection = std::max(std::min(b, d) - std::max(a, c), 0);  // subtract the intersection
	int ans = total - intersection;

    std::cout << ans << std::endl;


    return 0;
}