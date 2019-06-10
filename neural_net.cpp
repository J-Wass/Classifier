#include <iostream>
#include <vector>
#include <string>

class Neural_Net{
  std::vector<std::vector<int>> hidden_layers;
  std::vector<int> input_layer;
  std::vector<int> output_layer;
public:
  Neural_Net(std::vector<int> hidden_layer_sizes, int input_size, int output_size){
    input_layer = std::vector<int>(input_size);
    output_layer = std::vector<int>(output_size);
    for(int size : hidden_layer_sizes){
      hidden_layers.push_back(std::vector<int>(size));
    }
  }
  std::string to_string();
};

std::string Neural_Net::to_string(){
  return std::to_string(hidden_layers[0].size());
}
