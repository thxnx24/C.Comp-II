#include <iostream>
using namespace std;

template <class T>
class Stack
{
    public:
        Stack():top(0){ }
        ~Stack() {
            while (isEmpty()) {
              pop();
            }
            isEmpty();
        }

        void push(const T& object);
        T pop();
        bool isEmpty();
    
    private:
        struct StackNode {
            T data;
            StackNode *next;

            StackNode(const T& newData, StackNode *nextNode)
                :data(newData), next(nextNode) {}
        };
        StackNode *top;
};

template <class T>
bool Stack<T>::isEmpty() {
    if (top == 0) {
        return true;
    }
    else 
        return false;
}

template <class T>
void Stack <T>::push (const T& obj) {

}

template <class T>
T Stack<T>::pop() {

}