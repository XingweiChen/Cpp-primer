class Sales_data{ };

template<typename T> bool compare(const T& o1, const T& o2){
    if (o1 == o2)
        return 0;
    else if (o1 < o2)
        return -1;
    return 1;
}

int main(){
    Sales_data num1, num2;
    compare(num1, num2);
}

/*

16.3.cpp: In instantiation of ‘bool compare(const T&, const T&) [with T = Sales_data]’:
16.3.cpp:13:23:   required from here
16.3.cpp:4:12: error: no match for ‘operator==’ (operand types are ‘const Sales_data’ and ‘const Sales_data’)
     if (o1 == o2)
            ^
16.3.cpp:6:17: error: no match for ‘operator<’ (operand types are ‘const Sales_data’ and ‘const Sales_data’)
     else if (o1 < o2)
*/
