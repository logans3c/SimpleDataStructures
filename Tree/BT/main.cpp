#include <iostream>
#include <queue>

using namespace std;
template < class Tdata >
class TreeNode
{
public :
    Tdata data;
    TreeNode<Tdata> *right;
    TreeNode<Tdata> *left;

    TreeNode(Tdata _data){
        this -> data = _data;
        this -> right = nullptr;
        this -> left = nullptr;
    }

};

template <class Tdata >
class BinaryTree{


private:
    TreeNode<Tdata> *root;

    int internalHeight (TreeNode<Tdata> *node){
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

    void internalInOrder (TreeNode<Tdata> *node){

        if (node == nullptr){
            return;
        }

        internalInOrder(node -> left);
        cout << node -> data << " --> ";

        internalInOrder(node -> right);


    }

    void internalPostOrder (TreeNode<Tdata> *node){
        if (node == nullptr){
            return;
        }

        internalPostOrder(node -> left);
        internalPostOrder(node -> right);
        cout << node -> data << " --> ";


    }




public:
    BinaryTree(){root = nullptr;}
    ~BinaryTree() {delete root;}

    void Insert (Tdata _data){
        TreeNode<Tdata> *newNode = new TreeNode<Tdata>(_data);

        if (this -> root == nullptr){
            this -> root = newNode;
            return ;
        }

        queue<TreeNode<Tdata>*> queue;
        queue.push(this -> root);
        while (!queue.empty()){
            TreeNode<Tdata> *currentNode = queue.front(); //front() returns the first element in the queue, the first element is the oldest element in the queue
            queue.pop(); // here the first element is deleted from the queue
            if (currentNode -> left == nullptr){
                currentNode -> left = newNode;
                break;
            }
            else {
                queue.push(currentNode -> left);
            }
            if (currentNode -> right == nullptr){
                currentNode -> right = newNode;
                break;
            }
            else {
                queue.push(currentNode -> right);
            }

        }

    }

    int Height (){
        return internalHeight(this -> root);
    }
    /**
     int Height (TreeNode<Tdata> *node){
        if (node == nullptr)
            return 0;
        else {
            int leftHeight = Height(node -> left);
            int rightHeight = Height(node -> right);
            if (leftHeight > rightHeight)
                return leftHeight + 1;
            else
                return rightHeight + 1;

        }
     */

    void PreOrder(){
        return internalPreOrder(this->root);
    }

    void InOrder(){
        return internalInOrder(this -> root);
    }

    void PostOrder(){
        internalPostOrder(this -> root);
    }




};

int main() {
    BinaryTree<char> tree_char;
    tree_char.Insert('A');
    tree_char.Insert('B');
    tree_char.Insert('C');
    tree_char.Insert('D');
    tree_char.Insert('E');
    tree_char.Insert('F');
    tree_char.Insert('G');
    tree_char.Insert('H');
    tree_char.Insert('I');
    cout << tree_char.Height() << endl;
    /* tree_char.PreOrder(); */
    /*tree_char.InOrder();*/
    tree_char.PostOrder();

    return 0;
}
