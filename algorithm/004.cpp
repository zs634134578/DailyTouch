#include <iostream>

int main() 
{
    int array[4][4] = {1, 2, 8, 9,
        2, 4, 9, 12,
        4, 7, 10, 13,
        6, 8, 11, 15};
    int i, j;
    i = 0;
    j = 3;  // 右上角的值
    int targetValue;
    bool flag;

    while(1) {
        flag = false;
        std::cout << "targetValue: ";
        std::cin >> targetValue;

        while( i <=3 && j >=0  ) {
            if ( array[i][j] == targetValue )
            {
                flag = true;
                break;
            }
            else if ( array[i][j] > targetValue )
                j--;
            else
                i++;
        }

        if ( flag )
            std::cout << "true" << std::endl;
        else
            std::cout << "false" << std::endl;
    }
    std::cout << "Hello world!" << std::endl;
    return 0;
}
