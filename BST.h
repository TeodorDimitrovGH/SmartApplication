#ifndef BST_H
#define BST_H


class BST
{
     private:
        struct node{
            int key;
            node* left;
            node* right;
        };

        node* root;
        void addLeafPrivate(int key, node* root);
        void printInOrderPrivate(node* root);
        node* returnNodePrivate(int key, node* root);
        int findSmallestPrivate(node* root);
        void removeNodePrivate(int key, node* root);
        void removeRootMatch();
        void removeMatch(node* parent, node* match, bool isLeft);
        void removeSubTree(node* Ptr);
        bool balanced (const node* root) const;
        int height(const node* root) const;
        node* copyTree(const node *subTreeRoot);
        void deleteAll(node *subTreeRoot);

    public:
        BST();
        node* createLeaf(int key);
        void addLeaf(int key);
        void printInOrder();s
        node* returnNode(int key);
        int returnRootKey();
        void printChildren(int key);
        int findSmallest();
        void removeNode(int key);
        int publicHeight();
        ~BST();
    protected:



};

#endif // BST_H
