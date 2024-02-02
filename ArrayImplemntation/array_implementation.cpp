//
// Created by moham on 10/19/2023.
//
#include <iostream>
#include <cstring>
using namespace std;
template<class T>

class ourArray {
    T *sourceArray;

public :
    int numOfElements;
    int capacity;

    ourArray() {
        capacity = 10;
        numOfElements = 0;
        sourceArray = new T [capacity];
    }

    void resize(T *& sourceArray,int newSize){
        this -> capacity = sizeof(T) * newSize;
        if (newSize <= 0)
            return;
        if (sourceArray == nullptr)
            return;
        if (newSize == static_cast<int>(sizeof(sourceArray)))
            return;
        T* newArray = new T [newSize];
        memcpy(newArray,sourceArray,capacity );
        delete[] sourceArray; // we deleted the block of memory that the pointer was pointing to
        sourceArray = newArray; // // we made the pointer point to the new block of memory

}

     void add (T *&sourceArray , T val){
        if (numOfElements == capacity){
            resize(sourceArray,capacity);
        }
        sourceArray[numOfElements++] = val;

}
    void deleteAT (T *&sourceArray , int index){
        for (int i = index ; i < capacity - 1 ; i++){
            sourceArray[i] = sourceArray[i+1];
        }
    }
    T getAt (T *&sourceArray ,int index){
        if (index < 0){
            return T();
        }
        return *(sourceArray + index);
    }
};



int main (){
    int *arr = new int [10];
    ourArray<int> our;

    our.add(arr,1);
    our.add(arr,2);
    our.add(arr,3);
    our.add(arr,4);
    our.add(arr,5);
    our.add(arr,6);
    our.add(arr,7);
    our.add(arr,8);
    our.add(arr,9);
    our.deleteAT(arr,1);



    // ADD VALUES TO THE ARRAY
    for(int i = 0 ; i < our.capacity ; i++){
        cout << arr[i] << endl;
    }
    cout << " real-time array capacity : " << our.capacity << endl;
    cout << " getAt function result :  " << our.getAt(arr,3) << endl;

    return 0;

}
