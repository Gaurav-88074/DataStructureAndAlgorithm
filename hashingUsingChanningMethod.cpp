#include<iostream>
#include<vector>
using namespace std;    

class node{
    public:
    int data;
    node* next;
    node(){
        this->next = NULL;
    }
    node(int data){
        this->data = data;
        this->next = NULL;
    }
};
int hashCode(int data){
    return data%9;
}
node* insert(node* &head,int data){
    if(!head){
        return new node(data);
    }
    else if(head->data==data){
        return head;
    }
    else if(head->data>data){
        node* mid = new node(data);
        mid->next = head;
        return mid;
    }
    else{
        head->next = insert(head->next,data);
    }
    return head;
}
void add(vector<node*> &hashTable,int data){
    int hashValue = hashCode(data);
    node* head = hashTable[hashValue];
    head = insert(head,data);
    hashTable[hashValue] = head;
}
void displayNode(node* &head){
    if (!head){cout<<"NULL";return;}
    cout<<head->data<<" -> ";
    displayNode(head->next);
}
node* deleteNode(node* &head,int data){
    if(!head){
        return head;
    }
    if(head->data==data){
        return  head->next;
    }
    else{
        head->next = deleteNode(head->next,data);
    }
    return head;
}
void discard(vector<node*> &hashTable,int data){
    int hashValue = hashCode(data);
    node* head = hashTable[hashValue];
    head = deleteNode(head,data);
    hashTable[hashValue]=head;
}
bool isPresent(node* &head,int data){
    if(!head){return false;}
    if(head->data==data){return true;}
    return isPresent(head->next,data);
}
bool contains(vector<node*> &hashTable,int data){
    int hashValue = hashCode(data);
    node* head = hashTable[hashValue];
    return isPresent(head,data);
}
void display(vector<node*> &hashTable){
    for (int i = 0; i < 10; i++){
        cout<<"["<<i<<" : ";
        displayNode(hashTable[i]);
        cout<<"]"<<endl;
    }
}
int main(int argc, char const *argv[]){
    vector<node*> hashTable(10);
    for (int i = 0; i < 100; i++){
        add(hashTable,rand()%100);
    }
    display(hashTable);
    bool check = contains(hashTable,9);
    cout<<check<<endl;
    discard(hashTable,18);
    display(hashTable);
    // add(hashTable,10);
    // add(hashTable,34);
    // add(hashTable,26);
    // add(hashTable,49);
    // add(hashTable,50);
    // add(hashTable,36);
    // add(hashTable,77);
    // add(hashTable,38);
    // add(hashTable,99);
    // add(hashTable,24);
    // add(hashTable,45);
    // add(hashTable,64);
    // add(hashTable,22);
    // add(hashTable,46);
    // add(hashTable,42);
    // add(hashTable,51);
    // add(hashTable,74);
    // add(hashTable,14);
    // add(hashTable,89);
    // add(hashTable,10);
    // add(hashTable,20);
    // add(hashTable,30);
    // add(hashTable,40);
    // add(hashTable,50);
    // add(hashTable,60);
    // add(hashTable,70);
    // add(hashTable,80);
    // add(hashTable,90);
    

    return 0;
}
