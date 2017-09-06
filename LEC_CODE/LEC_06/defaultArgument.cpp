#include<vector>

#include "defaultArgumentStack.hpp"

int main(){
    Stack<int> s1;
    s1.push(1);
    s1.push(2);

    Stack<int, std::deque<int>> s2 = s1;
    Stack<int, std::vector<int>> s3;

    s3 = s1;
    std::cout << s1 << "\n" << s2 << "\n";
    s1.pop();
    s2.push(3);
    std::cout << s1 << "\n" << s2 << "\n";
}
