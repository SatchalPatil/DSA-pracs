#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* insert(node* root, int x) {
    if (root == NULL) {
        root = new node(x);
    }

    if (x <= root->data) {
        root->left = insert(root->left, x);
    } else {
        root->right = insert(root->right, x);
    }
    return root;
}

int height(node* root) {
    if (root == NULL) {
        return 0;
    }
    int ht_left = 1 + height(root->left);
    int ht_right = 1 + height(root->right);
    return max(ht_left, ht_right);
}

void display(node* root) {
    if (root == NULL) {
        return;
    }

    display(root->left);
    cout << root->data << " ";
    display(root->right);
}

int findMin(node* root) {
    if (root == NULL) {
        cout << "Tree is empty" << endl;
        return -1;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

void find(node* root, int key) {
    if (root == NULL) {
        cout << "Value not present" << endl;
        return;
    }

    if (root->data == key) {
        cout << "Value present" << endl;
    } else if (root->data > key) {
        find(root->left, key);
    } else {
        find(root->right, key);
    }
}

void mirror(node* root) {
    if (root == NULL) {
        return;
    }
    mirror(root->left);
    mirror(root->right);
    swap(root->left, root->right);
}

int main() {
    node* root = NULL;
    int n;
    cout << "Enter the number of nodes you want: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int ele;
        cout << "Enter the element to insert in node " << i << ": ";
        cin >> ele;
        root = insert(root, ele);
    }

    cout << "Display elements: ";
    display(root);
    cout << endl;

    cout << "Height of tree: " << height(root) << endl;

    cout << "Minimum value: " << findMin(root) << endl;

    cout << "Swapped: ";
    mirror(root);
    display(root);
    cout << endl;

    int x;
    cout << "Enter the element to search: ";
    cin >> x;
    find(root, x);

    return 0;
}

