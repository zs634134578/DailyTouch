#include <iostream>
#include "../common/array.h"

class HeapSort
{
public:
    HeapSort() {};
    void Run(int* array, int len);
private:
    bool buildHeap(int* array, int len);
    int indexOfLastNotLeafNode(int len);
    void adjust(int* array, int len, int index);
    inline int parentIndex(int index)
    {
        return index % 2 == 0 ? index / 2 - 1: index / 2;
    }
    inline int leftChildIndex(int index)
    {
        return index * 2 + 1;
    }
    inline int rightChildIndex(int index)
    {
        return index * 2 + 2;
    }
    inline void swap(int* array, int index1, int index2)
    {
        int temp = array[index1];
        array[index1] = array[index2];
        array[index2] = temp;
    }
};

void HeapSort::adjust(int* array, int len, int index)
{
    if (index >= len)
    {
        return;
    }
    int left = leftChildIndex(index);
    int right = rightChildIndex(index);
    if (left < len && array[index] < array[left])
    {
        swap(array, index, left);
    }
    if (right < len && array[index] < array[right])
    {
        swap(array, index, right);
    }
    adjust(array, len, left);
    adjust(array, len, right);
}

int HeapSort::indexOfLastNotLeafNode(int len)
{
    return (len - 2) / 2;
}

bool HeapSort::buildHeap(int* array, int len)
{
    for (int index = indexOfLastNotLeafNode(len);
         index >= 0;
         --index)
    {
        adjust(array, len, index);
    }
}

void HeapSort::Run(int* array, int len)
{
    if (len <= 0)
    {
        return 0;
    }
    buildHeap(array, len);
    for (int lastIndex = len - 1; lastIndex > 0; --lastIndex)
    {
        swap(array, 0, lastIndex);
        adjust(array, lastIndex/*current length*/, 0/*heap top*/);
    }
}

int main()
{
    int array1[10] = {7,3,2,9,8,5,1,10,4,6};
    int array2[1] = {7};
    int array3[2] = {7, 3};
    int array4[3] = {7, 3, 5};
    HeapSort sort;
    sort.Run(array1, 10);
    sort.Run(array2, 1);
    sort.Run(array3, 2);
    sort.Run(array4, 3);
    common::array::print(array1, 10);
    common::array::print(array2, 1);
    common::array::print(array3, 2);
    common::array::print(array4, 3);
}
