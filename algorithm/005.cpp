#include <iostream>
#include "string.h"


#define print(x,y) std::cout<< x << ": "  << y << std::endl;

int main() {
    char str[30] = "We are happy.";
    int len1 = strlen(str);
    int len2 = len1;
    int i;

    for(i = 0; i < len1; i++) 
    {
        if ( str[i] == ' ' )
            len2 += 2;
    }

    std::cout << "new str len: " << len2 << std::endl;
    int index1 = len1 - 1;
    int index2 = len2 - 1;

    for( ; index1 >= 0 && index2 > index1; index1--, index2-- )
    {
        if ( str[index1] != ' ' )
        {
            str[index2] = str[index1];
        }
        else
        {
            str[index2--] = '0';
            str[index2--] = '2';
            str[index2] = '%';
        }
        std::cout << "mid result: " << str << std::endl;
    }
    
    std::cout << "replace complete: ";
    std::cout << str << std::endl;
    return 0;
}
