#include<iostream>
using namespace std;

class node{
    public:
        int  data;
        node* next;
        node(int data){
            this->data = data;
            this->next = NULL;
        }
};
node * push(node* &head,int data){
    if(head==NULL){
        return new node(data);
    }
    else{
        node* top = new node(data);
        top->next = head;
        return top;
    }
}
bool isEmpty(node* &head){
    if(!head){
        return true;
    }
    else{
        return false;
    }
}
node * pop(node* &head){
    if(isEmpty(head)){
        cout<<"stack underflow!"<<endl;
        return head;
    }
    else{
        node * thisNode = head->next;
        free(head);
        return thisNode;
    }
}
int peek(node * &head){
    if(isEmpty(head)){
        cout<<"stack is empty!"<<endl;
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
        display(head->next);
        cout<<head->data<<" ";
    }
}
const void menu(){
    cout<<"---------------"<<endl;
    cout<<"1.Display Stack"<<endl;
    cout<<"2.Push element "<<endl;
    cout<<"3.Pop element  "<<endl;
    cout<<"4.Peek Element  "<<endl;
    cout<<"5.Check IsEmpty  "<<endl;
    cout<<"6.Exit"<<endl;
    cout<<"---------------"<<endl;
}
const void choice1(node* &head){
    cout<<"Stack : [";
    display(head);
    cout<<"]"<<endl;
}
const void choice2(node* &head){
    int value;
    cout<<"Enter value : ";
    cin>>value;
    head = push(head,value);
}
const void choice3(node* &head){
    int value = peek(head);
    cout<<"~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<value<<" is popped!"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~"<<endl;
    head = pop(head);
}
const void choice4(node* &head){
    cout<<"Peek element : "<<peek(head)<<endl;
}
const void choice5(node* &head){
    if(isEmpty(head)){
        cout<<"Yes,Stack is Empty"<<endl;
    }
    else{
        cout<<"No,Stack isn't Empty!"<<endl;
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
   
    return 0;
}

