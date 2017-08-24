#ifndef STACK_H
#define STACK_H
#include <string>
using namespace std;

template <class T>
 struct StackItem{
    string name;
    T value;
    StackItem<T>* previous;
 };

 template <typename T>
class Stack
{
    private:
        StackItem<T>* stackPtr;
    public:
        Stack();
        ~Stack();
        void push(string name, T value);
        void pop();
        void readItem(StackItem<T>* item);
        void printStack();
        friend std::ostream& operator<<(std::ostream &strm, const Stack<T>* myStack);
    protected:


};

#endif // STACK_H
