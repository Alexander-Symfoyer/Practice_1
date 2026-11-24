#include <iostream>
#include <vector>
#include <stdexcept>
#include <utility>


using namespace std;


namespace CP{
    
    template <typename T>
    class vector{

        protected:
            T *mData;
            size_t mCap;
            size_t mSize;

            void rangecheck(int n) {
                if (n < 0 || (size_t)n >= mSize) {                 
                    throw std::out_of_range("index out of range");
                    }
                }
            
            void expand(size_t capacity) {
                T *arr = new T[capacity]();                 
                for (size_t i = 0; i < mSize; i++) {       
                    arr[i] = mData[i];
                }                               
                delete [] mData;                            
                mData = arr;                                
                mCap = capacity;                            
            }


            void ensurecapacity(size_t capacity) {             
                if (capacity > mCap) {                      

                    size_t s = (capacity > 2 * mSize) ?  capacity : 2 * mCap;      
                    expand(s);
                }
            }

            
        public:
            
            typedef T* iterator;        
                                        //* iterator is an pointer to an element
                                        //* typedef create an alias for *T

                                        //? Ex vector<int>;
                                        //? typedef int* iterator;

            iterator begin() const {
                return &mData[0];       //? mData + 0
            }
            iterator end() const {
                return begin() + mSize;     //? pointing one position past the last element
            }


            iterator insert(iterator it, const T &element) {
                
                size_t pos = it - begin();                  // index where the new element will be inserted (for campare in loop)
                ensurecapacity(mSize + 1);  

                for(size_t i = mSize; i > pos; i--) {       //? Shift one position to the right
                    mData[i] = mData[i-1];                  //! Start from the last element to avoid overwriting data
                }

                mData[pos] = element;                       //* put the new element at the requested position
                mSize++;
                return begin() + pos;                       // return an interator pointing to the inserted element

            }

            void erase(iterator it) {

                while((it + 1) != end()) {          //? shift element one position to the left
                                                    //? to overwrite the element being erased
                    *it = *(it + 1);                
                    it++;                          

                }

                mSize--;                            //* remove the last duplicate element
            }

            void resize(size_t n) {
                
                if (n > mCap) {
                    expand(n);
                }

                if (n > mSize) {
                    T init = T();                               //* Default value of Type T
                                                                //? Ex vector<int> --> int init = int();
                    for (size_t i = mSize; i < n; i++) {        //? [10,20,30]
                        mData[i] = init;                        //? [10,20,30,0,0,0] ( resize(6) )
                    }
                }

                mSize = n;

            }


            vector() {          
                int cap = 1;
                mData = new T[cap];
                mCap  = cap;
                mSize = 0;      
            } 

            vector(size_t cap) {   
                mData = new T[cap]();   
                mCap = cap;
                mSize = cap;    
            }

            ~vector() { 
                delete [] mData;
            }

            
            vector(const vector<T> &a) {            
                mData = new T[a.capacity()]();
                mCap = a.capacity();
                mSize = a.size();

                for (size_t i = 0; i < a.size(); i++) {
                    mData[i] = a[i];
                }
            }

            vector<T> & operator=(vector<T> other) {    
                using std::swap;                        
                swap(this->mSize, other.mSize);
                swap(this->mCap, other.mCap);
                swap(this->mData, other.mData);
                return *this;                          
            }

            //! - access -

            T& at(int index) {                          
                rangecheck(index);
                return mData[index];
            }

            const T& at(int index) const {              
                rangecheck(index);
                return mData[index];
            }


            T& operator[] (int index) {                 
                return mData[index];
            }

            const T& operator[] (int index) const {     
                return mData[index];
            }
            

            void push_back(const T& element) {
                insert(end(), element);
            }

            void pop_back() { 
                if (!empty()){
                    mSize--; 
                }                           
            }

            void clear() {
                mSize = 0;
            }


            bool empty() const {
                return mSize == 0;
            }

            size_t size() const {
                return mSize;
            }

            size_t capacity() const {
                return mCap;
            }


            //! - extra (not-stl) -

            void insert_by_pos(size_t it, const T &element) {
                insert(begin() + it, element);
            }

            void erase_by_pos(int index) {
                erase(begin() + index);
            }

            bool contains(const T& element) {
                return index_of(element) != -1;
            }

            int index_of(const T& element) {
                for(int i = 0; i < mSize; i++) {
                    if (mData[i] == element) {
                        return 1;
                    }
                }
                return -1;
            }

        
        };
    }


void print(const CP::vector<int>& v) {
    for (int i : v) {
        std::cout << i << '\n';
    }
}


int main() {                    //* Test

    CP::vector<int> v1;
    v1.push_back(5);
    v1.push_back(10);
    v1.push_back(15);
    v1.push_back(20);
    v1.push_back(25);

    cout << v1[0] << '\n';
    print(v1);

    cout << v1.empty() << '\n';
    cout << v1.size() << '\n';

    v1.insert(v1.begin() + 4, 30);
    v1.erase(v1.begin() + 1);
    v1.pop_back();
    
    cout << "---------------" << '\n';
    print(v1);

    CP::vector<int> v2 = v1;
    CP::vector<int> v3(v1);

    cout << v2[0] << " " << v3[0] << '\n';

    v1.at(3) = 50;
    cout << v1.at(3) << '\n';

    cout << v1.capacity() << '\n';

    v1.resize(10);
    cout << "-------------------" << '\n';
    print(v1);


    //cout << v1.at(-1) << '\n';      //* Test exception

    cout << v1.contains(50) << '\n';

    v1.insert_by_pos(2, 35);
    v1.insert_by_pos(3, 45);
    v1.erase_by_pos(1);
    print(v1);

    v1.clear();
    cout << v1.empty() << '\n';
}


