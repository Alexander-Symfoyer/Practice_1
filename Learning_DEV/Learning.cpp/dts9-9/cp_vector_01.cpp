#include <iostream>
#include <vector>


using namespace std;


namespace CP {

    template<typename T>
    class vector{

        protected:
            T *mData;               //* pointer to the dynamic array on the heap
                                    //* stores all vector elements

            size_t mCap;            //* size_t = int but no negative numbers
                                    //* total number of allocated elements

            size_t mSize;           //* number of elements currently stored            

            void rangecheck(int n) {
                if (n < 0 || (size_t)n >= mSize) {                  //! Type casting 
                                                                    // n = int but mSize = size_t
                                                                    // (size_t)n for change type, make it comparable

                    throw std::out_of_range("index out of range");
                }
            }
            
            void expand(size_t capacity) {
                T *arr = new T[capacity]();                 // new array has a request capacity
                for (size_t i = 0; i < mSize; i++) {        // copy from the old array to new array
                    arr[i] = mData[i];
                }                               
                delete [] mData;                            // release the old array
                mData = arr;                                // make data point to the new array (move pointer)
                mCap = capacity;                            // update the current capacity
            }


            void ensurecapacity(size_t capacity) {          // check if the current capacity is enough     
                if (capacity > mCap) {                      

                    //* choose the new capacity
                    // Use the requested capacity if it is larger
                    // Otherwise, double the current capacity

                    size_t s = (capacity > 2 * mSize) ?  capacity : 2 * mCap;       // ? : = ternary operator (if-else)
                    expand(s);
                }
            }

            bool empty() const {
                return mSize == 0;
            }

            size_t size() const {
                return mSize;
            }

            size_t capacity() const {
                retrun mCap;
            }


        public:
            vector() {          //* Default constructor
                int cap = 1;
                mData = new T[cap];
                mCap  = cap;
                mSize = 0;      //? []
            } 

            vector(size_t cap) {   //* constructor with initial size
                mData = new T[cap]();   //! () = value initialize (0)
                mCap = cap;
                mSize = cap;    //? [0,0,0,0,0]
            }

            ~vector() { 
                delete [] mData;
            }

            
            vector(const vector<T> &a) {            //* Copy constructor
                mData = new T[a.capacity] ();
                mCap = a.capacity();
                mSize = a.size();

                for (size_t i = 0; i < a.size(); i++) {
                    mData[i] = a[i];
                }
            }

            vector<T> & operator=(vector<T> &other) {       //* Copy assignment operator
                if (mData != other.mData) {
                    delete [] mData;

                    mData = new T[other.capacity()]();
                    mCap = other.capacity();
                    mSize = other.size();

                    for(size_t i = 0; i < other.size(); i++) {
                        mData[i] = other[i];
                    }
                }
            }

            
            //! - access -

            T& at(int index) {
                rangecheck(index);
                return mData[index];
            }

            T& operator[] (int index) {
                return mData[index];
            }
            

            //! - modifier -

            void push_back(const T& element) {
                ensurecapacity(mSize + 1);          // make sure there is enough space
                mData[mSize++] = element;           //* store the new element at the end
                                                    //* then increase size by 1
            }

            void pop_back() {                       //* remove the last element
                mSize--;                            //* by decreasing the current size
            }

            

    };

}


int main() {

    CP::vector<int> w(5);



}