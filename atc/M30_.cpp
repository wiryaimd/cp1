#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

int main(){

    int n, m;
    std::cin >> n >> m;

    // always cast when multiply with big value, because it may exceed int size
    long long r = ((long long)n * m) - ((long long)2 * m + ((long long)2 * n - 4));

    // debug((2 * m + (2 * n - 4)))
    // care using std::abs() instaed of abs(), because abs() only for int type (not ull, or ll etc)
    std::cout << std::abs(r) << std::endl;

    return 0;
}
