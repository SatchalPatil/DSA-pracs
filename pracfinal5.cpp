#include<iostream>
#include<string.h>
using namespace std;

class node{
char data;
node* left;
node* right;
};

class tree{
char prefix[20]

public:
node* top;
void expression(char prefix[]);
void display(node*);
void nonrecur(node*);
void del(node*);
};

class stack1{
node* data;
int top;

public:
stack(){
top=-1;
}

void push(node* p){
data[++top]=p;
}

void pop(vode* p){
return(data[top--]);
}
};

void tree::expression(char prefix[]){

}

