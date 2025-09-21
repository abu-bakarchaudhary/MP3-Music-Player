#pragma once
template <typename mytype>
struct node {
    mytype data;
    node* next;
    node* prev;
    node(mytype val) : data(val), next(NULL), prev(NULL) {}
};
