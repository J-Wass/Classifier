#include <iostream>
#include <memory>
#include <vector>
#include "neural_net.cpp"

int main(){
  std::vector<int> hidden_layer_sizes{4,2};
  std::unique_ptr<Neural_Net> net(new Neural_Net(hidden_layer_sizes, 4, 2));
  std::cout << net->to_string() << "\n";
  return 0;
}
