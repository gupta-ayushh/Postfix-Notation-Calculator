#include"list.h"
#include<iostream>
using namespace std;
List::List(){
    try{
        sentinel_head=new Node(true);
        sentinel_tail=new Node(true);
    }
    catch(bad_alloc&e)
    {
        throw runtime_error("Out of Memory");
    }
    size=0;
    sentinel_head->next=sentinel_tail;
    sentinel_tail->prev=sentinel_head;
}

List::~List(){
    Node* temp=sentinel_head;
    while(temp->next!=NULL){
        Node* mem=temp->next;
        delete temp;
        temp=mem;
    }
    delete temp;
}

void List::insert(int v){
    Node* temp=new Node(v,sentinel_tail,sentinel_head);
    if(sentinel_head->next==sentinel_tail){
        sentinel_head->next=temp;
        temp->prev=sentinel_head;
        sentinel_tail->prev=temp;
        temp->next=sentinel_tail;
    }
    else{
        temp->prev=sentinel_tail->prev;
        temp->next=sentinel_tail;
        temp->prev->next = temp ;
        sentinel_tail->prev=temp;
    }
    size++;
}

int List::delete_tail(){
    Node* temp=sentinel_tail->prev;
    sentinel_tail->prev=sentinel_tail->prev->prev;
    sentinel_tail->prev->next=sentinel_tail;
    int m=temp->get_value();
    delete temp;  
    size--;  
    return m;    
}

int List::get_size(){
    return size;
}

Node* List::get_head(){
    Node* n=sentinel_head;
    return n;
}
