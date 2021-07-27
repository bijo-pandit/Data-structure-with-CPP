#include<stdlib.h>
#include<iostream>
using namespace std;
class ArrayList
{
    private:
        int capacity;
        int lastIndex;
        int *arr_ptr;
    public:
        ArrayList()
        {
            capacity =0;
            lastIndex=-1;
            arr_ptr=NULL;
        }

        ~ArrayList()
        {
            delete []arr_ptr;
            arr_ptr=NULL;
        }
        void createArray(int);
        void append(int);
        void insertAt(int,int);
        void removeFrom(int);
        void removeFront();
        void removeLast();
        void release();
        int countItems();
        int frontItem();
        int lastItem();
        void viewList();
};

void ArrayList::createArray(int capacity)
{
    this->capacity = capacity;
    arr_ptr =new int[capacity];
}

void ArrayList::append(int data)
{
    if(lastIndex==capacity-1)
        cout<<" Overflow ";
    else
    {
        lastIndex+=1;
        arr_ptr[lastIndex] = data;
    }
}

void ArrayList::insertAt(int index_location, int data)
{
    if(lastIndex==capacity-1)
        cout<<" Overflow ";
    else if(index_location>-1 && index_location<=lastIndex+1)
    {
        for(int idx=lastIndex+1; idx>index_location; --idx)
            arr_ptr[idx]=arr_ptr[idx-1];
        arr_ptr[index_location]=data;
        lastIndex+=1;
    }   
    else 
        cout<<" Invalid index ";
}

void ArrayList::removeFrom(int index_location)
{
    if(lastIndex==-1)
        cout<<" Underflow ";
    else if(index_location>-1 && index_location<=lastIndex)
    {
        for(int idx=index_location; idx<lastIndex; ++idx)
            arr_ptr[idx]=arr_ptr[idx+1];
        lastIndex-=1;
    }
    else
        cout<<" Invalid index ";
}

void ArrayList::removeFront()
{
    if(lastIndex>-1)
    {
        for(int idx=0; idx<lastIndex; ++idx)
            arr_ptr[idx]=arr_ptr[idx+1];
        lastIndex-=1;
    }
}

void ArrayList::removeLast()
{
    if(lastIndex>-1)
        lastIndex-=1;
}

void ArrayList::release()
{
    capacity=0;
    lastIndex=-1;
    delete []arr_ptr;
    arr_ptr=NULL;
}

int ArrayList::countItems()
{
    return lastIndex+1;
}

int ArrayList::frontItem()
{
    if(lastIndex>-1)
        return arr_ptr[0];
    return lastIndex;   //lastIndex is -1
}

int ArrayList::lastItem()
{
    if(lastIndex>-1)
        return arr_ptr[lastIndex];
    return lastIndex;   //lastIndex is -1
}

void ArrayList::viewList()
{
    if(lastIndex>-1)
        for(int idx=0; idx<=lastIndex; ++idx)
            cout<<" "<<arr_ptr[idx];
    else
        cout<<" Underflow ";
}

int main(int argc, char const *argv[])
{
    ArrayList arr;
    arr.createArray(5);
    arr.append(49);
    arr.append(48);
    arr.insertAt(0,60);
    arr.insertAt(3,10);
    arr.viewList();
    return 0;
}
