/*
 * Prob: Ruined squares
 * File Created: Saturday, 11th May 2024 4:42:39 pm
 * Author: Wiryaimd
 */

#include<iostream>

using namespace std;

int main(){

    /*
        given squares with coordinate x1, y1, x2, y2 point (in counter-clockwise order)
        find his x3, y3, and x4, y4

        need to know that 
        x2-x1 and y2-y1 can be used to find x3 and y3, also x4y4

        point x3 = x2 - (y2-y1)
            substract with len y because x3 will going to opposite direction of x2
        point y3 = y2 - (x2-x1)
            same for y3 and son on

        we subtract with opposite x or y, to find its 90deg coordinate


    */

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int difx = x2 - x1;
    int dify = y2 - y1;
    int x3 = x2 - dify;
    int y3 = y2 + difx;
    int x4 = x3 - difx;
    int y4 = y3 - dify;

    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;

    return 0;
}