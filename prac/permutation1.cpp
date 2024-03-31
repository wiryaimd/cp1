#include<iostream>
#include<algorithm>

using namespace std;
int main(){

    int data[] = {2, 3, 4, 5}; // data perlu di sort terlebih dahulu,
    // karena function next_permutation menghasilkan nilai dari paling terurut hingga ke n!

    // 4! == 24

    int i = 1;
    do{
        cout << i << ": ";
        cout << data[0] << " hoh " << data[1] << " hoh " << data[2] << " " << data[3] << endl;
        i++;
    }while(next_permutation(data, data + 4)); // 24 kali permutasi

    // next_permutation();

    return 0;
}