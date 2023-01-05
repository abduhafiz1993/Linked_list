// double linkeed list
#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
    node *pre;
};
struct node *head = NULL;
void atbeigning(int firstData){
    node *temp,*temp1;
    
    temp = new node;
    temp->data =firstData;
    temp->pre=NULL;
    temp->next=NULL;

    if(head==NULL){
        head=temp;
        head->next= NULL ;
        head->pre=NULL;
    }
    else{
    	temp->next=head;
        temp->pre=NULL;
        head->pre=temp;
        head=temp;
    }
}
void insert(int aData){
    node *temp,*temp1;
    
    temp = new node;
    temp->data =aData;
    temp->next = NULL;

    
    if(head == NULL){
        head =temp;
        head->next =NULL;
        head->pre=NULL;
    }
    else{
        temp1=head;
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
        temp->next=NULL;
        temp->pre=temp1;
        temp1->next=temp;

    }

}
void atSpecficPlace(int aData, int n){
    node *temp,*temp1;
    
    temp = new node;
    temp->data =aData;
    temp->next = NULL;
    temp->pre = NULL;
    temp1=head;
    for(int i=1; i<n; i++){
        temp1=temp1->next;
    }
    temp->next=temp1;
    temp->pre=temp1->pre;
    temp1->pre->next=temp;
    temp1->pre=temp;
}
void deleteAtSpecificPlace(int n){
    node *temp, *pre;
    temp=head;
    if(n!=1){
    for(int i=1; i<n; i++){
        temp=temp->next;
    }
    temp->pre->next=temp->next;
    temp->next->pre=temp->pre;
    delete temp;
    }else{
    temp->next->pre=NULL;
    head=temp->next;
    delete temp;
}
}
void display(){
    node *temp;
    if(head==NULL){
        cout<<"There is no list to display";
    }
    else{
    temp=head;
    while(temp->next!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
    }
}

void displayInversly(){
    node *temp, *temp1;;
    if(head==NULL){
        cout<<"There is no list to display";
    }
    else{
    temp=head;
    while(temp->pre!= head){
    	temp1=temp-;
    }

    while(temp->next!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
    }
}

int main(){
	atbeigning(4);
    insert(5);
    insert(6);
    insert(7);
    insert(8);
    insert(9);
    display();
    atbeigning(3);
    //displayInversly();
    display();
    atSpecficPlace(3,4);
    display();
    deleteAtSpecificPlace(1); 
    display();


    return 0; 
}