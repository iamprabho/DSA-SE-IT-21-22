#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *newNode(int val)
{
    node *n = new node;
    n->data = val;
    n->left = NULL;
    n->right = NULL;
    // return n;
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

node *search(node *t, int key)
{
    bool flag = 0;
    node *s = t;
    while (s != NULL)
    {
        if (s->data == key)
        {
            flag += 1;
            cout << s->data << " is present in this tree\n";
            break;
        }
        else if (s->data < key)
        {
            s = s->right;
        }
        else if (s->data > key)
        {
            s = s->left;
        }
    }
}

node *insert(node *root, int val)
{
    if (root == NULL)
    {
        return newNode(val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}

int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int hl = height(root->left);
    int hr = height(root->right);
    return max(hl, hr) + 1;
}

node *mirror(node *t)
{
    node *temp_var;
    if (t == NULL)
    {
        return NULL;
    }
    temp_var = t->left;
    t->left = mirror(t->right);
    t->right = mirror(temp_var);
    inorder(t);
    // return t;
}

node *copy(node *T)
{
    node *p;
    p = NULL;
    if (T != NULL)
    {
        p = new node();
        p->data = T->data;
        p->left = copy(T->left);
        p->right = copy(T->right);
    }
    inorder(p);
}

void leaf(node *t)
{
    if (t == NULL)
        return;
    if (t->left == NULL && t->right == NULL)
    {
        cout << "\nLeaf Nodes: " << t->data << endl;
    }
    leaf(t->left);
    leaf(t->right);
}

node *find_min(node *r)
{
    while (r->left != NULL)
    {
        r = r->left;
    }
    return r;
}

node *del(node *t, int val)
{
    node *temp, *q, *r;

    if (t == NULL)
    {
        return NULL;
    }
    if (val < t->data)
    {
        t->left = del(t->left, val);
        return t;
    }
    if (val > t->data)
    {
        t->right = del(t->right, val);
        return t;
    }

    // element found
    // no child
    if (t->left == NULL && t->right == NULL)
    {
        delete t;
        return NULL;
    }

    //one child
    if (t->left != NULL && t->right == NULL)
    {
        temp = t;
        t = t->left;
        delete temp;
        return t;
    }

    if (t->left == NULL && t->right != NULL)
    {
        temp = t;
        t = t->right;
        delete temp;
        return t;
    }

    // both child present
    temp = find_min(t->right);
    t->data = temp->data;
    t->right = del(t->right, temp->data);
    return t;
}

int main()
{
    int ch, i, l, l1, val;
    node *temp = NULL;
    do{
        cout << "\n\t\t----------TREE OPERATIONS---------- \nChoose from following: ";
        cout << "\n1]-> Insert" << endl;
        cout << "2]-> Delete" << endl;
        cout << "3]-> Search" << endl;
        cout << "4]-> Inorder Display" << endl;
        cout << "5)-> Display - Depth of tree" << endl;
        cout << "6]-> Display - Mirror image" << endl;
        cout << "7]-> Create a copy" << endl;
        cout << "8]-> Display leaf nodes" << endl;
        cout << "9]-> Exit" << endl;
        cout << "\nYour choice: ";
        cin >> ch;
        switch (ch){
        case 1:
            cout << "Enter a num:-> ";
            cin >> l;
            temp = insert(temp, l);
            break;

        case 2:
            cout << "Enter which no is to be delete: ";
            cin >> l1;
            del(temp, l1);
            break;

        case 3:
            cout << "Enter a val for search: ";
            cin >> val;
            search(temp, val);
            break;

        case 4:
            cout << "Inorder Display: ";
            inorder(temp);
            break;

        case 5:
            cout << "Height of binary search tree is: " << height(temp);
            break;

        case 6:
            mirror(temp);
            break;

        case 7:
            copy(temp);
            break;

        case 8:
            leaf(temp);
            break;
        }
    } while (ch != 9);
    return 0;
}
