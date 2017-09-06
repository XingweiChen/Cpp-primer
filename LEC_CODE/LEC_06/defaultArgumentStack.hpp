#ifndef DEFAULTARGUMENTSTACK_HPP
#define DEFAULTARGUMENTSTACK_HPP

#include <iostream>
#include <deque>

template <typename,typename> class Stack;

template <typename T, typename CONT>
std::ostream& operator<< (std::ostream &os, const Stack<T, CONT> &s){
    Stack<T, CONT> tmpS = s;
    while(!tmpS.empty()){
        std::cout << tmpS.top() << " ";
        tmpS.pop();
    }
    return os;
}

template <typename T, typename CONT = std::deque<T>> class Stack {
public:
    Stack() = default;
    template<typename CONT2>
    Stack(const Stack<T, CONT2>&);

    friend std::ostream& operator<<<T>(std::ostream &, const Stack<T, CONT> &);
    void push(const T &);
    void pop();
    T& top();
    const T& top() const;
    bool empty() const;

    // add Stack as friend to all other stacks
    template <typename U, typename CONT2> friend class Stack;
private:
    CONT stack_;
};
// stack_ begin and end can not access, it's private.
// we need add Stack as friend to all other stacks
template<typename T, typename CONT>
template<typename CONT2>
Stack<T, CONT>::Stack(const Stack<T, CONT2>& s2):
    stack_{s2.stack_.cbegin(), s2.stack_.cend()} {}


template <typename T, typename CONT>
bool Stack<T, CONT>::empty() const{
    return stack_.empty();
}

template <typename T, typename CONT>
T& Stack<T, CONT>::top(){
    return stack_.back();
}

template <typename T, typename CONT>
const T& Stack<T, CONT>::top() const{
    return stack_.back();
}

template <typename T, typename CONT>
void Stack<T, CONT>::pop(){
    stack_.pop_back();
}

template <typename T, typename CONT>
void Stack<T, CONT>::push(const T& ele){
    stack_.push_front(ele);
}


#endif
