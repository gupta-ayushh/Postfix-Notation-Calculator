#include<iostream>
#include<stdexcept>
#include"stack_a.h"

using namespace std;

Stack_A:: Stack_A(){
        int stk[1024];
        size=0;
}

void Stack_A::push(int data){
        if(size==1024){
            throw runtime_error("Stack Full");
        }
        else{
            stk[size]=data;
            size++;
        }
    }

int Stack_A::pop(){
        if(size==0){
            throw runtime_error("Empty Stack");
        }
        else{
            return stk[--size];
        }
    }

int Stack_A::get_element_from_top(int idx){
        if((size-1-idx)<0){
            throw runtime_error("Index out of Storage");
        }
        else{
        return stk[size-1-idx];
        }
    }

int Stack_A::get_element_from_bottom(int idx){
        if((idx)>=size){
            throw runtime_error("Index out of Storage");
        }
        else{
        return stk[idx];
        }
    }

void Stack_A::print_stack(bool top_or_bottom){
        if(top_or_bottom){
            for(int i=size-1;i>-1;i--){
                cout<<stk[i]<<endl;
            }
        }
        else{
            for(int i=0;i<size;i++){
                cout<<stk[i]<<endl;
            }
        }
    }

int Stack_A::add(){
        if(size<=1){
            throw runtime_error("Not Enough Arguments");
        }
        else{
            stk[size-2]+=stk[size-1];
            size--;
            return stk[size-1];
        }
    }

int Stack_A::subtract(){
        if(size<=1){
            throw runtime_error("Not Enough Arguments");
        }
        else{
            stk[size-2]-=stk[size-1];
            size--;
            return stk[size-1];
        }
    }

int Stack_A::multiply(){
        if(size<=1){
            throw runtime_error("Not Enough Arguments");
        }
        else{
            stk[size-2]*=stk[size-1];
            size--;
            return stk[size-1];
        }
    }

int Stack_A::divide(){
        if(size<=1){
            throw runtime_error("Not Enough Arguments");
        }
        else if(stk[size-1]==0){
            size-=2;
            throw runtime_error("Divide by Zero Error");
        }
        else{
            if(stk[size-2]*stk[size-1]<0){
                stk[size-2]=stk[size-2]/stk[size-1];
                stk[size-2]-=1;
                size--;
                return stk[size-1];
            }
            stk[size-2]/=stk[size-1];
            size--;
            return stk[size-1];
        }
    } 

int* Stack_A::get_stack(){
        return stk;
    }

int Stack_A::get_size(){
        return size;
    }