#ifndef LINKEDLIST_H
#define LINKEDLIST_H


class LinkedList
{
    private:
        typedef struct node{
            int data;
            node* next;

        }* nodePtr;

        nodePtr head;
        nodePtr curr;
        nodePtr temp;
    public:
        LinkedList();
        void addNode(int data);
        void deleteNode(int data);
        void printList();
        int getListLenght();
        int* getListData();
        LinkedList createLinkedListFromArray(int* linkedListValues, int linkedListLength);
        void reverseList();
    protected:
};

#endif // LINKEDLIST_H
