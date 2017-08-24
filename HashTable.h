#ifndef HASHTABLE_H
#define HASHTABLE_H
#include<iostream>
#include<string>
using namespace std;


class HashTable
{
    public:
        HashTable();
        int hashFunction(string key);
        void addItem(string name, string drink);
        int numberOfItemsInABucket(int index);
        void printTable();
        void printItemsInIndex(int index);
        void findDrink(string name);

    protected:

    private:
        static const int tableSize = 10;

        struct item{
            string name;
            string drink;
            item* next;
        };

        item* hashTable[tableSize];
};

#endif // HASHTABLE_H
