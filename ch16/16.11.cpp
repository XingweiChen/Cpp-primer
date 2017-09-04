template <typename elemType> class ListItem;
template <typename elemType> class List{
public:
    List<elemType>();
    List<elemType>(const List<elemType> &);
    List<elemType>& operator=(const List<elemType> &);
    ~List();
    // type of ListItem class should be specified here
    void insert(ListItem<elemType> *ptr, elemType value);
private:
    // type of ListItem class should be specified here
    ListItem<elemType> *front, *end;
};

int main(){
    return 0;
}
