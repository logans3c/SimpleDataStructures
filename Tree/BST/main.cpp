#include <iostream>
#include <queue>
using namespace std;


template< class Tdata >
class TreeNode{
public:
    Tdata subject;
    TreeNode<Tdata> *right;
    TreeNode<Tdata> *left;

    TreeNode(Tdata _data){
        this->subject = _data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

template < class Tdata >
class BST{
private:
    int internalHeight(TreeNode<Tdata> *node){
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
        cout << node -> subject << " --> " ;
        internalPreOrder(node -> left);
        internalPreOrder(node -> right);
    }

    void internalInOrder (TreeNode<Tdata> *node) {
        if (node == nullptr) {
            return;
        }
        internalInOrder(node->left);
        cout << node->subject << " --> ";
        internalInOrder(node->right);
    }

    void internalPostOrder(TreeNode<Tdata> *node){
        if(node == nullptr){
            return;
        }
        internalPostOrder(node -> left);
        internalPostOrder(node -> right);
        cout << node -> subject << " --> " ;
    }

public:
    TreeNode<Tdata> *root;

    BST(){this->root = nullptr;}
    ~BST(){delete root;}

    TreeNode<Tdata>* insert_subject (Tdata _subject){
        TreeNode<Tdata> *newNode = new TreeNode<Tdata>(_subject);

        if (this->root == nullptr){
            this->root = newNode;
            return newNode;
        }

        TreeNode<Tdata> *currentNode = this->root;

        while(currentNode != nullptr){
            if (newNode->subject < currentNode->subject){
                if (currentNode->left == nullptr){
                    currentNode->left = newNode;
                    break;
                }
                else{
                    currentNode = currentNode->left;
                }
            }
            else if (newNode->subject > currentNode->subject){
                if (currentNode->right == nullptr){
                    currentNode->right = newNode;
                    break;
                }
                else{
                    currentNode = currentNode->right;
                }
            }
            else{
                break;
            }
        }
        return newNode;
    }

    TreeNode<Tdata> *find(Tdata _data){
        TreeNode <Tdata> *currentNode = this ->root;

        while(currentNode != nullptr){
            if (_data == currentNode -> subject){
                return currentNode;
            }
            else if (_data < currentNode -> subject){
                currentNode = currentNode -> left;
            }
            else if(_data > currentNode -> subject){
                currentNode = currentNode -> right;
            }
        }
        return nullptr;
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

    bool isExist(Tdata _data){
        TreeNode<Tdata> *currentNode = this->root;
        while (currentNode != nullptr) {
            if (currentNode->subject == _data) {
                return true;
            } else if (currentNode->subject > _data) {
                currentNode = currentNode->left;
            } else {
                currentNode = currentNode->right;
            }
        }
        return false;
    }

    void Remove(Tdata _subject){
        TreeNode<Tdata> *currentNode = this->root;
        TreeNode<Tdata> *parent = nullptr;
        bool isLeft = false;

        while (currentNode != nullptr) {
            if (currentNode->subject == _subject) {
                break;
            } else if (currentNode->subject > _subject) {
                parent = currentNode;
                currentNode = currentNode->left;
                isLeft = true;
            } else {
                parent = currentNode;
                currentNode = currentNode->right;
                isLeft = false;
            }
        }

        if (currentNode == nullptr) {
            cout << "Not Found" << endl;
            return;
        }

        if (currentNode->left == nullptr && currentNode->right == nullptr) {
            if (parent == nullptr) {
                this->root = nullptr;
            } else {
                if (isLeft) {
                    parent->left = nullptr;
                } else {
                    parent->right = nullptr;
                }
            }
        } else if (currentNode->left != nullptr && currentNode->right != nullptr) {
            TreeNode<Tdata> *minRight = currentNode->right;
            TreeNode<Tdata> *parentMinRight = currentNode;
            while (minRight->left != nullptr) {
                parentMinRight = minRight;
                minRight = minRight->left;
            }
            currentNode->subject = minRight->subject;
            if (parentMinRight == currentNode) {
                currentNode->right = minRight->right;
            } else {
                parentMinRight->left = minRight->right;
            }
        } else {
            TreeNode<Tdata> *child = nullptr;
            if (currentNode->left != nullptr) {
                child = currentNode->left;
            } else {
                child = currentNode->right;
            }
            if (parent == nullptr) {
                this->root = child;
            } else {
                if (isLeft) {
                    parent->left = child;
                } else {
                    parent->right = child;
                }
            }
        }
    }

    int height(TreeNode<Tdata>* node) {
        if (node == nullptr) return 0;
        else {
            return 1 + max(height(node->left), height(node->right));
        }
    }

    int getBalanceFactor(TreeNode<Tdata>* node) {
        if (node == nullptr) return 0;
        else {
            return height(node->left) - height(node->right);
        }
    }

    TreeNode<Tdata>* rightRotate(TreeNode<Tdata>* x) {
        TreeNode<Tdata>* y = x->left;
        TreeNode<Tdata>* T2 = y->right;

        y->right = x;
        x->left = T2;
        return y;
    }

    TreeNode<Tdata>* leftRotate(TreeNode<Tdata>* x) {
        TreeNode<Tdata> *y = x->right;
        TreeNode<Tdata> *T2 = y->left;

        y->left = x;
        x->right = T2;
        return y;
    }

    TreeNode<Tdata>* balanceBst(TreeNode<Tdata>* node) {
        if (node == nullptr) return nullptr;
        node->left = balanceBst(node->left);
        node->right = balanceBst(node->right);
        int balanceFactor = getBalanceFactor(node);
        if (balanceFactor > 1) {
            if (getBalanceFactor(node->left) >= 0) {
                node = rightRotate(node);
            } else {
                node->left = leftRotate(node->left);
                node = rightRotate(node);
            }
        } else if (balanceFactor < -1) {
            if (getBalanceFactor(node->right) <= 0) {
                node = leftRotate(node);
            } else {
                node->right = rightRotate(node->right);
                node = leftRotate(node);
            }
        }
        return node;
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
