#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node{
    public:
        int data;
        int height;
        node* left;
        node* right;
        node(int data){
            this->height = 1;
            this->data   = data;
            this->left   = NULL;
            this->right  = NULL;
        }
};
class avlTree{
    private:
        node * root;
    public:
        avlTree(){
            this->root = NULL;
        }
        bool contains(node* &root,int data){
            if(!root){
                return root;
            }
            else if(data==root->data){
                return data==root->data;
            }
            else if (data<root->data){
                return contains(root->left,data);
            }
            else{
                return contains(root->right,data);
            }
            
        }
        int getHeight(node* &root){
            int hr = root && root->right ?root->right->height:0; 
            int hl = root && root->left  ?root->left->height:0; 
            return hr>hl ? hr+1:hl+1;
        }
        node* add(node* &root,int data){
            if(!root){
                return new node(data);
            }
            else if(data<root->data){
                root->left = add(root->left,data);
            }
            else{
                root->right = add(root->right,data);
            }
            root->height = getHeight(root);
            return root;
        }
        void add(int data){
            if (this->contains(this->root,data)){
                return; 
            }
            this->root = this->add(root,data);
        }
        void inOrder(node* &root){
            if(!root){
                return;
            }
            inOrder(root->left);
            cout<<root->data<<" ";
            inOrder(root->right);
        }
        void display(){
            this->inOrder(this->root);
            cout<<endl;
        }
        node * inOrderPredecessor(node* &root){
            if(!root->right){
                return root;
            }
            return inOrderPredecessor(root->right);
        }
        node * discard(node* &root,int data){
            if(!root){
                return root;
            }
            else if (data<root->data){
                root->left = discard(root->left,data);
            }
            else if (data>root->data){
                root->right = discard(root->right,data);
            }
            else{
                if (!root->right && !root->left){
                    root = root->right;
                    
                }
                else if(!root->right){
                    root =  root->left;
                }
                else if(!root->right){
                    root =  root->right;
                }
                else{
                    node * iPre = inOrderPredecessor(root->left);
                    root->data  = iPre->data;
                    root->left = this->discard(root->left,iPre->data);
                }
                
            }
            if(root){
                root->height = getHeight(root);
            }
            return root;
        }
        void discard(int data){
            this->root = this->discard(root,data);
        }
        int balanceFactor(node* &root){
            int left  = root && root->left ?root->left ->height:0;
            int right = root && root->right?root->right->height:0;
            return left-right;
        }
        void levelOrder(){
            queue<node*> l;
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
                    cout<<d->data<<" height : "<<
                    d->height<<" bf "<<balanceFactor(d)<<" ";
                    if(d->left){
                        l.push(d->left);
                    }
                    if(d->right){
                        l.push(d->right);
                    }
                }
            }
            cout<<endl;
        }

};
int main(int argc, char const *argv[]){
    
    avlTree* l = new avlTree();
    l->add(5);
    l->add(6);
    l->add(3);
    l->add(4);
    l->add(2);
    l->add(1);
    l->add(9);
    l->add(7);
    l->add(10);
    l->display();
    l->discard(5);
    l->levelOrder();
    l->display();
    return 0;
}
