#include <iostream>
#include "BTree.cpp"

using namespace std;

int main()
{
    BTree<int> myTree;
    int treeKeys[16] = {50, 76, 21, 4, 32,64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80};
    for(int i = 0; i < 16; i++){
        cout <<"iterating" <<endl;
        myTree.addNode(treeKeys[i]);
    }
    myTree.printInOrder();
    cout<<endl;
    myTree.printPostOrder();
    cout<<endl;
    myTree.printPreOrder();
    cout<<endl;
    myTree.printLevelOrder();
    cout<<endl;
    cout<<endl;
    cout<<endl;
    myTree.printInOrder();
        cout<<endl;

    myTree.removeNode(76);
        myTree.printInOrder();
        cout<<"remove root match breaks it"<<endl;
        myTree.removeNode(50);
        myTree.printInOrder();

        // Let us open a file and serialize the tree into the file
    FILE *fp = fopen("tree.txt", "w");
    if (fp == NULL)
    {
        puts("Could not open file");
        return 0;
    }
    myTree.serialize(fp);
    fclose(fp);

    // Let us deserialize the storeed tree into root1
    fp = fopen("tree.txt", "r");
    myTree.deSerialize(fp);

    return 0;
}
