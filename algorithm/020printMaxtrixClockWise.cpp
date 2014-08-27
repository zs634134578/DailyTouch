/*
    输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
    例如：输入如下矩阵
    1    2    3   4
    5    6    7   8
    9   10  11  12
    13 14  15  16
    打印结果： 1 2 3 4 8 12 16 15 14 13 9  5 6 7  11 10
*/

#include <iostream>
using namespace std;

#define print(x) std::cout << x << " " << std::endl;

void printMatrixInCircle(int a[][4], int cols, int rows, int start )
{
    int endx = cols - start -1;
    int endy = rows - start - 1;

    // left to right
    for ( int i = start; i <= endx; i++ )
        print(a[start][i]);

    if ( start < endy ) {
        for( int i = start+1; i <= endy; i++ )
            print(a[i][endx]);
    }
    if( start < endx && start < endy )
    {
        for( int i = endx-1; i >= start; i-- )
            print(a[endy][i]);
    }
    if( start < endx && start < endy-1 )
    {
        for( int i = endy -1; i>=start+1; i-- )
            print(a[i][start]);
    }
}


void printClockWise(int a[][4], int cols, int rows)
{
    if( a == NULL || cols <= 0 || rows <= 0 )
        return;

    int start = 0;

    while( cols > start * 2 && rows > start * 2 )
    {
        printMatrixInCircle(a, cols, rows, start);
        start++;
    }
}

int main()
{
    int a[4][4] = { 1, 2,  3,  4,
                    5, 6,  7,  8,
                    9, 10,11, 12,
                    13,14,15, 16
                  };
    printClockWise(a, 4, 4);
    return 0;
}
