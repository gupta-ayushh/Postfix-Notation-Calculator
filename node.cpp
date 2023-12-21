#include<iostream>
#include"node.h"
#include<stdexcept>
using namespace std;
Node::Node(bool sentinel){
    sentinel=true;
    is_sentinel=sentinel;
    next=NULL;
    prev=NULL;
}

Node::Node(int v, Node* nxt, Node* prv){
    value=v;
    next=nxt;
    prev=prv;
    is_sentinel=false;
}

bool Node:: is_sentinel_node(){
    return is_sentinel;
}

int Node::get_value(){
    return value;
}