#include<iostream>
#include<stdexcept>
#include"stack_c.h"
using namespace std;
Stack_C:: Stack_C(){
    try{
        stk=new List();
    }
    catch(bad_alloc &e){
        throw runtime_error("Out of Memory");
    }
}
Stack_C::~Stack_C(){
    delete stk;
}

void Stack_C::push(int data){
    stk->insert(data);
}

int Stack_C::pop(){
        if(stk->get_size()<=0){
            throw runtime_error("Empty Stack");
        }
        else{
            int x=stk->delete_tail();
            return x;
        }
    }

int Stack_C::get_element_from_top(int idx){
    int s=stk->get_size();
        if((s-1-idx)<0||idx<0){
            throw runtime_error("Index out of range");
        }
        else{
            //return stk[s-1-idx];
            Node* temp=stk->get_head();
            for(int i=0;i<(s-idx);i++){
                temp=temp->next;
            }
            int v=temp->get_value();
            return v;
        }
}

int Stack_C::get_element_from_bottom(int idx){
    int s=stk->get_size();
        if((idx)>=s||idx<0){
            throw runtime_error("Index out of range");
        }
        else{
            Node *temp=stk->get_head();
            for(int i=0;i<=idx;i++){
                temp=temp->next;
            }
            int v=temp->get_value();
            return v;
        }
    }

void Stack_C::print_stack(bool top_or_bottom){
    int s=stk->get_size();
    Node* temp=stk->get_head();
        if(top_or_bottom!=0){
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp=temp->prev;
            for(int i=0;i<s;i++){
                int x=temp->get_value();
                cout<<x<<"\n";
                temp=temp->prev;
            }
        }
        else{
                temp=temp->next;
            for(int i=0;i<s;i++){
                int x=temp->get_value();
                cout<<x<<"\n";
                temp=temp->next;
            }
        }
    }

int Stack_C::add(){
    int s=stk->get_size();
    // Node* temp=stk->get_head();
    // while(temp->next!=NULL){
    //     temp->prev=temp;
    //     temp=temp->next;
    //     temp->next=temp->next->next;
    // }
    // temp->next=temp;
    // temp=temp->prev;
    // temp->prev=temp->prev->prev;
    // int s=stk->get_size();
        if(s<=1){
            throw runtime_error("Not Enough Arguments");
        }
        else{
            int x=stk->delete_tail();
            int y=stk->delete_tail();
            stk->insert(x+y);
            return x+y;
        }
            // for(int i=0;i<s;i++){
            //     int x=temp->get_value();
            //     cout<<x<<endl;
            //     temp->next=temp;
            //     temp=temp->prev;
            //     temp->prev=temp->prev->prev;
            // }
    }

int Stack_C::subtract(){
    int s=stk->get_size();
    
    if(s<=1){
        throw runtime_error("Not Enough Arguments");
    }
    else{
            int x=stk->delete_tail();
            int y=stk->delete_tail();
            stk->insert(y-x);
        return y-x;
    }
    }

int Stack_C::multiply(){
    int s=stk->get_size();
    if(s<=1){
        throw runtime_error("Not Enough Arguments");
    }
    else{
        int x=stk->delete_tail();
        int y=stk->delete_tail();
        stk->insert(y*x);
        return x*y;
    }
}

int Stack_C::divide(){
    int s=stk->get_size();
    if(s<=1){
        throw runtime_error("Not Enough Arguments");
    }
    else{
        int v=stk->delete_tail();
        int w=stk->delete_tail();
        if(v==0){
            throw runtime_error("Divide by Zero Error");
        }
        else{
            if(v*w<0){
                w=w/v;
                w-=1;
                stk->insert(w);
                return w;
            }
            else{
                w=w/v;
                stk->insert(w);
                return w;
            }
        }
    }
}

List* Stack_C::get_stack(){
        return stk;
    }

int Stack_C::get_size(){
        return stk->get_size();
    }
