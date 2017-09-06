#include<iostream>

template<typename T> class Screen;

// friend function must defined before friend declaration.
template<typename T> Screen<T>
    operator+(const Screen<T>& sc1, const Screen<T>& sc2){
        return {sc1.height + sc2.height, sc1.width + sc2.width};
    }

template<typename T> std::ostream& operator<<(std::ostream& os,
    const Screen<T>& sc){
    os << "Height: " << sc.height << "\t" << "Width: " << sc.width;
    return os;
}

template<typename T> std::istream& operator>>(std::istream& is,
    Screen<T>& sc){
    is >> sc.height >> sc.width;
    return is;
}

template<typename T> class Screen{
public:
    Screen<T>(T h, T w): height{h}, width{w} {}

    friend std::ostream& operator<< <T>(std::ostream& os, const Screen<T>& sc);

    friend std::istream& operator>> <T>(std::istream& is, Screen<T>& sc);

    friend Screen<T> operator+ <T>(const Screen<T>& sc1, const Screen<T>& sc2);

private:
    T height;
    T width;
};

int main(){
    Screen<int> sc(100,200);
    std::cout << sc << "\n";
    std::cin >> sc;
    std::cout << sc << "\n";
}
