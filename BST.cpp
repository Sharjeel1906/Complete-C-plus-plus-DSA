#include <iostream>

using namespace std;

class Node{
public:
   int data;
   Node* left;
   Node* right;
   Node(int val){
    data = val;
    left = right = NULL;
   }
};

Node* insert(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val < root->data){
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

Node* buildBst(int arr[], int n) {
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    return root;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool search(Node* root, int key){
    if(root == NULL){
        return false;
    }
    if(root->data == key){
        return true;
    }
    if(key < root->data){
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// inorder successor = Left most node in right subtree
// inorder successor has at most one child

Node* inordersuccessor(Node* root){
    while (root != NULL && root->left != NULL){
        root = root->left;
    }
    return root;
}

Node* Delete(Node* root, int key){
    if(root == NULL){
        return NULL;
    } else if(root->data > key){
        root->left = Delete(root->left, key);
    } else if(root->data < key){
        root->right = Delete(root->right, key);
    } else {
        // Node to be deleted found
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        } else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* in_succ = inordersuccessor(root->right);
            root->data = in_succ->data;
            root->right = Delete(root->right, in_succ->data);
        }
        return root;
    }
    return root;
}

int main(){
    int insertCount = 7; 
    int insertArr[] = {5, 3, 7, 2, 4, 6, 8};
    Node* root = buildBst(insertArr, insertCount);

    cout << "BST Inorder after insertion: ";
    inorder(root);
    cout << endl;

    int searchVal = 6;
    cout << "Search " << searchVal << ": " << (search(root, searchVal) ? "Found" : "Not Found") << endl;

    int deleteVal = 3;
    root = Delete(root, deleteVal);

    cout << "BST Inorder after deleting " << deleteVal << ": ";
    inorder(root);
    cout << endl;
}