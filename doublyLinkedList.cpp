#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
bool isEmpty(node* &head){
    if(!head){
        return true;
    }
    else{
        return false;
    }
}
node * insertAtEnd(node* &head,node* &tail,int data){
    if(head==NULL){
        head = new node(data);
        tail =head;
    } 
    else{
        tail->next = new node(data);
        tail->next->prev = tail;
        tail = tail->next;
    }
    return head;
}
node * insertAtHead(node* &head,node* &tail,int data){
    if(head==NULL){
        head = new node(data);
        tail = head;
    } 
    else{
        node * top = new node(data);
        top->next  = head;
        head->prev = top;
        head = top;
        
    } 
    return head;
}
node * insertAtIndex(node* &head,int data,int index){
    static int pointer = -1;
    if(pointer==index-1){
        node * headNext= new node(data);
        headNext->next = head;
        head->prev  = headNext;
        return headNext;
    } 
    else{
        pointer++;
        head->next = insertAtIndex(head->next,data,index);
        head->next->prev = head;
        return head;
    } 
}
node * deleteFromHead(node* &head){
    if(!head){
        return head;
    } 
    else{
        node * thisNode = head;
        head=head->next;
        if(head){
            head->prev=NULL;
        }
        free(thisNode);
    } 
    return head;
}
node * deleteFromTail(node* &head,node* &tail){
    if (!tail){
        return tail;
    }
    else if(tail==head){
        node* thisNode = head->prev;
        free(head);
        tail=thisNode;
        return thisNode;
    }
    else{
        tail->prev->next=NULL;
        tail = tail->prev;
    }
    return head;
    
}
node * deleteAtIndex(node* &head,int index){
    static int pointer = -1;
    if(head==NULL){
        return head;
    }
    else if(pointer==index-1){
        node * target = head->next;
        free(head);
        return target;
    }
    else{
        pointer++;
        head->next = deleteAtIndex(head->next,index);
        head->next->prev = head;
        return head;
    } 
}
bool contains(node * &head,int data){
    if (head==NULL){
        return false;
    }
    else if(head->data==data){
        return true;
    }
    else{
        return contains(head->next,data);
    }
}
node * discard(node * head,int data){
    if (!head){
        cout<<"seems it doesn't exist!"<<endl;
        // return head;
    }
    else if (head->data == data){
        node* thisNode = head;
        head = head->next;
        free(thisNode);
        // return head;
    }
    else{
        head->next = discard(head->next,data);
        head->next->prev = head;
        // return head;
    }
    return head;
}
node * reverse(node * &head,node * &tail){
    if(!head){
        return head;
    }
    else{
        node * temp = head->prev;
        head->prev = reverse(head->next,tail);
        head->next = temp;
    }
    tail = head;
    return head;
}
void display(node* &head){
    if (head==NULL){
        cout<<"NULL";
        return;
    }
    else{
        cout<<head->data<<" -> ";
        display(head->next);
    }
}
void displayReverse(node* &tail){
    if (tail==NULL){
        cout<<"NULL";
        return;
    }
    else{
        cout<<tail->data<<" -> ";
        displayReverse(tail->prev);
    }
}
const void menu(void){
    cout<<"---------------------------------------"<<endl;
    cout<<"0.Display Doubly Linked List"<<endl;
    cout<<"1.Insert Value"<<endl;
    cout<<"2.Insert At Head"<<endl;
    cout<<"3.Insert At Tail"<<endl;
    cout<<"4.Insert At Specific Index"<<endl;
    cout<<"5.Deletion At Head"<<endl;
    cout<<"6.Deletion At Tail"<<endl;
    cout<<"7.Deletion At Specific Index"<<endl;
    cout<<"8.Discard Element"<<endl;
    cout<<"9.Reverse Doubly Linked List"<<endl;
    cout<<"10.To check that element is present or not"<<endl;
    cout<<"11.Exit"<<endl;
    cout<<"---------------------------------------"<<endl;
}
const void choice0(node * &head){
    cout<<endl<<"Doubly Linked List : [";
    display(head);
    cout<<"]"<<endl<<endl;
}
const void choice1(node * &head,node * &tail){
    int value;
    cout<<"Enter the value  : ";
    cin>>value;
    head = insertAtEnd(head,tail,value);
}
const void choice2(node * &head,node * tail){
    int value;
    cout<<"Enter the value to be inserted at Head : ";
    cin>>value;
    head = insertAtHead(head,tail,value);
}
const void choice3(node * &head,node * tail){
    int value;
    cout<<"Enter the value to be inserted at Tail : ";
    cin>>value;
    head = insertAtEnd(head,tail,value);
}
const void choice4(node * &head){
    int value;
    int index;
    cout<<"Enter the value , index : ";
    cin>>value>>index;
    head = insertAtIndex(head,value,index);
}
const void choice5(node * &head){
    head = deleteFromHead(head);
}
const void choice6(node * &head,node * &tail){
    head = deleteFromTail(head,tail);
}
const void choice7(node * &head){
    int index;
    cout<<"Enter index value : ";
    cin>>index;
    head = deleteAtIndex(head,index);
}
const void choice8(node * &head){
    int value;
    cout<<"Enter value : ";
    cin>>value;
    head = discard(head,value);
}
const void choice9(node * &head,node* &tail){
    node * preTail = tail;
    head = reverse(head,tail);
    head = preTail;
}
const void choice10(node * &head){
    int value;
    cout<<"Enter value : ";
    cin>>value;
    bool check = contains(head,value);
    if (check){
        cout<<"Yes,it is present"<<endl;
    }
    else{
        cout<<"No,it isn't present"<<endl;
    }      
}
const void execute(node * &head,node* &tail){
    menu();
    int choice;
    cin.clear();
    cout<<"-----------------------"<<endl;
    cout<<"Enter Your Choice [0-11] : ";
    cin>>choice;
    cout<<"-----------------------"<<endl;
    cin.clear();
    cin.ignore();
    switch (choice){
        case 0:
            choice0(head);
            execute(head,tail);
            break;
        case 1:
            choice1(head,tail);
            choice0(head);
            execute(head,tail);
            break;
        case 2:
            choice2(head,tail);
            choice0(head);
            execute(head,tail);
            break;
        case 3:
            choice3(head,tail);
            choice0(head);
            execute(head,tail);
            break;
        case 4:
            choice4(head);
            choice0(head);
            execute(head,tail);
            break;
        case 5:
            choice5(head);
            choice0(head);
            execute(head,tail);
            break;
        case 6:
            choice6(head,tail);
            choice0(head);
            execute(head,tail);
            break;
        case 7:
            choice7(head);
            choice0(head);
            execute(head,tail);
            break;
        case 8:
            choice8(head);
            choice0(head);
            execute(head,tail);
            break;
        case 9:
            choice9(head,tail);
            choice0(head);
            execute(head,tail);
            break;
        case 10:
            choice10(head);
            choice0(head);
            execute(head,tail);
            break;
    }
}
int main()
{
    node* head = NULL;
    node* tail = NULL;
    execute(head,tail);
    // head = insertAtEnd(head,tail,6);
    // head = insertAtEnd(head,tail,7);
    // head = insertAtEnd(head,tail,8);
    // head = insertAtEnd(head,tail,9);
    // head = insertAtHead(head,tail,2);
    // display(head);
    // //----------------------------------
    // cout<<endl;
    // node * preTail = tail;
    // head = reverse(head,tail);
    // head = preTail;
    // display(head);
    // cout<<endl;
    // displayReverse(tail);
    // execute(head);
    return 0;
}