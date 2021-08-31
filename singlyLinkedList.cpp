#include<iostream>
using namespace std;
struct node{
    int data;
    struct node* next;
    node(int data){
        this->data = data;
        this->next = NULL;
    }
};
struct node * insertAtEnd(struct node* &head,int data){
    if(head==NULL){
        return new struct node(data);
    } 
    else{
        head->next = insertAtEnd(head->next,data);
        return head;
    } 
}
struct node * insertAtHead(struct node* &head,int data){
    if(head==NULL){
        return new struct node(data);
    } 
    else{
        struct node * top = new struct node(data);
        top->next = head;
        return top;
    } 
}
struct node * insertAtIndex(struct node* &head,int data,int index){
    static int pointer = -1;
    if(pointer==index-1){
        struct node * headNext= new struct node(data);
        headNext->next = head;
        head = headNext;
        return head;
    } 
    else{
        pointer++;
        head->next = insertAtIndex(head->next,data,index);
        return head;
    } 
}
struct node * deleteFromHead(struct node* &head){
    if(head==NULL){
        return NULL;
    } 
    else{
        struct node * thisNode = head;
        free(thisNode);
        return head->next;
    } 
}
struct node * deleteFromTail(struct node* &head){
    if(head->next==NULL){
        free(head);
        return NULL;
    }
    else{
        head->next = deleteFromTail(head->next);
        return head;
    } 
}
struct node * deleteAtIndex(struct node* &head,int index){
    static int pointer = -1;
    if(head==NULL){
        return head;
    }
    else if(pointer==index-1){
        struct node * target = head->next;
        free(head);

        return target;
    }
    else{
        pointer++;
        head->next = deleteAtIndex(head->next,index);
        return head;
    } 
}
void display(struct node* head){
    if (head==NULL){
        cout<<"NULL";
        return;
    }
    else{
        cout<<head->data<<" -> ";
        display(head->next);
    }
}
bool contains(struct node * &head,int data){
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
struct node * discard(struct node * head,int data){
    if (head==NULL){
        cout<<"seems it doesn't exist!"<<endl;
        return NULL;
    }
    else if (head->data == data){
        return head->next;
    }
    else{
        head->next = discard(head->next,data);
        return head;
    }
}
const void menu(void){
    cout<<"---------------------------------------"<<endl;
    cout<<"0.Display Linked List"<<endl;
    cout<<"1.Insert Value"<<endl;
    cout<<"2.Insert At Head"<<endl;
    cout<<"3.Insert At Tail"<<endl;
    cout<<"4.Insert At Specific Index"<<endl;
    cout<<"5.Deletion At Head"<<endl;
    cout<<"6.Deletion At Tail"<<endl;
    cout<<"7.Deletion At Specific Index"<<endl;
    cout<<"8.Discard Element"<<endl;
    cout<<"9.To check that element is present or not"<<endl;
    cout<<"10.Exit"<<endl;
    cout<<"---------------------------------------"<<endl;
}
const void choice0(struct node * &head){
    cout<<endl<<"Linked List : [";
    display(head);
    cout<<"]"<<endl<<endl;
}
const void choice1(struct node * &head){
    int value;
    cout<<"Enter the value  : ";
    cin>>value;
    head = insertAtEnd(head,value);

}
const void choice2(struct node * &head){
    int value;
    cout<<"Enter the value to be inserted at Head : ";
    cin>>value;
    head = insertAtHead(head,value);

}
const void choice3(struct node * &head){
    int value;
    cout<<"Enter the value to be inserted at Tail : ";
    cin>>value;
    head = insertAtEnd(head,value);
}
const void choice4(struct node * &head){
    int value;
    int index;
    cout<<"Enter the value , index : ";
    cin>>value>>index;
    head = insertAtIndex(head,value,index);
}
const void choice5(struct node * &head){
    head = deleteFromHead(head);
}
const void choice6(struct node * &head){
    head = deleteFromTail(head);
}
const void choice7(struct node * &head){
    int index;
    cout<<"Enter index value : ";
    cin>>index;
    head = deleteAtIndex(head,index);
}
const void choice8(struct node * &head){
    int value;
    cout<<"Enter value : ";
    cin>>value;
    head = discard(head,value);
}
const void choice9(struct node * &head){
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
const void execute(struct node * &head){
    menu();
    int choice;
    cin.clear();
    cout<<"-----------------------"<<endl;
    cout<<"Enter Your Choice [0-9] : ";
    cin>>choice;
    cout<<"-----------------------"<<endl;
    cin.clear();
    cin.ignore();
    switch (choice){
        case 0:
            choice0(head);
            execute(head);
            break;
        case 1:
            choice1(head);
            choice0(head);
            execute(head);
            break;
        case 2:
            choice2(head);
            choice0(head);
            execute(head);
            break;
        case 3:
            choice3(head);
            choice0(head);
            execute(head);
            break;
        case 4:
            choice4(head);
            choice0(head);
            execute(head);
            break;
        case 5:
            choice5(head);
            choice0(head);
            execute(head);
            break;
        case 6:
            choice6(head);
            choice0(head);
            execute(head);
            break;
        case 7:
            choice7(head);
            choice0(head);
            execute(head);
            break;
        case 8:
            choice8(head);
            choice0(head);
            execute(head);
            break;
        case 9:
            choice9(head);
            choice0(head);
            execute(head);
            break;
        default :
            break;
    }

}
int main()
{
    struct node* head = NULL;
    execute(head);
    return 0;
}