#include <iostream>

using namespace std;

namespace CP {

    template<typename T>            //? : = initializer list
    class node {                    //? { } = constructor body (empty)

        public:
            T data;                 //* Store the value
            node *next;             //* Point to the next node

            node() :                //* Create an empty node
                data(T()),        //* Initialize data with default value                    
                next(nullptr)        //* No next node yet
                { }
        
            node(const T& data, node* next) :    //* Create a node with data and a next pointer
                data(data),       //* Copy given value into this node
                next(next)        //* Connect this node to next node
                { }
            

    };

}

int main() {

    CP::node<int> *p = nullptr;                 //? Point to nothing
    p = new CP::node<int>(10, nullptr);

    CP::node<int> *q = nullptr;
    q = new CP::node<int>(20,nullptr);

    p->next = q;                                    //* Connect first node to the second node
    q->next = new CP::node<int>(30,nullptr);        //* Connect second node to third node

    p = p->next->next;              //* p -> [30]
    q = p;                          //* Make q point to the same node as p
    q = q->next;                    //* q -> [nullptr]

    cout << p << '\n';
    cout << q << '\n';

}