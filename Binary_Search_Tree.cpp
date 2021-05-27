#include<bits/stdc++.h>
#include<stack>
using namespace std;
#define ll long long


struct node
{
    int key;
    struct node *left;
    struct node *right;
};

// Utitlity function to create a new node
node* newnode(int data)
{
    node* temp = new node;
 
    temp->key = data;
    temp->left = NULL;
    temp->right = NULL;
 
    return temp;
}
node *insert(node *root , int key)
{
    node *temp = newnode(key);
    
    node *x = root; 
    node *y = NULL;

    while( x != NULL)
    {
        y = x;
        if(x->key < key)
        {
            x = x->right;
        }
        else
        {
            x = x->left;
        }
    }
    //if tree is already empty.
    if(y == NULL)
    {
        y = temp;
    }

    //else tree is not empty.we use node y to take track of parent of x(child of y) where we have to insert new node 
    else
    {
        if(key > y->key)
        {
            y->right = temp;
        }
        else
        {
            y -> left = temp;
        }
    }
    return y;
}

int max_depth(node *root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        return (1 + max( max_depth(root->left) , max_depth(root->right)));
    }
}

int max_depth_iterative(node *root)
{
    int lvl = 0;
    queue<node*>q;
    q.push(root);
    node *curr = NULL;

    while(!q.empty())
    {
        int size = q.size();
        //Traverse and add all node of subtrees in queue .
        while(size--)
        {
            curr = q.front();
            q.pop();
            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);
        }
        lvl++;
    }
    return lvl;
}

void Inorder(node* root)
{
    if (root == NULL)
        return;
    else {
        Inorder(root->left);
        cout << root->key << " ";
        Inorder(root->right);
    }
}

void Inorder_iterative(node *root)
{

    stack<node*>s;
    node* curr = root;
    while(!s.empty() || curr != NULL)
    {
        if(curr != NULL)
        {
            s.push(curr);
            curr = curr -> left;
        }
        else
        {
            curr = s.top();
            s.pop();
            cout << curr -> key <<" ";
            curr = curr -> right;
        }
    }
}
void pre_order(node* root )
{
    if(root == NULL)return;
    
    else
    {
        cout << root -> key << " ";
        pre_order(root -> left);
        pre_order(root -> right);
    }
}

void preorder_iterative(node *root)
{
    stack<node*>s;
    s.push(root);

    while(!s.empty())
    {
        node *curr = s.top();
        s.pop();
        cout << curr -> key <<" ";
        if(curr -> right != NULL)
        {
            s.push(curr->right);
        }
        if(curr -> left != NULL)
        {
            s.push(curr -> left);
        }
    }
    
}

void post_order(node *root)
{
    if(root == NULL) return;

    else
    {
        post_order(root -> left);
        post_order(root -> right);
        cout << root->key << " ";
    }
}

void postorder_iterative(node *root)
{
    stack<node*>s;
    s.push(root);

    //Make another stack to store post-order Traversal of BST.
    stack<int>store;
    while(!s.empty())
    {
        node *curr = s.top();
        s.pop();
        store.push(curr -> key);
        if(curr -> left != NULL)
        {
            s.push(curr -> left );
        }
        if(curr -> right != NULL)
        {
            s.push(curr -> right);
        }
    }

    while( !store.empty())
    {
        cout << store.top() << " ";
        store.pop();
    }
}

void levelorder_iterative(node *root)
{
    //using queue.
    queue<node*>q;
    node *curr = NULL;
    q.push(root);

    while(!q.empty())
    {
        curr = q.front();
        q.pop();
        cout << curr->key << " ";
        
        if(curr -> left)
        {
            q.push(curr->left);
        }
        if(curr -> right)
        {
            q.push(curr->right);
        }
    }
}
node* search(node *root , int key)
{
    node *temp = root;
    bool find = false;

    while(1)
    {
        if(temp -> key == key)
        {
            return temp;
        }
        else if(temp->key > key)
        {
            temp = temp -> left;
        }
        else
        {
            temp = temp -> right;
        }
        if(temp == NULL)
        {
            return NULL;
        }
    }
}

int main()
{

    /* Let us create following BST
            50
          /   \
        30      70
        / \   / \
       20 40 60 80 */

    node *root = NULL;

    //Insert Operation.
    root = insert(root,50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
/*------------------------------------------------------------------------------------------------------------------------------*/
    //calculate height or depth of tree.
    int ldepth = 0, rdepth = 0;
    int height = max_depth_iterative(root);
    /*int height = max_depth(root);*/
    cout << "Max Depth/Height is : " << height <<endl;

    //Inorder Traversal.
    cout <<"Tree Traversal in Inorder : "<<endl;
    /*Inorder(root);*/
    Inorder_iterative(root);
    cout << "\n\n";


    //pre-order Traversal.
    cout << "Tree Travsersal in pre-order : "<<endl;
    /*pre_order(root);*/
    preorder_iterative(root);
    cout << "\n\n";


    //post-order Traversal.
    cout << "Tree Traversal in post-order : "<<endl;
    /*post_order(root);*/
    postorder_iterative(root);
    cout << "\n\n";

    //levelorder Traversal.
    cout << "Tree Traversal in level-order : "<<endl;
    levelorder_iterative(root);
    cout <<"\n\n";

    //Search in binary tree.
    node* find = search(root , 50);
    if(find)cout << "Element found in Binary Tree "<<find->key;
    else cout << "Element not found in Binary Tree ";
}

//Insert a node in BST.
//Calculate maximum height/depth of Tree in most optimized way(iterative and recursive both code are written).
//searching in BST.
//Traversal (recurive and iterative)
/*   1) Inorder 
     2) preorder
     3)postorder
     4)levelorder(only iterative using queue)
*/
