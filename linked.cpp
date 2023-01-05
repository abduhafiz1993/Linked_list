// single linkeed list
#include<iostream>
using namespace std;
struct node{
    int data;                                                                           
    node *next;
};
struct node *head = NULL;
void atbeigning(int firstData){
    node *temp;
    
    temp = new node;
    temp->data =firstData;
    temp->next = NULL;

    if(head==NULL){
        head=temp;
    }
    else{
        temp->next=head;
        head =temp;
    }
}
void insert(int aData){
    node *temp,*temp1;
    
    temp = new node;
    temp->data =aData;
    temp->next = NULL;

    
    if(head == NULL){
        head =temp;
    }
    else{
        temp1=head;
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
        temp1->next=temp;

    }

}
void atSpecficPlace(int aData, int n){
    node *temp,*temp1,*pre;
    
    temp = new node;
    temp->data =aData;
    temp->next = NULL;
    temp1=head;
    for(int i=1; i<n; i++){
        pre=temp1;
        temp1=temp1->next;
    }
    pre->next=temp;
    temp->next=temp1;
}
void deleteAtSpecificPlace(int n){
    node *temp, *pre;
    temp=head;
    for(int i=1; i<n; i++){
        pre=temp;
        temp=temp->next;
    }
    pre->next=temp->next;
    delete temp;

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

int main(){
    insert(5);
    insert(6);
    insert(7);
    insert(8);
    insert(9);
    display();
    atbeigning(4);
     display();
    atSpecficPlace(3,4);
     display();
    deleteAtSpecificPlace(5); 
     display();


    return 0; 
}