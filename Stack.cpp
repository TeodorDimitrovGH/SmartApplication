#include <cstdlib>
#include <iostream>
using namespace std;

#include "Stack.h"
template <typename T>
Stack<T>::Stack(){
    cout << "Initial creation" << endl;
    stackPtr = NULL;
}

template <typename T>
Stack<T>::~Stack(){
    StackItem<T>* firstPointer;
    StackItem<T>* secondPointer;
    firstPointer = stackPtr;

    while(firstPointer != NULL){
        secondPointer = firstPointer;
        firstPointer = firstPointer->previous;
        secondPointer->previous = NULL;
        delete secondPointer;
    }
}

template <typename T>
void Stack<T>::push(string name, T value){
    cout << "Pushing" << endl;
    StackItem<T>* newItem = new StackItem<T>;
    newItem->name = name;
    newItem->value = value;

    if(stackPtr == NULL){
            cout << "Pushing to stackPTr" << endl;
        stackPtr = newItem;
        stackPtr->previous = NULL;
    } else {
        newItem->previous = stackPtr;
        stackPtr = newItem;
        cout <<stackPtr->name << endl;
    }
}

template <typename T>
void Stack<T>::readItem(StackItem<T>* item){
    cout << "-------------" << endl;
    cout<< "name: " << item->name << endl;;
    cout<< "value: " << item->value << endl;
    cout << "-------------" << endl;
}

template <typename T>
void Stack<T>::pop(){
    if(stackPtr == NULL){
        cout << "Empty stack" << endl;
    } else {
        StackItem<T>* delPtr;
        delPtr = stackPtr;
        readItem(delPtr);
        stackPtr = stackPtr->previous;
        delPtr->previous = NULL;
        delete delPtr;
    }
}

template <typename T>
void Stack<T>::printStack(){
    if(stackPtr == NULL){
        cout<< "empty stack" << endl;
    } else {
        StackItem<T>* pointer = new StackItem<T>;
        pointer = stackPtr;
        while(pointer != NULL){
            readItem(pointer);
            pointer = pointer->previous;
        }
    }
}

