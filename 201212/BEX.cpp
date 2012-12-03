//维护堆算法
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>

using namespace std;

const long maxn = 1000005;
typedef struct BOOK
{
    long ans;
    long index;
    long exercises;
    string name;
}Book;
Book bookHeap[maxn];
long heapSize;

void MinHeapFixup();
void MinHeapFixdown(long);

void output()
{
    for (long i = 0; i < heapSize; ++i)
    {
        cout<<bookHeap[i].index<<" "<<bookHeap[i].exercises<<" "<<bookHeap[i].name<<endl;
    }
}

//<0 
inline int Compare(long first, long second)
{
    if (bookHeap[first].exercises > bookHeap[second].exercises)
    {
        return 1;
    }
    else if(bookHeap[ first ].exercises < bookHeap[ second ].exercises)
    {
        return -1;
    }

    if (bookHeap[first].index < bookHeap[second].index)
    {
        return 1;
    }

    return -1;
}

void MinHeapAddElement(long index, long exercises, string bookName)
{
    Book newbook;
    newbook.index = index;
    newbook.ans = 0;
    newbook.exercises = exercises;
    newbook.name = bookName;
    bookHeap[heapSize] = newbook;
    ++heapSize;
    
    MinHeapFixup();
}

void MinHeapPopTopElement()
{
    if (heapSize <= 0)
        return;

    bookHeap[0] = bookHeap[heapSize - 1];
    --heapSize;
    MinHeapFixdown(0);
}

void MinHeapRemoveElement(long index)
{
    if (heapSize <= 0)
        return;

    bookHeap[index] = bookHeap[heapSize - 1];
    --heapSize;
    //MinHeapFixdown(index);
}

void MinHeapFixup()
{
    if (heapSize <= 1)
        return;

    long curIndex = heapSize - 1;
    long temp = heapSize;
    bookHeap[temp] = bookHeap[curIndex];
    long parentIndex = (curIndex-1)/2;

    while (parentIndex >= 0 && curIndex != 0)
    {
        if (Compare(parentIndex, temp) < 0)
        {
            break;
        }

        bookHeap[curIndex] = bookHeap[parentIndex];
        curIndex = parentIndex;
        parentIndex = (curIndex-1)/2;
    }

    bookHeap[curIndex] = bookHeap[temp];
    //output();
}

void MinHeapFixdown(long parentIndex)
{
    if (parentIndex < 0)
        return;
 
    long temp = heapSize;
    bookHeap[temp] = bookHeap[parentIndex];
    long leftChildIndex = 2*parentIndex + 1;
    long replaceIndex = leftChildIndex;
   
   while(replaceIndex < heapSize)
   {
       long rightChildIndex = leftChildIndex + 1; 
       if (rightChildIndex < heapSize && Compare(rightChildIndex, leftChildIndex) < 0)
       {
            replaceIndex = rightChildIndex;
       }

       if (Compare(temp, replaceIndex) < 0)
       {
            break;
       }

       bookHeap[parentIndex] = bookHeap[replaceIndex];
       parentIndex = replaceIndex;
       leftChildIndex = 2*parentIndex + 1;
       replaceIndex = leftChildIndex;
   }

   bookHeap[parentIndex] = bookHeap[temp];
}

void MakeMinHeap(long rem)
{
    //The number of internal nodes (non-leaf nodes) in a Complete Binary Tree of n nodes is floor(n/2)
    for (int index = heapSize/2 - 1/*minus 1 because index from 0*/; index>=rem; --index)
    {
        MinHeapFixdown(index);
    }
}

int main()
{
    long N;
    cin>>N;
    string bookName;
    long exercises;
    heapSize = 0;

    long index = 1;

    while (N--)
    {
        cin>>exercises;
        if (-1 == exercises)
        {
            cout<<bookHeap[0].ans<<" "<<bookHeap[0].name<<endl;
            MinHeapPopTopElement();

            index = heapSize+1;
        }
        else
        {
            cin>>bookName;
            //index, exercises, bookName.
            if (exercises > 0)
            {
                if (heapSize <= 0)
                {
                    MinHeapAddElement(index, exercises, bookName);
                    ++index;
                }
                else
                {
                    long tempE = bookHeap[0].exercises;
                    if (exercises > tempE)
                    {
                        ++bookHeap[0].ans;
                    }
                    else
                    {
                        MinHeapAddElement(index, exercises, bookName);
                        ++index;
                    }
                }
            }
        }
    }

    return 0;
}

