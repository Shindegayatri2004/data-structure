#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class BT {
public:
    int data;
    BT* left;
    BT* right;

    BT(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

BT* create() {
    int x;
    cout << "Enter the data you want to insert: ";
    cin >> x;
    return new BT(x);
}

void insert(BT* current, BT* newnode) {
    char ch1;
    cout << "\nEnter where do you want to insert (left[l]/right[r]) of " << current->data << " : ";
    cin >> ch1;

    if (ch1 == 'l' || ch1 == 'L') {
        if (current->left == NULL) {
            current->left = newnode;
        } else {
            insert(current->left, newnode);
        }
    } else {
        if (current->right == NULL) {
            current->right = newnode;
        } else {
            insert(current->right, newnode);
        }
    }
}

void preorder(BT* current) {
    if (current == NULL) return;
    cout << current->data << " ";
    preorder(current->left);
    preorder(current->right);
}

void inorder(BT* current) {
    if (current == NULL) return;
    inorder(current->left);
    cout << current->data << " ";
    inorder(current->right);
}

void postorder(BT* current) {
    if (current == NULL) return;
    postorder(current->left);
    postorder(current->right);
    cout << current->data << " ";
}

int total_node(BT* root) {
    if (root == NULL) return 0;
    return 1 + total_node(root->left) + total_node(root->right);
}

void leaf_node(BT* root) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) {
        cout << root->data << " ";
    }
    leaf_node(root->left);
    leaf_node(root->right);
}

int height(BT* root) {
    if (root == NULL) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

bool findAncestors(BT* root, int target) {
    if (root == NULL) return false;
    if (root->data == target) return true;

    if (findAncestors(root->left, target) || findAncestors(root->right, target)) {
        cout << root->data << " ";
        return true;
    }
    return false;
}

void iterativePreorder(BT* root) {
    if (root == NULL) return;
    stack<BT*> s;
    s.push(root);

    while (!s.empty()) {
        BT* current = s.top();
        s.pop();
        cout << current->data << " ";

        if (current->right != NULL) {
            s.push(current->right);
        }
        if (current->left != NULL) {
            s.push(current->left);
        }
    }
}

int main() {
    BT* root = NULL;
    int ch1, ch, val, target;

    do {
        cout << "\nEnter your choice:\n";
        cout << "1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Total Nodes\n6. Leaf Nodes\n7. Height of Tree\n8. Ancestors of a Node\n9. Iterative Preorder Traversal\n";
        cin >> ch;

        switch (ch) {
            case 1:
                if (root == NULL) {
                    cout << "Creating the root node\n";
                    cout << "Enter the root node value: ";
                    cin >> val;
                    root = new BT(val);
                } else {
                    cout << "Inserting a new node:\n";
                    cout << "Enter the value of the new node: ";
                    cin >> val;
                    BT* newnode = new BT(val);
                    insert(root, newnode);
                }
                break;

            case 2:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;

            case 3:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;

            case 4:
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;

            case 5:
                cout << "Total nodes in the tree: " << total_node(root) << endl;
                break;

            case 6:
                cout << "Leaf Nodes: ";
                leaf_node(root);
                cout << endl;
                break;

            case 7:
                cout << "Height of the tree: " << height(root) << endl;
                break;

            case 8:
                cout << "Enter the node value to find ancestors: ";
                cin >> target;
                cout << "Ancestors of " << target << ": ";
                if (!findAncestors(root, target)) {
                    cout << "Node not found\n";
                }
                cout << endl;
                break;

            case 9:
                cout << "Iterative Preorder Traversal: ";
                iterativePreorder(root);
                cout << endl;
                break;

            default:
                cout << "Wrong Choice\n";
        }

        cout << "Do you want to continue? If yes, press 1: ";
        cin >> ch1;

    } while (ch1 == 1);

    return 0;
}

