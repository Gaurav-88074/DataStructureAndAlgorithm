#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->left = NULL;
        this->data = data;
        this->right= NULL;
    }
};
node* add(node* &root,int data){
    if(root==NULL){
        return new node(data);
    }
    else if(data < root->data){
        root->left  = add(root->left,data);
    }
    else{
        root->right = add(root->right,data);
    }
    return root;
}
node* inOrderPredecessor(node* root){
    if(root->right==NULL){
        return root;
    }
    else{
        return inOrderPredecessor(root->right);
    }
}
bool contains(node* root,int data){
    if (root ==NULL){
        return false;
    }
    else if(root->data==data){
        return true;
    }
    else if (data<root->data){
        return contains(root->left,data);
    }
    else{
        return contains(root->right,data);
    }
    
}
node* discard(node* &root,int data){
    if(root==NULL){
        return root;
    }
    else if(data<root->data){
        root->left = discard(root->left,data);
    }
    else if(data>root->data){
        root->right = discard(root->right,data);
    }
    else{
        if (root->left==NULL && root->right==NULL){
            root =  NULL;
        }
        else if(root->left==NULL){
            root = root->right;
        }
        else if(root->right==NULL){
            root = root->left;
        }
        else{
            node* iPre = inOrderPredecessor(root->left);
            root->data = iPre->data;
            root->left = discard(root->left,iPre->data);
        }
    }
    return root;
}
void inOrder(node* root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void preOrder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    inOrder(root->left);
    inOrder(root->right);
}
void postOrder(node* root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    inOrder(root->right);
    cout<<root->data<<" ";
}
void preOrderIterative(node * root){
    if(!root){
        return;
    }
    stack<node*> s ;
    s.push(root);
    while (!s.empty()){
        node * head = s.top();
        s.pop();
        cout<<head->data<<" ";
        if (head->right){
            s.push(head->right);
        }
        if (head->left){
            s.push(head->left);
        }
    }
}
void postOrderIterative(node * root){
    if(!root){
        return;
    }
    stack<node*> s ;
    s.push(root);
    while (!s.empty())
    {
        node * head = s.top();
        while (head!=NULL)
        {
            s.push(head);
            head=head->left;
        }
        
    }
    
}
void levelOrder(node* root){
    static queue<node*> l;
    l.push(root);
    l.push(NULL);
    while (!l.empty()){
        node* d = l.front();
        l.pop();
        if (d==NULL){
            if (!l.empty()){
                l.push(d);
                cout<<endl;
            }
            else{
                break;
            }
        }
        else{
            cout<<d->data<<" ";
            if(d->left){
                l.push(d->left);
            }
            if(d->right){
                l.push(d->right);
            }
        }
    }
    
}
int main(int argc, char const *argv[])
{
    node * root = NULL;

    root = add(root,5);
    root = add(root,3);
    root = add(root,6);
    root = add(root,1);
    root = add(root,4);

    inOrder(root);cout<<endl;
    // root = discard(root,5);
    // inOrder(root);cout<<endl;
    // root = discard(root,3);
    // inOrder(root);cout<<endl;
    //--------------------------------
    levelOrder(root);cout<<endl;
    //--------------------------------
    //--------------------------------
    preOrder(root);cout<<endl;
    preOrderIterative(root);cout<<endl;
    //--------------------------------
    // cout<<contains(root,3)<<endl;
    // cout<<contains(root,5)<<endl;
    // cout<<contains(root,6)<<endl;
    // cout<<contains(root,1)<<endl;
    // cout<<contains(root,4)<<endl;
    // cout<<contains(root,2)<<endl;

    return 0;
}
