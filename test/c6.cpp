#include<iostream>
#define debug(x) cerr << (#x) << " " << (x) << endl;

using namespace std;

int v(int a = 2){ // default parameter val in cpp
    return a * 3;
}

int main(){

    string xixixi = "jiahahaha";
    debug(xixixi);

    debug(3 + 5 - 2);

    debug(xixixi.substr(5, 3));
    debug(v());

    return 0;
}