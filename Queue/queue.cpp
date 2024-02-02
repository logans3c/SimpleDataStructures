#include <iostream>
#include "signly_linked_List.cpp"
using namespace std;

class Queue {
private:
    linkedList* data_list;
public :
    Queue(){
        this -> data_list = new linkedList();
    }

    void enqueue (int _data) {
        this->data_list->insertLast(_data);
    }

    int dequeue(){ // deletes the head of the list and returns the data of the deleted head
        int head_data = this -> data_list -> head -> data;
        this -> data_list -> deleteHead();
        return head_data;
    }

    int peek(){
        return this -> data_list -> head -> data;
}
    bool isEmpty(){
        if (this -> data_list -> head == NULL)
            return false;
        else{
            return true;
        }

}



};



int main() {
    return 0;
}
