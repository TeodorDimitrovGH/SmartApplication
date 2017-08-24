#ifndef BTREE_H
#define BTREE_H
#include<stdio.h>
template <class T>
struct Node{
    T data;
    Node<T>* left;
    Node<T>* right;
};

template <typename T>
class BTree
{
    public:
        BTree();
        ~BTree();

        void addNode(T data);
        void printInOrder();
        void printPostOrder();
        void printPreOrder();
        void printLevelOrder();
        T getSmallestValue();
        void removeNode(int key);
        void serialize(FILE *fp);
        void deSerialize(FILE *fp);
    protected:

    private:
        Node<T>* root;

        void addNode(T data, Node<T>* root);
        Node<T>* createNode(T data);
        void printInOrder(Node<T>* nodePtr);
        void printPostOrder(Node<T>* nodePtr);
        void printPreOrder(Node<T>* nodePtr);
        int height(Node<T>* treeRoot);
        void printGivenLevel(Node<T>* root, int level);
        void printLevelOrder(Node<T>* root);
        void removeNode(int key, Node<T>* nodePtr);
        void removeRootMatch();
        void removeMatch(Node<T>* parent, Node<T>* current, bool isLeft);
        Node<T>* copyTree(const Node<T> *subTreeRoot);
        T getSmallestValue(Node<T>* root);
        void removeSubTree(Node<T>* root);
        void serialize(Node<T> *root, FILE *fp);
        void deSerialize(Node<T> *&root, FILE *fp);
};

#endif // BTREE_H
