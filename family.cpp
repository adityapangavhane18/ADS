#include<iostream>
#include<string>
using namespace std;

struct node {
    string name, relation;
    node *right;
    node *left;
};

node *getnode() {
    node *temp;
    temp = new node;
    cout << "Enter the name of the family member :";
    cin >> temp->name;
    cout << "Enter the relation :";
    cin >> temp->relation;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

node *create() {
    node *temp, *ptr, *root = NULL;
    char dir;
    int ch;
    do {
        temp = getnode();
        if (root == NULL) {
            root = temp;
        } else {
            ptr = root;
            while (ptr != NULL) {
                cout << "Enter the direction(l/r)";
                cin >> dir;
                if (dir == 'l' || dir == 'r') { // Validating direction input
                    if (dir == 'l') {
                        if (ptr->left == NULL) {
                            ptr->left = temp;
                            break;
                        } else
                            ptr = ptr->left;
                    } else {
                        if (ptr->right == NULL) {
                            ptr->right = temp;
                            break;
                        } else
                            ptr = ptr->right;
                    }
                } else {
                    cout << "Invalid direction. Please enter 'l' or 'r'." << endl;
                }
            }
        }
        cout << "\nDo you want to add more data(1/0):";
        cin >> ch;
    } while (ch == 1);
    return root;
}

void preorder_trav(node *h) {
    if (h == NULL)
        return;
    else {
        cout << "\t" << h->name << " :: " << h->relation << "\n";
        preorder_trav(h->left);
        preorder_trav(h->right);
    }
}

void postorder_trav(node *h) {
    if (h == NULL)
        return;
    else {
        postorder_trav(h->left);
        postorder_trav(h->right);
        cout << "\t" << h->name << " :: " << h->relation << "\n";
    }
}

void inorder_trav(node *h) {
    if (h == NULL)
        return;
    else {
        inorder_trav(h->left);
        cout << "\t" << h->name << " :: " << h->relation << "\n";
        inorder_trav(h->right);
    }
}

void update_info(node *h, string target_name) {
    if (h == NULL)
        return;
    else {
        if (h->name == target_name) {
            cout << "Enter the new name of the family member :";
            cin >> h->name;
            cout << "Enter the new relation :";
            cin >> h->relation;
            return;
        }
        update_info(h->left, target_name);
        update_info(h->right, target_name);
    }
}

void deallocate_memory(node* root) {
    if(root == NULL)
        return;
    deallocate_memory(root->left);
    deallocate_memory(root->right);
    delete root;
}

int main() {
    node *n = nullptr; // Initialize to nullptr
    int ch, c;
    do {
        cout << "\nMENU\n1.Create\n2.Display\n3.Update Information\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                n = create();
                break;

            case 2:
                if (n == nullptr) {
                    cout << "Tree is empty..." << endl;
                } else {
                    cout << "Post order display :: \n";
                    postorder_trav(n);
                    cout << "\nPre order display :: \n";
                    preorder_trav(n);
                    cout << "\nIn order display :: \n";
                    inorder_trav(n);
                }
                break;

            case 3:
                if (n == nullptr) {
                    cout << "Tree is empty. Please create a tree first." << endl;
                } else {
                    string target_name;
                    cout << "Enter the name of the family member to update: ";
                    cin >> target_name;
                    update_info(n, target_name);
                }
                break;

            default:
                cout << "Wrong choice..\n";
        }
        cout << "Do you want to continue(1/0) : ";
        cin >> c;
    } while (c == 1);
    
    deallocate_memory(n); // Deallocate memory before exiting

    return 0;
}

