#include <iostream>
#include <queue>
using namespace std;

template< class Tdata >
class TreeNode{
public:
    Tdata data;
    TreeNode<Tdata> *right;
    TreeNode<Tdata> *left;

    TreeNode(Tdata _data){
        this->data = _data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

template < class Tdata >
class BST{

private:
    internalHeight(TreeNode<Tdata> *node){
        if (node == nullptr)
            return 0;
        else {
            return 1 + max(internalHeight(node -> left), internalHeight(node -> right));

        }
    }

    void internalPreOrder(TreeNode<Tdata> *node){
        if(node == nullptr){
            return;
        }
        cout << node -> data << " --> " ;

        internalPreOrder(node -> left);
        internalPreOrder(node -> right);

    }

    void internalInOrder (TreeNode<Tdata> *node) {

        if (node == nullptr) {
            return;
        }

        internalInOrder(node->left);
        cout << node->data << " --> ";

        internalInOrder(node->right);
    }

    void internalPostOrder(TreeNode<Tdata> *node){
        if(node == nullptr){
            return;
        }
        internalPostOrder(node -> left);
        internalPostOrder(node -> right);
        cout << node -> data << " --> " ;
    }

    void internalPrint(TreeNode<Tdata> *node){
        if(node == nullptr){
            return;
        }
        internalPrint(node -> left);
        cout << node -> data << " --> " ;
        internalPrint(node -> right);
    }





public:
    TreeNode<Tdata> *root;

    BST(){this->root = nullptr;}
    ~BST(){delete root;}

    void iterative_insert(Tdata _data){
        /*without queue*/

        TreeNode<Tdata> *newNode = new TreeNode<Tdata>(_data);
        if (this->root == nullptr){
            this -> root = newNode;
            return;
        }

        TreeNode<Tdata> *currentNode = this -> root;

        while(currentNode != nullptr){

            if(newNode->data < currentNode -> data){
                if(currentNode->left == nullptr){
                    currentNode -> left = newNode;
                    break;
                }
                else {
                    currentNode = currentNode -> left;

                }
            }
            else{
                if (currentNode -> right == nullptr) {
                    currentNode->right = newNode;
                    break;
                }
                else{
                    currentNode = currentNode -> right;
                }
            }
        }




    }

    void queue_insert (Tdata data) {
        /*insert with the help of queue*/

        TreeNode<Tdata> *newNode = new TreeNode<Tdata>(data);

        if (this->root == nullptr) {
            this->root = newNode;
            return;
        }

        queue<TreeNode<Tdata> *> queue;
        queue.push(this->root);
        while (!queue.empty()) {
            TreeNode<Tdata> *currentNode = queue.front();
            queue.pop();
            if (currentNode->Left == nullptr) {
                currentNode->Left = newNode;
                break;
            } else {
                queue.push(currentNode->Left);
            }

            if (currentNode->Right == nullptr) {
                currentNode->Right = newNode;
                break;
            } else {
                queue.push(currentNode->Right);
            }
        }
    }

    TreeNode<Tdata> find(Tdata _data){

        TreeNode <Tdata> *currentNode = this ->root;

        while(currentNode != nullptr){
            if (_data == currentNode -> data){
                return currentNode;
            }
            else if (_data < currentNode -> data){
                currentNode = currentNode -> left;

            }
            else if(_data > currentNode -> data){
                currentNode = currentNode -> right;
            }


        }
        return nullptr;
    }

    /**
        * @brief This function is used to find the parent of a node
        * @param _data
        * @return
        */
    void delete_leaf(Tdata _data) {

        TreeNode<Tdata> * currentNode = this->root;
        TreeNode<Tdata> * parent = nullptr;


        while (currentNode != nullptr) {
            if (_data == currentNode->data && (currentNode->left == nullptr && currentNode->right == nullptr)) {
                    if (parent -> right -> data != currentNode -> data){
                        //delete currentNode;
                        parent -> left = nullptr;
                        break;

                }
                    else{
                        //delete currentNode;
                        parent -> right = nullptr;
                        break;
                    }
            }

            if(currentNode -> data < _data){
                parent = currentNode;
                currentNode = currentNode -> right;
            }
            else if (_data > currentNode -> data){
                parent = currentNode;
                currentNode = currentNode -> right;
            }

        }
    }




    void delete_one_child(Tdata _data) {
        TreeNode<Tdata> * currentNode = this->root;
        TreeNode<Tdata> * parent = nullptr;

        if (_data == this->root->data) {
            if (this->root->left != nullptr) {
                this->root = this->root->left;
            } else {
                this->root = this->root->right;
            }
            delete currentNode;
            return;
        }

        while (currentNode != nullptr) {
            if ((currentNode->left == nullptr) ^ (currentNode->right == nullptr) && currentNode->data == _data) {}
        }
    }


    void delete_two_childs(Tdata _data){
        TreeNode<Tdata> *currentNode = this -> root;
        TreeNode<Tdata> *parent =nullptr ;
        TreeNode<Tdata> *minRight =nullptr ;



        while(currentNode != nullptr){
            if ((currentNode -> left != nullptr && currentNode -> right != nullptr) && currentNode -> data == _data){

                

                }
            }

    }

    int height(){
        return internalHeight(this->root);
    }

    void PreOrder(){
        internalPreOrder(this->root);
    }

    void InOrder(){
        internalInOrder(this->root);
    }

    void PostOrder(){
        internalPostOrder(this->root);
    }

    void Print(){
        internalPrint(this->root);
    }

    void delete_data(Tdata _data){
       //delete_two_childs(_data);
       //delete_one_child(_data);
        delete_leaf(_data);

    }




};







int main() {
    BST<int> tree_int;

    tree_int.iterative_insert(1);
    tree_int.iterative_insert(8);
    tree_int.iterative_insert(2);
    tree_int.iterative_insert(9);
    tree_int.iterative_insert(6);
    tree_int.iterative_insert(5);
    tree_int.iterative_insert(7);
    tree_int.iterative_insert(3);
    tree_int.delete_data(7);
    tree_int.PostOrder();

    return 0;
}
