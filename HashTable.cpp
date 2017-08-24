#include "HashTable.h"

HashTable::HashTable()
{
    for(int i = 0; i < tableSize; i++){
        hashTable[i] = new item;
        hashTable[i]->name = "empty";
        hashTable[i]->drink = "empty";
        hashTable[i]->next = NULL;
    }
}

int HashTable::hashFunction(string key){
    int hashValue = 0;
    int index;
    index = key.length();

    for(int i = 0; i < key.length(); i++){
        hashValue = hashValue + (int)key[i];
    }
    index = hashValue % tableSize;
    return index;
}

void HashTable::addItem(string name, string drink){
    int index = hashFunction(name);
    cout<<"debugging here with index " << index << " and name " + name<< endl;
    if(hashTable[index]->name  == "empty"){
        hashTable[index]->name = name;
        hashTable[index]->drink = drink;
    }
    else{
        item* ptr = hashTable[index];
        item* n = new item;
        n->name = name;
        n->drink = drink;
        n->next = NULL;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = n;
    }
}

int HashTable::numberOfItemsInABucket(int index){
    int count = 0;
    if(hashTable[index]->name == "empty"){
        return count;
    }
    else{
        item* ptr = hashTable[index];
        while(ptr->next != NULL){
            count++;
            ptr = ptr->next;
        }
    }
    return count;
}

void HashTable::printTable(){
    int number;
    for(int i = 0; i < tableSize; i++){
        number = numberOfItemsInABucket(i);
        cout<< "--------------------\n";
        cout<< "index : ";
        cout<< i << endl;
        cout<<hashTable[i]->name << endl;
        cout<<hashTable[i]->drink << endl;
        cout<<"# of items in the bucket " << number <<endl;
        cout<< "--------------------\n";
    }
}

void HashTable::printItemsInIndex(int index){
    item* ptr = hashTable[index];
    if(ptr->name == "empty"){
        cout<< "index = " << index << " is emptty."<<endl;
    } else {
        cout<< "index = " << index << " contains the following items\n";
        while(ptr != NULL){
            cout<< "----------------\n";
            cout<< "Name: " << ptr->name << endl;
            cout<< "Drink: " << ptr->drink << endl;
            cout<< "----------------\n";
            ptr = ptr->next;
        }
    }
}

void HashTable::findDrink(string name){
    int index = hashFunction(name);
    item* ptr = hashTable[index];
    string drink;
    bool isNameFounded = false;

    while(ptr!= NULL){
        if(ptr->name == name){
            isNameFounded = true;
            drink = ptr->drink;
        }
        ptr = ptr->next;
    }
    if(isNameFounded){
        cout<<"FavouriteDrink: " << drink << endl;
    } else {
        cout << name << "'s info was not found in the table." << endl;
    }
}
