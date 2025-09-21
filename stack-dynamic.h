#pragma once
#include <string>
#include "Node.h"
using namespace std;
template <typename mytype>
class stackdynamic{
    node<mytype> *top;
    public:
    stackdynamic(){
        top=NULL;
    }
    stackdynamic(stackdynamic& b)
	{
		stackdynamic temps;
		node<mytype>* temp = b.top;
		while (temp != NULL)
		{
			temps.push(temp->data);  // to hold values
			temp = temp->next;
		}
	    temp =temps.top;
		while (temp != NULL)
		{
			push(temp->data);
			temp = temp->next;   // to reverse it
		}
	}
    bool empty(){
        return (top==NULL);
    }
    void push(mytype value){
        node<mytype>* temp=new node<mytype>(value);
        temp->next=top;
        top=temp;
    }
    void pop(){
        if(top!=NULL){
            node<mytype> *temp=top;
            top=top->next;
            delete temp;
        }
    }
    void topdata(){
        if(top!=NULL){
            cout<<top->data<<endl;
        }
    }
    ~stackdynamic()
	{
		while (top != NULL)
		{
			pop();
		}
	}
};
