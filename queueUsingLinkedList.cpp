#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data = data;
        this->next = NULL;
    }
};

node * enqueue(node* &head,int data){
    if (head==NULL){
        return new node(data);
    }
    else{
        head->next =  enqueue(head->next,data);
    }
    return head;
}
bool isEmpty(node* &head){
    if(head==NULL){
        return true;
    }
    else{
        return false;
    }
}
node * dequeue(node* &head){
    if (isEmpty(head)){
        cout<<"Queue is empty!"<<endl;
        return head;
    }
    else{
        return head->next;
    }
}
int peek(node* &head){
    if (isEmpty(head)){
        cout<<"Queue is empty!"<<endl;
        return -1;
    }
    else{
        return head->data;
    }
}
void display(node* &head){
    if(head==NULL){
        return;
    }
    else{
        cout<<head->data<<" ";
        display(head->next);
    }
}
const void menu(){
    cout<<"---------------"<<endl;
    cout<<"1.Display Queue"<<endl;
    cout<<"2.Enqueue element "<<endl;
    cout<<"3.Dequeue element  "<<endl;
    cout<<"4.Peek element  "<<endl;
    cout<<"5.Check IsEmpty  "<<endl;
    cout<<"6.Exit"<<endl;
    cout<<"---------------"<<endl;
}
const void choice1(node* &head){
    cout<<"Queue : [";
    display(head);
    cout<<"]"<<endl;
}
const void choice2(node* &head){
    int value;
    cout<<"Enter value : ";
    cin>>value;
    head = enqueue(head,value);
}
const void choice3(node* &head){
    int value = peek(head);
    cout<<"~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<value<<" is popped!"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~"<<endl;
    head = dequeue(head);
}
const void choice4(node* &head){
    cout<<"Peek element : "<<peek(head)<<endl;
}
const void choice5(node* &head){
    if(isEmpty(head)){
        cout<<"Yes,Queue is Empty"<<endl;
    }
    else{
        cout<<"No,Queue isn't Empty!"<<endl;
    }
}
const void execute(node * &head){
    menu();
    int choice;
    cin.clear();
    cout<<"-----------------------"<<endl;
    cout<<"Enter Your Choice [1-5] : ";
    cin>>choice;
    cout<<"-----------------------"<<endl;
    cin.clear();
    cin.ignore();
    switch (choice){
        case 1:
            choice1(head);
            execute(head);
            break;
        case 2:
            choice2(head);
            choice1(head);
            execute(head);
            break;
        case 3:
            choice3(head);
            choice1(head);
            execute(head);
            break;
        case 4:
            choice4(head);
            choice1(head);
            execute(head);
            break;
        case 5:
            choice5(head);
            choice1(head);
            execute(head);
            break;
        default:
            break;
    }
}
int main(int argc, char const *argv[]){
    node * head = NULL;
    execute(head);
    // head = enqueue(head,5);
    // head = enqueue(head,6);
    // head = enqueue(head,7);
    // display(head);
    // head = enqueue(head,8);
    // display(head);
    // head = dequeue(head);
    // display(head);
    // cout<<peek(head)<<endl;
    return 0;
}

