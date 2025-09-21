#pragma once
#include <string>
#include "Node.h"

using namespace std;


template <typename mytype>
class linkedlistdoubly {
    node<mytype>* head;
    node<mytype>* tail;
    
    public:
    linkedlistdoubly() : head(NULL), tail(NULL) {}
    string getnode(int condition){
        static node<mytype>* temporary=head;
        if(condition==0){
            temporary=head;
            return temporary->data;
        }
        else if(condition==1){
            if(temporary->next==NULL)
                return "false";
            temporary=temporary->next;
            return temporary->data;
        }
        else if(condition==-1){
            if(temporary->prev==NULL)
                return "false";
            temporary=temporary->prev;
            return temporary->data;
        }
        return " ";
    }
    void IAS(int value) {
        node<mytype>* temp = new node<mytype>(value);
        if (head != NULL) {
            temp->next = head;
            head->prev = temp;
        } else {
            tail = temp;
        }
        head = temp;
    }

    void DFS() {
        if (head == NULL) {
            cout << "Linked list is empty!" << endl;
            return;
        }
        node<mytype>* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }
        delete temp;
    }

    void IAE(mytype value) {
        node<mytype>* temp = new node<mytype>(value);
        if (tail == NULL) {
            head = tail = temp;
            return;
        }
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }

    void DFE() {
        if (tail == NULL) {
            cout << "Linked list is empty!" << endl;
            return;
        }
        node<mytype>* temp = tail;
        tail = tail->prev;
        if (tail != NULL) {
            tail->next = NULL;
        } else {
            head = NULL;
        }
        delete temp;
    }

    void IAAP(int value, int position) {
        if (position == 1) {
            IAS(value);
            return;
        }
        node<mytype>* temp = new node<mytype>(value);
        node<mytype>* check = head;
        int count = 1;
        while (check != NULL && count < position - 1) {
            check = check->next;
            count++;
        }
        if (check == NULL || check->next == NULL) {
            cout << "Position out of bounds!" << endl;
            delete temp;
            return;
        }
        temp->next = check->next;
        temp->prev = check;
        check->next->prev = temp;
        check->next = temp;
    }

    void DFAP(int position) {
        if (head == NULL) {
            cout << "Linked list is empty!" << endl;
            return;
        }
        if (position == 1) {
            DFS();
            return;
        }
        node<mytype>* temp = head;
        int count = 1;
        while (temp != NULL && count < position) {
            temp = temp->next;
            count++;
        }
        if (temp == NULL) {
            cout << "Position out of bounds!" << endl;
            return;
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev;
        }
        temp->prev->next = temp->next;
        delete temp;
    }
    int deletevalue(mytype name){
        node<mytype>* temp=head;
        int count=1;
        while (temp!=NULL)
        {
            if(temp->data==name){
                break;
            }
            temp=temp->next;
            count++;
        }
        return count;
    }
    int totalnode(){
        node<mytype>*temp=head;
        int count=0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        return count;
    }
    void shuffleNodes() {
        if (!head || !head->next) return;
    
        node<mytype>* temp = head;
        while (temp && temp->next) {
            swap(temp->data, temp->next->data);
            temp = temp->next->next;  // Move two steps
        }
    }
    

    void display() {
        cout << "Printing.....\n";
        node<mytype>* temp = head;
        if (temp == NULL) {
            cout << "Linked list is empty!" << endl;
            return;
        }
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
