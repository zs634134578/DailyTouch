
#include "stringUtility.h"

#include <iostream>
#include <algorithm>

int main()
{
    std::string str("1!2!#!4!7!#!#!8!#!11!13!#!#!14!#!#!3!5!9!12!15!#!#!16!#!#!#!10!#!#!6!#!#!");
    std::vector<std::string> resultVec;
    SplitToVec(str, "!", resultVec);
    for_each(resultVec.begin(), resultVec.end(),
             [](const std::string& ele){
                std::cout << ele << " ";
             });
    std::cout << std::endl;
    return 0;
}
