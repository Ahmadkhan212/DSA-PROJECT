
#include <iostream>
using namespace std;

struct node {
    int data;
    node *left;
    node *right;

    node(int val) {
        data = val;
        left = right = NULL;
    }
};

bool find(node *root, int target, int &k, int &ancestor) {
    if (root == NULL) {
        return false;
    }

    if (root->data == target) {
        return true; 
    }

    if (find(root->left, target, k, ancestor) || find(root->right, target, k, ancestor)) {
        k--; 

        if (k == 0) {
            ancestor = root->data; 
            return false; 
        }

        return true; 
    }

    return false;
}

int findk(node *root, int k, int target) {
    int ancestor = -1; 
    find(root, target, k, ancestor);
    return ancestor;
}

int main() {
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->left->left = new node(8);
    root->left->left->right = new node(18);

    
    cout << findk(root, 2, 18) << endl; 

}
