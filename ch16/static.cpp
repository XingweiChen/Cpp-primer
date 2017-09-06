#include<iostream>

template <typename T> class Foo{
public:
    Foo<T>(T in_f): f{in_f} {ctr ++;}
    void print(){ std::cout << f << std::endl;};
    static std::size_t count() {return ctr;}
private:
    static std::size_t ctr = 0;
    T f;
};

template<typename T>
std::size_t Foo<T>::ctr = 0;


// template<typename T> inline Foo<T>::Foo(T in_f){}

int main(){
    Foo<double> fd1(1),fd2(2);
    fd1.print(); fd2.print();
    // Foo<int> fi1, fi2;
    std::cout << Foo<double>::count() << "\t" << "\n";
}
