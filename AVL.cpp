#include <iostream>
#include <queue>
using namespace std;

class node{
public:
      int data;
      int height=1;
      node *left;
      node *right;
      node(int data){
            this->left = NULL;
            this->data = data;
            this->right = NULL;
      }
};
int getHeight(node *root){
      if (!root){
            return 0;
      }
      else{
            int left  = getHeight(root->left);
            int right = getHeight(root->right);
            return 1 + max(left, right);
      }
}
int balanceFactor(node * root){
      return getHeight(root->left)-getHeight(root->right);
}
node * llRotation(node * root){
      node * x = root->left;
      node * y = x->right;
      x->right = root;
      root->left = y;
      return x;
}
node * rrRotation(node * root){
      node * x = root->right;
      node * y = x->left;
      x->left = root;
      root->right = y;
      return x;
}
node *add(node* &root, int data){
      if (root == NULL){
            return new node(data);
      }
      else if (data < root->data){
            root->left = add(root->left, data);
            root->left->height = getHeight(root->left);
      }
      else{
            root->right = add(root->right, data);
            root->right->height = getHeight(root->right);
      }
      root->height = getHeight(root);
      if (balanceFactor(root)==2 && balanceFactor(root->left)==1){
            root = llRotation(root);
      }
      else if (balanceFactor(root)==2 && balanceFactor(root->left)==-1){
            root->left = rrRotation(root->left);
            root = llRotation(root);
      }
      else if (balanceFactor(root)==-2 && balanceFactor(root->right)==1){
            root->right = llRotation(root->right);
            root = rrRotation(root);
      }
      else if (balanceFactor(root)==-2 && balanceFactor(root->right)==-1){
            root = rrRotation(root);
      }
      return root;
}
node *inOrderPredecessor(node *root){
      if (root->right == NULL){
            return root;
      }
      else{
            return inOrderPredecessor(root->right);
      }
}
bool contains(node *root, int data){
      if (root == NULL){
            return false;
      }
      else if (root->data == data){
            return true;
      }
      else if (data < root->data){
            return contains(root->left, data);
      }
      else{
            return contains(root->right, data);
      }
}
node *discard(node *&root, int data){
      if (root == NULL){
            return root;
      }
      else if (data < root->data){
            root->left = discard(root->left, data);
      }
      else if (data > root->data){
            root->right = discard(root->right, data);
      }
      else{
            if (root->left == NULL && root->right == NULL)
            {
                  root = NULL;
            }
            else if (root->left == NULL)
            {
                  root = root->right;
            }
            else if (root->right == NULL)
            {
                  root = root->left;
            }
            else
            {
                  node *iPre = inOrderPredecessor(root->left);
                  root->data = iPre->data;
                  root->left = discard(root->left, iPre->data);
            }
      }
      
      return root;
}
void inOrder(node* &root){
      if (!root)
      {
            return;
      }
      inOrder(root->left);
      cout << root->data << " ";
      inOrder(root->right);
}
void levelOrder(node* &root){
      static queue<node *> l;
      l.push(root);
      l.push(NULL);
      while (!l.empty()){
            node *d = l.front();
            l.pop();
            if (d == NULL){
                  if (!l.empty())
                  {
                        l.push(d);
                        cout << endl;
                  }
                  else
                  {
                        cout << endl;
                        break;
                  }
            }
            else{
                  // cout <<"[height "<<
                  // d->height<<" : "<<" bf : "<<balanceFactor(d)<<" value "<<
                  // d->data << "] ";
                  cout<<d->data<<" ";
                  if (d->left){
                        l.push(d->left);
                  }
                  if (d->right){
                        l.push(d->right);
                  }
            }
      }
}

int main(int argc, char const *argv[]){
      node *root = NULL;

      root = add(root, 10);                                          
      root = add(root, 20);
      root = add(root, 30);
      root = add(root, 40);
      root = add(root, 50);
      root = add(root, 60);

      inOrder(root);cout<<endl;
      root = discard(root,50);
      inOrder(root);cout<<endl;
      root = discard(root,30);
      inOrder(root);cout<<endl;
      //--------------------------------
      root = add(root, 50);
      root = add(root, 5);
      root = add(root, 60);
      root = add(root, 70);
      root = add(root, 80);
      root = add(root, 90);
      root = add(root, 100);
      //--------------------------------
      levelOrder(root);
      //--------------------------------
      //     cout<<contains(root,3)<<endl;
      //     cout<<contains(root,5)<<endl;
      //     cout<<contains(root,6)<<endl;
      //     cout<<contains(root,1)<<endl;
      //     cout<<contains(root,4)<<endl;
      //     cout<<contains(root,2)<<endl;

      return 0;
}