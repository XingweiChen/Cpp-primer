#include<vector>
#include<cassert>
#include<functional>
#include<algorithm>

/*
  2018/3/1
  这里用两种方式实现了function作为params的传输
  需要注意的是在func中嵌套是 func本身是地址可以直接传输
  在外界定义函数，它本质上是一个指向函数的指针因此要&
  
  第二种调用了std::function更安全
*/



/* WAY 1 */
// void gradcheck_naive(std::pair<std::vector<double>, double> (*f)(
// std::vector<double>&), std::vector<double> &in_vec) {
//   auto res = f(in_vec);
//   std::cout << res.second << " ";
//   std::copy(res.first.begin(), res.first.end(),
//   std::ostream_iterator<double>(std::cout, " "));
// }

/* WAY 2*/
void gradcheck_naive(std::function<std::pair<std::vector<double>, double>(
                         const std::vector<double> &)>
                         f,
                     const std::vector<double> &in_vec) {
  auto res = f(in_vec);
  double eps = 1e-4;
  std::vector<double> temp;
  std::copy(in_vec.begin(), in_vec.end(), std::back_inserter(temp));
  for(auto i=0U; i <in_vec.size(); ++i){
      temp[i] += eps;
      auto res1 = f(temp);
      temp[i] -= 2 * eps;
      auto res2 = f(temp);
      temp[i] += eps;
      double numgrad = (res1.second - res2.second) / (2 * eps); 
      double reldiff = std::abs(numgrad - res.first[i]) / std::max(std::max(1.0, std::abs(numgrad)), std::abs(res.first[i]));
      assert(reldiff < 1e-5);
  }
}

// lambda x: (np.sum(x ** 2), x * 2)
std::pair<std::vector<double>, double> func(const std::vector<double> &in_vec) {
  double func_x = std::accumulate(
      in_vec.begin(), in_vec.end(), 0.0,
      [](auto left, auto right) { return left + std::pow(right, 2); });
  std::vector<double> out_vec;
  std::transform(in_vec.begin(), in_vec.end(), std::back_inserter(out_vec),
                 [](auto val) { return val * 2; });
  return std::make_pair(out_vec, func_x);
}

int main() {
  // Test Gradient check function
  {
    std::vector<double> test1 = {123.456};
    gradcheck_naive(&func, test1);
    std::vector<double> test2 = {static_cast<double>(rand()) / (RAND_MAX) + 1,
                                 static_cast<double>(rand()) / (RAND_MAX) + 1,
                                 static_cast<double>(rand()) / (RAND_MAX) + 1};
    gradcheck_naive(&func, test2);
  }
}
