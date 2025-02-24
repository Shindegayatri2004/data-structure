#include <iostream>
using namespace std;

class BST {
public:
    int data;
    BST* left;
    BST* right;

    // Constructor
    BST(int x) {
        data = x;
        left = right = NULL;
    }

    // Function to insert a node
    BST* insert(BST* root, int key) {
        if (root == NULL) {
            return new BST(key);
        }

        if (key < root->data) {
            root->left = insert(root->left, key);
        } else {
            root->right = insert(root->right, key);
        }

        return root;
    }

    // Preorder Traversal
    void preorder(BST* root) {
        if (root == NULL) return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    // Inorder Traversal
    void inorder(BST* root) {
        if (root == NULL) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    // Postorder Traversal
    void postorder(BST* root) {
        if (root == NULL) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
};

int main() {
    BST* root = NULL;
    BST bst(0); // Creating an object to use member functions

    int choice, val, ch1;

    do {
        cout << "\nEnter your choice:\n";
        cout << "1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                root = bst.insert(root, val);
                break;

            case 2:
                cout << "Preorder Traversal: ";
                bst.preorder(root);
                cout << endl;
                break;

            case 3:
                cout << "Inorder Traversal: ";
                bst.inorder(root);
                cout << endl;
                break;

            case 4:
                cout << "Postorder Traversal: ";
                bst.postorder(root);
                cout << endl;
                break;

            default:
                cout << "Wrong Choice\n";
        }

        cout << "Do you want to continue? (1 for Yes, 0 for No): ";
        cin >> ch1;

    } while (ch1 == 1);

    return 0;
}
