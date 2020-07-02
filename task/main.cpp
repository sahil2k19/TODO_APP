#include <iostream>

using namespace std;

class dll{
  public:
    int data;
    dll *next;
    dll *prev;
};
dll *head = NULL;

void push(int data){
  dll *newnode = new dll;
  newnode->data = data;
  newnode->prev = NULL;
  newnode->next = NULL;
  if(head==NULL){
    head = newnode;
    return;
  }
  newnode->next = head;
  head->prev = newnode;
  head = newnode;
  
}

void append(int data){
  dll *newnode = new dll();
  if(!newnode){
    cout<<"memory eror"<<endl;
    return;
  }
  newnode->data = data;
  newnode->next = NULL;
  newnode->prev = NULL;
  
  if(head == NULL){
    head = newnode;
    return;
  }
  dll *temp = head;
  while(temp!=NULL){
    temp = temp->next;
  }
  newnode->prev = temp;
  temp->next = newnode;
}
  

void print(){
  dll *temp=head;
  while(temp!=NULL){
    cout<<temp->data<<" " ;
    temp = temp->next;
  }
}
  

int main(){
  dll n;
  push(1);
  append(2);
  append(3);
  append(4);
  print();
  // insert(3,12);
  // deletenode(3);
  push(10);
  print();
}