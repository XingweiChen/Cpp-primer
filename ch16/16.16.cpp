#include<memory>


template<typename T> class Vec {
public:
    Vec(): // the allocator member is default initialized
      elements(nullptr), first_free(nullptr), cap(nullptr) {}
    Vec(std::initializer_list<T>);
    Vec(const Vec&);            // copy constructor
    Vec& operator=(const Vec&); // copy assignment
    ~Vec();                        // destructor
    void push_back(const T&);  // copy the element
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    T* begin() const { return elements; }
    T* end() const { return first_free; }
    // ...
private:
    std::allocator<T> alloc; // allocates the elements
    // used by the functions that add elements to the StrVec
    void chk_n_alloc()
        { if (size() == capacity()) reallocate(); }
    // utilities used by the copy constructor, assignment operator, and destructor
    std::pair<T*, T*> alloc_n_copy
        (const T*, const T*);
    void free();             // destroy the elements and free the space
    void reallocate();       // get more space and copy the existing elements

    T* elements;   // pointer to the first element in the array
    T* first_free; // pointer to the first free element in the array
    T* cap;        // pointer to one past the end of the array
};

template<typename T> std::pair<T*, T*>
alloc_n_copy(T* begin, T* end){
    T* data = alloc.allocate(std::distance(begin, end));
    return{data, std::uninitialized_copy(begin, end, data)};
}

// free the memory
template<typename T>
void Vec<T>::free(){
    if(elements){
        alloc.destroy(--first_free);
        alloc.deallocate(elements, capacity());
    }
}


// double the capacity.
template<typename T>
void reallocate()
{
    // calculate the new capacity required
    std::size_t newCapacity = 2 * size();

    // allocate and move old data to the new space
    wy_alloc_n_move(newCapacity);
}



// copy constructor
template<typename T>
Vec<T>::Vec(const Vec &v)
{
    /**
     * @brief newData is a pair of pointers pointing to newly allocated and copied
     *        from range : [b, e)
     */
    std::pair<T*, T*> newData = alloc_n_copy(v.begin(), v.end());

    elements = newData.first;
    first_free = cap = newData.second;
}


// constructor that takes initializer_list<T>
template<typename T>
Vec<T>::Vec(std::initializer_list<T> l)
{
    // allocate memory as large as l.size()
    T* const newData = alloc.allocate(l.size());

    // copy elements from l to the address allocated
    T* p = newData;
    for(const auto &t : l)
        alloc.construct(p++, t);

    // build data structure
    elements = newData;
    first_free = cap = elements + l.size();
}
