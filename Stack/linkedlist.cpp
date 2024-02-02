//
// Created by mohammed on 10/23/2023.
//
#include <iostream>

using namespace std;

class linkedListNode {
public:
    /* data members */
    int data;
    linkedListNode* next;   // we will use next as a pointer to the next node so it must be the same data_type as each node

    /* constructor */
    linkedListNode(int _data){
        this -> data = _data;
        this -> next = nullptr;
    }
};


class linkedListIterator {
public :
    linkedListNode* currentNode;
    linkedListIterator() { currentNode = NULL;}
    linkedListIterator(linkedListNode* node){ currentNode = node;}


    int data () {return currentNode -> data;}


    linkedListIterator next(){ // this function designed to move the iterator to the next node, the return type is linkedListIterator because we want to return the current node after moving it to the next node
        currentNode = currentNode -> next;
        return *this; //"this" is a pointer to the current object , *this is the current object, returning the curren object means returning the current node
    }

    linkedListNode* current () {return currentNode;}

};


class linkedList {
private :
    int length;
public:
    linkedListNode* head = nullptr;
    linkedListNode* tail = nullptr;

    int Length() {return this -> length;}

    void addHead (linkedListNode* node){
        this -> head = node;
        this -> tail = node;

    }


    linkedListIterator begin(){
        linkedListIterator itr (head); //that will make "currentNode" in the iterator class points to the first node "head"
        return itr; // return the iterator that points to the first node "head"
    }



    linkedListNode* find(int _data) {

        for (linkedListIterator itr = this->begin(); itr.current() != nullptr ; itr . next()) {

            if (itr .data() == _data){
                return itr.current();
            }

        }

        return nullptr;
    }


    linkedListNode* findParent(int _data){

        for (linkedListIterator itr = this -> begin(); itr.current() != NULL ; itr.next()){
            if (itr.current()->next && itr.current() -> next -> data == _data){
                return itr.current() ;
            }
        }
        return nullptr;

    }


    void printList(){
        for (linkedListIterator itr = this -> begin() ; itr.current() != NULL ; itr.next()){
            cout << itr.data() << " --> ";

        }
        cout << "\n";

    }

    void insertFirst (int _data){

        linkedListNode* newNode = new linkedListNode(_data);

        if (this -> head == nullptr){
            this -> head = newNode ;
            this -> tail = newNode;
        }
        else {
            newNode -> next = head ; // head was pointing to the first node , now the new node is pointing to the previous first node
            head = newNode;
        }



        this -> length++;
    }


    void insertLast(int _data){
        linkedListNode *newNode = new linkedListNode(_data); // "new" operator calls the constructor by default

        if (head == nullptr){
            this -> head = newNode;
            this -> tail = newNode;
        }
        else {

            this -> tail -> next = newNode;
            this -> tail = newNode;
        }
        this -> length++; // to count the number of nodes in the linked list

    }



    void insertAfter (linkedListNode* node, int _data){ // the node parameter is the data of the node that we want to insert after it.
        linkedListNode* newNode = new linkedListNode (_data);

        newNode -> next  = node -> next;
        node -> next = newNode;

        if (newNode -> next == NULL || this -> tail == node ){
            this -> tail = newNode;
        }
        this -> length++;

    }

    void insertBefore(linkedListNode* node , int _data){
        linkedListNode* newNode = new linkedListNode(_data);

        newNode -> next = findParent(node->data) -> next;
        findParent(node->data) -> next = newNode;
        this -> length++;

    }


    void deleteNode (linkedListNode* node){
        if (this -> head == this -> tail){
            this -> head = nullptr;
            this -> tail = nullptr;
        }
        else if (this->head == node ){
            this -> head = node -> next;
        }
        else {
            if (this-> tail == node){
                this -> tail = findParent(node -> data);
            } // means if the user want to delete the last node
            findParent(node->data)->next = node -> next;

        }
        delete node;
        this -> length--;

    }


    void deleteNode (int _data){ //delete node by data
        if (find(_data) == NULL){
            return;

        }
        this ->deleteNode(find(_data));



    }

    void deleteHead (){
        if (this -> head == nullptr){
            return;
        }
        else{
            linkedListNode* temp = this -> head;
            this -> head = this -> head -> next;
            delete temp;
            this -> length--;

        }

    }






};

