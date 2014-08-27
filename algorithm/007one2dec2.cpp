#include <iostream>
#include <string.h>

#define DEBUG 1
#define debug(x, y) std::cout << x << "\t" << y << std::endl;


void printFull(char* numbers, int len, int index);
void printNumber(char* numbers);


int main()
{
    int n;
    std::cout << "Please input n: ";
    std::cin >> n;

    char* numbers = new char[n + 1];
    memset(numbers, '0', n);
    numbers[n] = '\0';

    int i;
    for ( i = 0; i < 10; i++ )
    {
        numbers[0] = i + '0';
        printFull(numbers, n, 0);
    }
    
    delete[] numbers;

    std::cout << "Hello world" << std::endl;
    return 0;
}

void printFull(char* numbers, int len, int index)
{
   if ( index == len - 1 )
       printNumber(numbers);

   for ( int i = 0; i < 10; i++ )
   {
       numbers[index+1] = i + '0';
       printFull(numbers, len, index + 1);
   }
}

void printNumber(char* numbers)
{
    /*
    int len = strlen(numbers);

    for( int i = 0; i < len; i++ ) {
        std::cout << numbers[i] << std::endl;
    }
    std::cout << std::endl;
    */
    std::cout << numbers << std::endl;
}


