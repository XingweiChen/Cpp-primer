#include<set>
#include<memory>
#include<iostream>

// auto ftor(std::unique_ptr<int> &l, std::unique_ptr<int> &r) {
//  return *l < *r; 
// }

int main(){
//   std::set<std::unique_ptr<int>, decltype(ftor)> myset(ftor);
  std::set<std::unique_ptr<int>> myset;
  myset.insert(std::make_unique<int>(1));
  myset.insert(std::make_unique<int>(1));

  std::set<std::shared_ptr<int>, std::owner_less<std::shared_ptr<int>>> sset;
  sset.insert(std::make_shared<int>(1));
  sset.insert(std::make_shared<int>(1));
  std::cout << myset.size() << "\n";
  std::cout << sset.size() << "\n";
}