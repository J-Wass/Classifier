#include <iostream>
#include <memory>
#include <vector>
#include "neuralnet.cpp"
using namespace std;

int main(){
  vector<int> hidden_layer_shape{2,2};
  NeuralNet *net = new NeuralNet(5u, 3u, hidden_layer_shape);
  //build dataset
  //train on dataset
  //fit on something
  cout << net->to_string() << "\n";
  delete net;
  return 0;
}
