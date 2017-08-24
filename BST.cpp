#include "BST.h"
#include <cstddef>
#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
BST::BST()
{
    root == NULL;
}

BST::node* BST::createLeaf(int key){
    node * newNode = new node;
    newNode->key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void BST::addLeaf(int key){
    addLeafPrivate(key, root);
}

void BST::addLeafPrivate(int key, node* newNode){
    //Tree is empty
    if(root == NULL){
        root = createLeaf(key);
    }
    //Left child
    else if(key < newNode->key){
        if(newNode->left != NULL){
            addLeafPrivate(key, newNode->left);
        }
        else{
            newNode->left = createLeaf(key);

        }
    }
    //Right CHild
    else if(key > newNode->key){
        if(newNode->right != NULL){
            addLeafPrivate(key, newNode->left);
        }
        else{
            newNode->right = createLeaf(key);

        }
    }
    else{
        //cout<<"The key has been already added"<<endl;
    }
}

void BST::printInOrder(){
    printInOrderPrivate(root);
}

void BST::printInOrderPrivate(node* root){
    if(root != NULL){
        if(root->left != NULL){
            printInOrderPrivate(root->left);
        }
        cout<<root->key<<" ";
        if(root->right != NULL){
            printInOrderPrivate(root->right);
        }
    }
    else{
        cout<<"Empty tree"<<endl;
    }
}

BST::node* BST::returnNode(int key){
    return returnNodePrivate(key, root);
}

BST::node* BST::returnNodePrivate(int key, node* root){
    if(root != NULL){
        if(root->key == key){
            return root;
        } else {
            if(key < root->key){
                returnNodePrivate(key, root->left);
            }
            else{
                return returnNodePrivate(key, root->right);
            }
        }

    }
    else{
        return NULL;
    }
}
int BST::returnRootKey(){
    if(root != NULL){
        return root->key;
    } else {
        return -100;
    }
}

void BST::printChildren(int key){
    node* child = returnNode(key);
    if(child != NULL){
        child->left == NULL ?
        std::cout<<"Left child == NULL \n":
        cout<<"Left child key == " + child->left->key<<endl;

        child->right == NULL ?
        cout<<"right child == NULL \n":
        cout<<"right child key == " + child->right->key<<endl;
    } else {
        cout<<"KEY IS NOT AVAILABLE";
    }
}

int BST::findSmallest(){
    findSmallestPrivate(root);
}

int BST::findSmallestPrivate(node* parent){
    if(root == NULL){
        cout<<"Tree is empty"<<endl;
        return -1000;
    }
    else {
        if(parent->left == NULL){
            return findSmallestPrivate(parent->left);
        } else {
            return parent->key;
        }
    }
}

 void BST::removeNode(int key){
    removeNodePrivate(key, root);
 }

 void BST::removeNodePrivate(int key, node* parent){
    if(root == NULL){
        cout<<"Tree is empty"<<endl;
        return;
    }
    else{
        if(root->key){
            removeRootMatch();
        } else {
            if(key < parent->key && parent->left != NULL){
                parent->left->key == key ?
                    removeMatch(parent, parent->left, true) :
                        removeNodePrivate(key, parent->left);
            }
            else if(key > parent->key && parent->right != NULL){
                parent->right->key == key ?
                    removeMatch(parent, parent->right, false) :
                        removeNodePrivate(key, parent->right);
            }
            else{
                cout<<"The key is not in the tree"<<endl;
            }
        }
    }
 }

void BST::removeRootMatch(){
    if(root != NULL){
        node* delPtr = root;
        int rootKey = root->key;
        int smallestInRightSubtree;

        //Case 0:  root has 0 children
        if(root->left == NULL && root->right == NULL){
            root == NULL;
            delete delPtr;
        }

        //Case 1: 1 child;
        else if(root->left == NULL && root->right != NULL){
            root = root->right;
            delPtr->right = NULL;
            delete delPtr;
            cout<<"The root node with the key: ";
            cout<<rootKey;
            cout<<" was deleted." << "The new root contains: ";
            cout<<root->key << endl;
        }

        else if(root->left != NULL && root->right == NULL){
            root = root->left;
            delPtr->left = NULL;
            delete delPtr;
            cout<<"The root node with the key: ";
            cout<<rootKey;
            cout<<" was deleted." << "The new root contains: ";
            cout<<root->key << endl;
        }
        //Case 2: 2 children

        else{
            smallestInRightSubtree = findSmallestPrivate(root->right);
            removeNodePrivate(smallestInRightSubtree, root);
            root->key = smallestInRightSubtree;
            cout<<"The root key containing key" << rootKey << "was overwritten with key " << root->key << endl;
        }

    } else {
        cout<<"Can not remove root. The tree is empty"<<endl;
    }
}

void BST::removeMatch(node* parent, node* match, bool isLeft){
    if(root != NULL){
        node* delPtr;
        int matchKey = match->key;
        int smallestInRightSubtree;

        //Case 0;

        if(match->left == NULL && match->right == NULL){
            delPtr = match;
            isLeft == true ? parent->left = NULL : parent->right = NULL;
            delete delPtr;
            cout<< "The node containing key " << matchKey << " was removed"<<endl;
        }
        else if(match->left == NULL && match->right != NULL){
            isLeft == true ? parent->left = match->right : parent->right = match->right;
            match->right = NULL;
            delPtr = match;
            delete delPtr;
            cout<< "The node containing key " << matchKey << " was removed"<<endl;
        }
        else if(match->right == NULL && match->left != NULL){
            isLeft == true ? parent->left = match->left : parent->right = match->left;
            match->left = NULL;
            delPtr = match;
            delete delPtr;
            cout<< "The node containing key " << matchKey << " was removed"<<endl;
        }
        else{
            smallestInRightSubtree = findSmallestPrivate(match->right);
            removeNodePrivate(smallestInRightSubtree, match);
            match->key = smallestInRightSubtree;
        }
    }
    else{
        cout << "cant remove tree is empty" << endl;
    }
}

bool BST::balanced(const node* root) const{
        if (!root) return true;
        return abs(height(root->left) - height(root->right)) < 2 &&
               balanced(root->left) && balanced(root->right);
}

int BST::height(const node* root) const
    {
        if (!root) return 0;
        return 1 + std::max(height(root->left), height(root->right));
    }
int BST::publicHeight(){
    height(root);
}
BST::~BST(){
    deleteAll(root);
}
BST::node* BST::copyTree(const node *subTreeRoot)
{
	if (subTreeRoot == NULL)
		return NULL;
        node* newNode;
        newNode->left = copyTree(subTreeRoot->left);
        newNode->right = copyTree(subTreeRoot->right);
        return newNode;
}
void BST::deleteAll(node *subTreeRoot)
{
	if (subTreeRoot == NULL)
		return;

	deleteAll(subTreeRoot->left);
	deleteAll(subTreeRoot->right);
	delete subTreeRoot;
}
