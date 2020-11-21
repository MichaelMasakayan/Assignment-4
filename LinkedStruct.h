
#ifndef _LINKEDSTRUCT_H_
#define _LINKEDSTRUCT_H_
#include <iostream>
#include <fstream>
#include <math.h>
#include <time.h>
#include <string>
using namespace std;

template <class T>
class Que
{
    public:
    Que();
    Que(int o);
    ~Que();
    int data;
    void iterateByOne();
    int timeInQue();
    Que *rear;
    Que *front;
    Que *next;
    Que *prev;
    void printEntireRegistrar();

    private:
    
 };
template <class T>
Que<T>::Que()
{
    rear = nullptr;
    front = nullptr;
    data = 0;
}
template <class T>
Que<T>::Que(int o)
{
    
    rear = nullptr;
    front = nullptr;
    data = o;
}
template <class T>
Que<T>::~Que()
{

}

template <class T>
class Linked
{
  
    public: 

    void insert (int d);
    int deleteFront();
    T dequeue();
    int removeNode(int key);
    ~Linked();
    int peek();
    int pop();
    int timeInQue();
    int removeAt(int index);
    bool isFull();
    bool isEmpty();
    void insertRear(T d);
    int getSize();
    int size;
    void printEntireList();
    int getValuePositionOf(T o);
    Linked();
    Linked(T n);
    int numElements;
    T *myStack;
    T getFront();
    void insertToQue(T j);
    private:
    T data;
    Que<T> *front; 
     Que<T> *rear;
    // Que<T> *next;
    // Que<T> *prev;

 };
template<class T>
Linked<T>::Linked()
{
    // prev=nullptr;
    front=nullptr;
    // next=nullptr;
    rear=nullptr;
    size = 0;
}
template<class T>
//compiler from class notes
Linked<T>::Linked(T n)
{
    data=n;
    next= nullptr;
    prev=nullptr;

}
template<class T>
//compiler from class notes
T Linked<T>::getFront()
{
  return front->data;
}
template<class T>
Linked<T>::~Linked()
{

}
template<class T>
//code is taken and adapted from linked.cpp insertRear() same idea
void Linked<T>::insertToQue(T j)
{
    
    Que<T> *temp = new Que<T>(j);
    if(isEmpty() == true)
    {
        front = temp;
    }
    else
    {
        {
            rear->next= temp;
            temp->prev= rear;
        }
    }
    rear = temp; 
    size++;


}
template<class T>
// from inclass exampled for Genstack
void Linked<T>::insert(int d) {
    // make sure is not full before proceeding
    myStack [rear++] = d;
    rear = (rear) % size;
    numElements++;
}
template<class T>
//is the same as linked listed delteFront() function it will return the time in que for the first person
int Linked<T>::timeInQue()
{
    int throwaway = front ->data;
    Que<T> *Temp =front;
      //firstly checks if the whole thing is empty
    if(isEmpty() == true)
    {
        front = nullptr;
    }
    else
    {
        front->prev=nullptr;
        front = front->next;
    }   
    Temp->next = nullptr;
    Temp->prev = nullptr;
    delete Temp;
    size--;
    return throwaway;
}   
template<class T>
int Linked<T>::peek() {
    return myStack [front];
}
 template<class T>
bool Linked<T>::isFull() {
    return (numElements == size);
}
template<class T>
bool Linked<T>::isEmpty() {
    return size == 0;
}
//adapted from insertBack() talked about in class
template<class T>
void Linked<T>::insertRear(T d) 
{
    Que<T> *node = new Que<T>(d);
    if (size == 0)
    {
      
        front = node;
    }
    else
    {
       
        node-> prev = rear;
         rear->next=node;

    }
    rear = node;
      size++;
    
}

template<class T>
int Linked<T>::getSize() {
    return size;
}
template<class T>
int Linked<T>::pop() {
    if(!isEmpty())
    {
        front--;
        T t = myStack[front];
        
        return t;
    }
    else
    {
        {
           
            return 0;
        }
    }


    if(!isEmpty())
    front--;
    return myStack[front];
}
template<class T>
int Linked<T>::deleteFront()
{
    
     Que<T> *Temp = front;
    T throwaway = front -> data;
   
    //firstly checks if the whole thing is empty
    
    if(getSize() >1 )
    {
       
         front = front->next;
        front->prev=nullptr;
    }
    else
    {
       
        front=nullptr;
        
    }   
    Temp->next = nullptr;
    Temp->prev = nullptr;
    delete Temp;
    size--;
  
    return throwaway;

   
}
//remove node from class example for genstack
template<class T>
int Linked<T>::removeNode(int key) {
//make sure list is not empty
Linked<T> *curr = front;
//let’s attempt to find the node containing the key/value
    while (curr->data != key) {
    curr = curr->next;
    if (curr == NULL)
        return -1;
        }

    if (curr == front) {
    deleteFront();
    
    }
    else if (curr == rear) 
    {
        rear =curr->prev;
        rear->next = NULL;
    }
    else
    {
        curr->next->prev = curr->next;
        curr->prev->next = curr->next;
    }
    curr->next = NULL;
    curr->prev = NULL;
    int temp = curr->data;
    size--;
    delete curr;
    return temp;
}
template<class T>
void Linked<T>::printEntireList()
{
    Que<int> *currentN = front;


    for(int i = 0; i<size;i++)
    {
        cout<<"at "<< i << ": "<< currentN->data <<endl;
    }
  

}
//adapted from searchNode class example when talking about BST
template<class T>
int Linked<T>::getValuePositionOf(T o)
{
    //starting at the front node
    Linked<T> *curr = front;
    int pos = -1;
    if(isEmpty())
    {
        return -1;
    }
    else
    {
        while(curr->key!= o)
        {
            pos++;
            if(curr->data != o)
            {
                curr= curr->next;
            }
            else
            {
                return pos;
            }
            
        }
    }
    //for debug
    return -2;
}
template<class T>
T Linked<T>:: dequeue()
{
       
   return myStack.deleteFront();
}
template<class T>
class GeneralQueue
{
    public:
    GeneralQueue(int s);
    GeneralQueue();
    ~GeneralQueue();
    void enqueue(T o);
    bool isEmpty();
    int getSizes();
    int timeInQ();
    void printEntire();
    T dequeue();
    int sizeOfQueue;
    T peek();
    Linked<T> myStack;
    T backs();
    private: 

};
template<class T>
GeneralQueue<T>::GeneralQueue()
{

sizeOfQueue = 0;
     Linked<T> myQ = Linked<T>();
}
template<class T>
GeneralQueue<T>::GeneralQueue(int s)
{

sizeOfQueue = s;
     Linked<T> myQ = Linked<T>();
}
template<class T>
GeneralQueue<T>::~GeneralQueue()
{

}
template<class T>
int GeneralQueue<T>::getSizes()
{

 return myStack.getSize();

}
template<class T>
void GeneralQueue<T>::enqueue(T o)
{
  
 myStack.insertRear(o);

}
template<class T>
int GeneralQueue<T>::timeInQ()
{
 return myStack.timeInQue();
}
template<class T>
T GeneralQueue<T>::dequeue()
{
   
return myStack.deleteFront();
}
template<class T>
T GeneralQueue<T>::peek()
{
 return myStack.getFront();
}
template<class T>
 bool GeneralQueue<T>::isEmpty()
{

 return myStack.isEmpty();
}
template<class T>
void GeneralQueue<T>::printEntire()
{
myStack.printEntireList();

}

  
#endif