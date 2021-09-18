#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data = data;
    }
};
node* insertAtEnd(node* &head,node* &tail,int data){
    if (!head){
        head = tail = new node(data);
    }
    else{
        tail->next = new node(data);
        tail = tail->next;
    }
    tail ->next = head;
    return head;
}
node* insertAtHead(node* &head,node* &tail,int data){
    if (!head){
        head = tail = new node(data);
    }
    else{
        node* top = new node(data);
        top->next = head;
        head = top;
    }
    tail ->next = head;
    return head;
}
node* insertAtIndex(node* &head,int data,int index){
    if(index<0){
        cout<<"Error : index out of bound"<<endl;
        return head; 
    }
    else if (index==0){
        node * headNext = new node(data);
        headNext->next  = head;
        return headNext;
    }
    else{
        head->next = insertAtIndex(head->next,data,index-1);
    }
    return head;
}
node* deletionAtHead(node* &head,node* &tail){
    if (!head){
        return head;
    }
    else if(head==tail){
        return NULL;
    }
    else{
        node* top = head;
        head = head->next;
    }
    tail ->next = head;
    return head;
}
node* deletionAtTail(node* &head,node* &tail){
    if (!head){
        return head;
    }
    else if(head==tail){
        tail = NULL;
        return tail;
    }
    else if(head->next == tail){
        tail = head;
    }
    else{
        head->next = deletionAtTail(head->next,tail);
    }
    tail->next = head;
    return head;
}
node* remove(node* &head,node* &tail,int data){
    if (!head){
        return head;
    }
    else if(head->data != data && head==tail){
        return head;
    }
    else if(head->data == data){
        head =  head->next;
    }
    else{
        head->next = remove(head->next,tail,data);
    }
    tail->next = head;
    return head;
}
node* search(node* &head,node* tail,int data){
    if(!head){
        cout<<"seems it doesn't exist!"<<endl;
        return head;
    }
    else if(head->data==data){
        return head;
    }
    else if(head==tail && head->data!=data){
        cout<<"seems it doesn't exist!"<<endl;
        return NULL;
    }
    else{
        return search(head->next,tail,data);
    }
}
node* reverse(node* head,node* tail){
    return head;
}

void print(node* head,node* tail){
    if(!head){
        return;
    }
    else if(head==tail){
        cout<<head->data;
        return;
    }
    else{
        cout<<head->data<<" ,";
        print(head->next,tail);
    }
}
void display(node* &head,node* &tail){
    cout<<"[";
    print(head,tail);
    cout<<"]"<<endl;;
}
int main(int argc, char const *argv[]){
    node* head = NULL;
    node* tail = NULL;

    head = insertAtHead(head,tail,1);
    head = insertAtHead(head,tail,4);

    head = insertAtEnd(head,tail,3);
    head = insertAtEnd(head,tail,7);
    head = insertAtEnd(head,tail,8);
    head = insertAtEnd(head,tail,2);
    head = insertAtEnd(head,tail,5);
    head = insertAtEnd(head,tail,6);

    head = insertAtIndex(head,10,5);
    head = insertAtIndex(head,11,5);

    display(head,tail);

    deletionAtHead(head,tail);
    display(head,tail);

    deletionAtTail(head,tail);
    display(head,tail);


    head = remove(head,tail,11);
    display(head,tail);

    node* check = search(head,tail,2);
    cout<<check->data<<endl;
    
    return 0;
}
