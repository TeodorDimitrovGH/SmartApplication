#include "LinkedList.h"
#include <cstdlib>
#include <iostream>
using namespace std;


LinkedList::LinkedList()
{
    head = NULL;
    curr = NULL;
    temp = NULL;
}

void LinkedList::addNode(int data){
    cout<<"ADDING NODE"<<endl;
    nodePtr n = new node;
    n->next = NULL;
    n->data = data;

    if(head != NULL){
        curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = n;
    } else {
        head = n;
    }
}

void LinkedList::deleteNode(int data){
    cout<<"PRINTING LIST"<<endl;
    nodePtr deletePtr = NULL;
    temp = head;
    curr = head;
    if(head->data == data){
        deletePtr = head;
        head = head->next;
        delete deletePtr;
        cout<<"Head deleted"<<endl;
        return;
    }
    while(curr != NULL && curr->data != data){
        temp = curr;
        curr = curr->next;
    }
    if(curr == NULL){
        delete deletePtr;
        cout<<"data is not in list"<<endl;
    } else {

        deletePtr = curr;
        curr = curr->next;
        temp->next = curr;
        delete deletePtr;
        cout<<"The value has been deleted"<<endl;
    }
}

void LinkedList::printList(){
    curr = head;
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;

    }
}
int LinkedList::getListLenght(){
    curr = head;
    int length = 0;

    while(curr != NULL){
        length++;
        curr = curr->next;
    }

    return length;
}

int* LinkedList::getListData(){
    int* arrayOfData = new int[getListLenght()];
    int arrayIndex = 0;
    curr = head;
    while(curr != NULL){
        arrayOfData[arrayIndex] = curr->data;
        arrayIndex++;
        curr = curr->next;
    }
    return arrayOfData;
}

LinkedList LinkedList::createLinkedListFromArray(int* linkedListValues, int linkedListLength){
    LinkedList linkedList;
    for(int i = 0; i < linkedListLength; i++){
        linkedList.addNode(linkedListValues[i]);
    }
    return linkedList;
}

void LinkedList::reverseList(){
    curr = head;
    cout<<"reverse called"<<endl;
    nodePtr temp2;
    while(curr != NULL){
        temp = curr->next;
        temp2 = curr;
        curr = curr->next->next;
        temp->next = temp2;
        cout<<"in while" <<endl;
    }
    //delete temp2;
    cout<< "reverse ending" << endl;
    return;
}
