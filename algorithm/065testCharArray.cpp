/*
 *
 */

#include <iostream>

using namespace std;

#define debug(x, y) std::cout << "(debug)" << x << y << std::endl;
#define print(x) std::cout << x << std::endl;

class Solution
{

};


void printStrArray(char* strArray)
{ 
    for(int i = 0; strArray[i]!='\0'; i++)
        std::cout << strArray[i] ;
    std::cout << std::endl;
   
}

int main()
{
    Solution* solver = new Solution();
    char strArray[] = {'a', 'b','c'};
    debug("strArray: ", strArray);
    debug("size: ", sizeof(strArray)/sizeof(char));

    int intArray[] = {1,2,3};
    std::cout << intArray << std::endl;

    char* str = "abc";
    debug("str: ", str);
    for(int i = 0; strArray[i]!='\0'; i++)
        std::cout << strArray[i] ;

    std::cout << std::endl;
    printStrArray(strArray);
    print("Hello world!");
    return 0;
}
