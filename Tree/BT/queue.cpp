#include "signly_linked_List.cpp"
using namespace std;

template <class T>
class Queue {
private:
    linkedList* data_list;
public :
    Queue(){
        this -> data_list = new linkedList();
    }

    void enqueue (T _data) {
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
        if (this -> data_list -> head == nullptr)
            return true;
        else{
            return false;
        }

}



};
