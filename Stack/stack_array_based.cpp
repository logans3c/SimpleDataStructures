//
// Created by moham on 11/8/2023.
//
#include <iostream>
using namespace std;

class stack{
private:
    int* data_list; // the array that will hold the data of the stack
    int initial_size;
    int current_size;
    int top_index; // top_index is the index of the top element in the stack , if there is 5 elements in the stack then the top_index is 4
public:
    stack() {
        this->initial_size = 5;
        this->current_size = initial_size;
        this->data_list = new int[this->initial_size];
        this->top_index = -1; // the logic is that the top index is -1 when the stack is empty
    }

    void resizeOrNot(){
        if (top_index < current_size - 1 ){ //
            return;
        }

        int *newArray = new int [this -> initial_size + this -> current_size]; // create a new array with a bigger size
        this -> current_size += this -> initial_size;
        memcpy(newArray,this -> data_list, sizeof(int)*current_size); // copy the data from the old array to the new array,
        // because the new array is bigger so it can hold the data of the old array,
        // also we copy a number of bytes equal to the size of the new array,
        // this means the copied data will be the data of the old array and the rest of the new array will be filled with garbage values

        delete[] this -> data_list;
        this -> data_list = newArray;

    }

    void push(int _data){
        this -> resizeOrNot();
        this -> data_list[++this->top_index] = _data; // increment the top index and then add the data to the new top index
    }

    int peek(){
        if (this -> top_index == -1){
            return 0  ;
        }
        return this -> data_list[this -> top_index];
    }

    int pop(){
//        cout << "\ntop index before pop : "<< this -> top_index << endl;
        int head_data = this -> data_list[this -> top_index];
        this -> data_list[this -> top_index] = 0 ;
        this -> top_index-- ;
//        cout << "\ntop index after pop : "<< this -> top_index << endl;

        return head_data; // return the data of the deleted top element
    }

    bool isEmpty () {
        if (this -> top_index < 0) { //
            return true;
        }
        else{
            return false;
        }

    }
    int size(){
        return this -> top_index +1 ;
    }

    void print(){
        for(int i = 0 ; i < top_index +1 ; i++){
            cout << this -> data_list[i] << "  " ;
        }
    }



};


int main(){

    stack* s = new stack();
    s -> push(1);
    s -> push(2);
    s -> push(3);
    s -> push(4);
    s -> push(5);
    s -> push(6);
    s -> push(7);
    s -> push(8);
    //s -> pop();
    s -> print();
//    cout << " \npeek is : " << s -> peek();
//    cout << " \nis empty : " << s -> isEmpty();

    return 0;
}