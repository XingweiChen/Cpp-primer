#include<iostream>
#include<set>
#include<memory>
#include<string>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<iterator>




int main(){
    struct Car{
    	int data;
    	Car(): data{1} {}
    };
    // std::set<std::shared_ptr<Car>> test_set;
    std::vector<std::weak_ptr<Car>> vc;
    std::shared_ptr<Car> sptr = std::make_shared<Car>();
    std::weak_ptr<Car> wptr = sptr;
    vc.push_back(wptr);
    sptr.reset();
    std::cout << vc.size() << "\n";
    std::cout << vc[0].expired() << "\n";
    auto it = vc.begin();
    while(it != vc.end()){
        if(it -> expired()){
            vc.erase(it);
            std::cout << "reset" << "\n";
        }else{
            it++;
        }
    }
    std::cout << vc.size() << "\n";
}
