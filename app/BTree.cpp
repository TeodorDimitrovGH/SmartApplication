#include "BTree.h"
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#define MARKER -1
using namespace std;

template <typename T>
BTree<T>::BTree()
{
    root = NULL;
}

template <typename T>
void BTree<T>::addNode(T data){
    addNode(data, root);
}

template <typename T>
void BTree<T>::addNode(T data, Node<T>* nodePtr){
    if(root == NULL){
        root = createNode(data);
    } else {
        if(data > nodePtr->data){
            if(nodePtr->right != NULL){
                addNode(data, nodePtr->right);
            } else {
                nodePtr->right = createNode(data);
            }
        } else if(data < nodePtr->data) {
            if(nodePtr->left != NULL){
                addNode(data, nodePtr->left);
            } else {
                nodePtr->left = createNode(data);
            }
        }
    }
}

template <typename T>
Node<T>* BTree<T>::createNode(T data){
    Node<T>* newNode = new Node<T>;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

template <typename T>
void BTree<T>::printInOrder(){
    printInOrder(root);
}

template <typename T>
void BTree<T>::printPostOrder(){
    printPostOrder(root);
}

template <typename T>
void BTree<T>::printPreOrder(){
    printPreOrder(root);
}

template <typename T>
void BTree<T>::printInOrder(Node<T>* nodePtr){
    if(nodePtr == NULL){
        return;
    }

    printInOrder(nodePtr->left);
    cout << nodePtr->data << " ";
    printInOrder(nodePtr->right);
}

template <typename T>
void BTree<T>::printPostOrder(Node<T>* nodePtr){
    if(nodePtr == NULL){
        return;
    }

    printPostOrder(nodePtr->left);
    printPostOrder(nodePtr->right);
    cout << nodePtr->data << " ";
}

template <typename T>
void BTree<T>::printPreOrder(Node<T>* nodePtr){
    if(nodePtr == NULL){
        return;
    }

    cout << nodePtr->data << " ";
    printPreOrder(nodePtr->left);
    printPreOrder(nodePtr->right);
}

template <typename T>
void BTree<T>::printLevelOrder(Node<T>* root){
    int treeHeight = height(root);
    cout<<"got height " << treeHeight;
    for(int i = 1; i <= treeHeight; i++){
        printGivenLevel(root, i);
    }
}

template <typename T>
void BTree<T>::printGivenLevel(Node<T>* root, int level){
    if(root == NULL){
        return;
    }
    if(level == 1){
        cout << root->data << " ";
    } else {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

template <typename T>
int BTree<T>::height(Node<T>* treeRoot){
    if(treeRoot == NULL){
        return 0;
    } else {
        int lheight = height(treeRoot->left);
        int rheight = height(treeRoot->right);
        if(lheight > rheight)
            return lheight + 1;
        return rheight + 1;
    }
}

template<typename T>
void BTree<T>::printLevelOrder(){
    printLevelOrder(root);
}
template<typename T>
void BTree<T>::removeNode(int key){
    removeNode(key, root);
}
template<typename T>
void BTree<T>::removeNode(int key, Node<T>* nodePtr){
    if(root == NULL){
        cout << "Empty Tree" << endl;
    } else {
        if(root->data == key){
            removeRootMatch();
        } else if(key > nodePtr->data && nodePtr->right != NULL){
            if(nodePtr->right->data == key){
                removeMatch(nodePtr, nodePtr->right, false);
            } else {
                removeNode(key, nodePtr->right);
            }
        } else if(key < nodePtr->data && nodePtr->left != NULL){
            if(nodePtr->left->data == key){
                removeMatch(nodePtr, nodePtr->left, true);
            } else {
                removeNode(key, nodePtr->left);
            }
        }
    }
}

template<typename T>
void BTree<T>::removeRootMatch(){
    int rootKey = root->data;
    int smallestInSubtree;
    Node<T>* delPtr;
    if(root->left == NULL && root->right == NULL){
        root = NULL;
        delPtr = root;
        delete delPtr;
    } else if(root->left != NULL && root->right == NULL){
        delPtr = root;
        root = root->left;
        delPtr->left = NULL;
        delete delPtr;
    } else if(root->left == NULL && root->right != NULL){
        delPtr = root;
        root = root->right;
        delPtr->right = NULL;
        delete delPtr;
    } else {
        smallestInSubtree = getSmallestValue(root->right);
        removeNode(smallestInSubtree);
        root->data = smallestInSubtree;
    }
}

template<typename T>
void BTree<T>::removeMatch(Node<T>* parent, Node<T>* current, bool isLeft){
    Node<T>* delPtr;
    int smallesInSubTree;
    if(current->left == NULL && current->right == NULL){
        current = NULL;
        delPtr = current;
        delete delPtr;
    } else if(current->left != NULL && current->right == NULL){
        delPtr = current;
        current = current->left;
        if(isLeft){
            parent->left = current;
        } else {
            parent->right = current;
        }
        delPtr->left = NULL;
        delete delPtr;
    } else if(current->left == NULL && current->right != NULL){
        delPtr = current;
        current = current->right;
        if(isLeft){
            parent->left = current;
        } else {
            parent->right = current;
        }
        delPtr->right = NULL;
        delete delPtr;
    } else if(current->left != NULL && current->right != NULL){
        smallesInSubTree = getSmallestValue(current->right);
        removeNode(smallesInSubTree);
        current->data = smallesInSubTree;
    }
}

template <typename T>
T BTree<T>::getSmallestValue(){
    return getSmallestValue(root);
}

template <typename T>
T BTree<T>::getSmallestValue(Node<T>* root){
    if(root == NULL){
        return -12312312;
    } else {
        Node<T>* currentNode = root;
        while(currentNode->left!= NULL){
            currentNode = currentNode->left;
        }
        return currentNode->data;
    }
}

template<typename T>
Node<T>* BTree<T>::copyTree(const Node<T> *subTreeRoot)
{
	if (subTreeRoot == NULL)
		return NULL;

	return new Node<T>(subTreeRoot->data,
		copyTree(subTreeRoot->left),
		copyTree(subTreeRoot->right));
}
template <typename T>
void BTree<T>::serialize(FILE *fp){
    serialize(root, fp);
}

template <typename T>
void BTree<T>::serialize(Node<T> *root, FILE *fp)
{
    // If current node is NULL, store marker
    if (root == NULL)
    {
        fprintf(fp, "%d ", MARKER);
        return;
    }

    // Else, store current node and recur for its children
    fprintf(fp, "%d ", root->data);
    serialize(root->left, fp);
    serialize(root->right, fp);
}

template <typename T>
void BTree<T>::deSerialize(FILE *fp){
    deSerialize(root, fp);
}
template <typename T>
void BTree<T>::deSerialize(Node<T> *&root, FILE *fp)
{
    int val;
    if ( !fscanf(fp, "%d ", &val) || val == MARKER)
       return;

    root = createNode(val);
    deSerialize(root->left, fp);
    deSerialize(root->right, fp);
}
template <typename T>
void BTree<T>::removeSubTree(Node<T>* root){
    if(root == NULL){
        return;
    }

    removeSubTree(root->left);
    removeSubTree(root->right);
    cout << "removing: " << root->data << endl;
    delete root;
}
template <typename T>
BTree<T>::~BTree()
{
    removeSubTree(root);
}
