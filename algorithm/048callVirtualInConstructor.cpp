/*
 *
 */

#include <iostream>

using namespace std;

#define debug(x, y) std::cout << "(debug)" << x << y << std::endl;
#define print(x) std::cout << x << std::endl;

class Transaction {
    public:
     Transaction();
      virtual void logTransaction() const = 0;
};
Transaction::Transaction()
{
     logTransaction();
}

void Transaction::logTransaction() const
{
    print("BaseClass's logTransaction called.");
}


class BuyTransaction:public Transaction
{
public:
    BuyTransaction()
    {
        logTransaction();
    }
    virtual void logTransaction() const
    {
        print("ChildClass's logTransaction called.");
    }
};

int main()
{
    //BuyTransaction* buy = new BuyTransaction(); 
    BuyTransaction buy;

    print("Hello world!");
    return 0;
}
