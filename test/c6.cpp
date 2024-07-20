#include<iostream>
#include<algorithm>
#include<numeric>
#include<tuple>
#include<queue>
#define debug(x) cerr << (#x) << " " << (x) << endl;

using namespace std;

int v(int a = 2){ // default parameter val in cpp
    return a * 3;
}

int main(){

    // string xixixi = "jiahahaha";
    // debug(xixixi);

    // debug(3 + 5 - 2);

    // debug(xixixi.substr(5, 3));
    // debug(v());

    std::priority_queue<int> pq;
    pq.push(235);
    pq.push(2399);
    pq.push(2399);
    pq.push(231);
    pq.push(5);
    debug(pq.top());
    pq.pop();
    debug(pq.top());
    pq.pop();
    debug(pq.top());

    std::tuple<int, int, string> t(2, 3, "iyahh");
    
    string a = std::get<2>(t);
    int b, c;
    string ngok;
    std::tie(b, c, ngok) = t;
    
    debug(a);
    debug(ngok)

    return 0;
}