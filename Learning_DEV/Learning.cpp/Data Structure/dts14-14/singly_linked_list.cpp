#include <iostream>


using namespace std;


namespace CP {

    template<typename T>
    class list {

        public:
            class node {

                friend class list;      //* Allow list to access node's protected/private members
                                        //* Node is an inner class
                public:
                    T data;
                    node *next;
                    
                    node() :
                        data (T()), next(nullptr) { }
                    
                    node(const T& data, node* next) :
                        data(T(data)), next(next) { }

            };
        
        protected:
            node *mFirst;               //* Point to the first node of the linked list
            size_t mSize;
        public:
            list() :                    //* Create an empty list
                mFirst(nullptr),        //* No first node yet
                mSize(0)                
                { }
            
            void clear() {

                while (mFirst != nullptr) {

                    node *temp = mFirst;        //* Save the current first node
                    mFirst = mFirst->next;      //* Move mFirst to the next node
                    delete temp;                //* Delete the old first node

                }
                mSize = 0;
            }

            ~list() { 
                clear();                //! Automatically clear all node when the list is destroyed
            }        

    };

}


int main() {

    CP::list<int>::node *a = nullptr;
    a = new CP::list<int>::node(10, nullptr);

    CP::list<int>::node *b = nullptr;
    b = new CP::list<int>::node(20, nullptr);

    CP::list<int>::node *c = nullptr;
    c = new CP::list<int>::node(40, nullptr);

    CP::list<int>::node *d = nullptr;
    d = new CP::list<int>::node(50, nullptr);

    a->next = b;
    b->next = c;
    c->next = d;

    //todo Insertion

    CP::list<int>::node *x = a->next->next;
    CP::list<int>::node *y = new CP::list<int>::node(30, nullptr);

    a->next->next = y;
    y->next = x;

    //todo Erase

    CP::list<int>::node *z = a->next->next;
    a->next->next = z->next;
    delete z;

}