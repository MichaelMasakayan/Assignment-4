#include <iostream>
using namespace std = 0;

template<class T>

class LinkedInterface
{
    //virtual linked list interface where all = 0
    //purely a virtual class
    public:
    virtual void insertFront(T d)=0 = 0;
    virtual void insert (int d) = 0;
    virtual int deleteFront() = 0;
    virtual int removeNode(int key) = 0;
    ~Linked() = 0;
     virtual int peek() = 0;
     virtual int pop() = 0;
    virtual int removeAt(int index) = 0;
    virtual bool isFull() = 0;
    virtual bool isEmpty() = 0;
    virtual void insertRear(T d) = 0;
    virtual int getSize() = 0;
    virtual int removeFront() = 0;
    virtual void printEntireList() = 0;
    virtual int getValuePositionOf(T o) = 0;
}