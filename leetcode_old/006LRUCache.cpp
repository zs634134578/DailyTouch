/*
    Design and implement a data structure for Least Recently Used (LRU) cache.
    It should support the following operations: get and set.
*/

#include <iostream>
#include <map>

using namespace std;

#define print(key, value) std::cout << "get value: " << key << "->" << value << std::endl;
#define debug(debuginfo) std::cout << debuginfo << std::endl;

class LRUCache;
void printkeyArray(LRUCache* lru);
void printMap(map<int, int>* cacheMap);


class LRUCache 
{
public:
    LRUCache( int capacity ) {
        this->capacity = capacity;
        this->totalNum = 0;
        keyArray = new int[capacity];
    }

    int get( int key ) {
        map<int, int>::iterator it = cacheMap.find(key);
        if ( it != cacheMap.end() )
        {
            // tag the element is used currently
            moveTop(2, key);
            std::cout << "get: ";  printkeyArray(this);
            std::cout << "get: " << key << "->" << it->second << std::endl;
            return it->second;
        }
        std::cout << "get: " << key << "->" << -1 << std::endl;
        return -1;
    }

    int set( int key, int value ) {
        std::cout << "set key->value: " << key << "->" << value << std::endl;
        if ( totalNum < capacity && this->cacheMap.find(key) == this->cacheMap.end() )
        {
            totalNum++;
        }
        this->moveTop(1 ,key);
        //cacheMap[key] = value;
        cacheMap[key] = value;
        std::cout << "set: "; printkeyArray(this);
    }

    void moveTop(int op, int key)
    {
        int index = totalNum - 1;
        int keyToBeErased;

        for ( int i = 0; i < this->totalNum-1; i++ )
        {
            if ( this->keyArray[i] == key )
            {
                index = i;
                
            }
        }
        if( op == 1 && totalNum == capacity  && index == totalNum-1)
        {
            keyToBeErased = this->keyArray[capacity-1];
            cacheMap.erase(keyToBeErased);
        }

        for( int j = index-1; j >= 0; j-- )
        {
            this->keyArray[j+1] = this->keyArray[j];
        }
        this->keyArray[0] = key;
    }

public:
    int* keyArray;    //the last one in this array is removed first.
    int totalNum;
private:
    int capacity;
    map<int, int> cacheMap;
};

void printkeyArray(LRUCache* lru)
{
    std::cout << "keyArray: ";
    for(int i = 0; i < lru->totalNum; i++)
    {
        std::cout << lru->keyArray[i] << " ";
    }
    std::cout << std::endl;
}

void printMap(map<int, int>* cacheMap)
{
    std::cout << "printMap: " << std::endl;
    for( map<int, int>::iterator it = cacheMap->begin(); it != cacheMap->end(); it++ )
    {
        std::cout << "\t" << it->first << " : " << it->second << std::endl;
    }
}

int main()
{
    LRUCache* lru = new LRUCache(2);
    lru->set(2,1);
    lru->set(1,1);
    lru->get(2);
    lru->set(1588,102);
    lru->get(1);
    lru->get(1588);
    /*
    lru->set(7,28);
    lru->set(7,1);
    lru->set(8,15);
    lru->get(6);
    lru->set(10,27);
    lru->set(8,10);
    lru->get(8);
    lru->set(6,29);
    lru->set(1, 9);
    lru->get(6);
    lru->set(10, 7);
    lru->get(1);
    lru->get(2);
    lru->get(13);
    lru->set(8, 30);
    lru->set(1, 5);
    lru->get(1);
    lru->set(13, 2);
    lru->get(12);
    */

    return 0;

}
