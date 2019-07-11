#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <cmath>
#include <sstream>
using namespace std;
//TODO: remove using statement
//TODO: add own namespace
class NeuralNet{
public:
  /**
   * Builds weight and bias matrices
   *
   * @return New instance of a NeuralNet object with random initialized values.
   */
  NeuralNet(unsigned int input_size, int output_size, vector<int> hidden_layer_shape);

  /**
   * Generates a matrix with randomized values.
   *
   * @param x length of matrix.
   * @param y width of matrix.
   * @return matrix with randomized values.
   */
  vector<vector<float>> random_matrix(int x, int y);

  /**
   * Generates a vector with randomized values.
   *
   * @param size Length of requested vector.
   * @return vector with randomized values.
   */
  vector<float> random_vector(int size);

  /**
   * Pretty prints the shape/values of the current net.
   *
   * @return string representation of net.
   */
  string to_string();

private:
  // Vector of Bias Vectors
  vector<vector<float>> biases;

  // Vector of Neuron Activations
  vector<vector<float>> activation;

  //Vector of Weight Matrices
  vector<vector<vector<float>>> weights;

  unsigned int input_size;
};

NeuralNet::NeuralNet(unsigned int _input_size, int output_size, vector<int> hidden_layer_shape){
  //TODO: check input size & output size > 0
  //TODO:check hidden layers is populated and positive
  input_size = _input_size;

  // Add biases/weights for all hidden layers
  cout << hidden_layer_shape.size();
  for(unsigned int i = 0; i < hidden_layer_shape.size(); i++){
    //TODO: check if hidden layer is non zero
    int size = hidden_layer_shape[i];
    int previous_size = (i==0 ? input_size : hidden_layer_shape[i-1]);
    biases.push_back(random_vector(size));
    weights.push_back(random_matrix(size, previous_size));
  }
  // Add biases/weights for output layer
  int last_hidden_size = hidden_layer_shape[hidden_layer_shape.size()-1];
  biases.push_back(random_vector(output_size));
  weights.push_back(random_matrix(output_size, last_hidden_size));
}

vector<vector<float>> NeuralNet::random_matrix(int x, int y){
  vector<vector<float>> rand_2d_vect;
  for(int i = 0; i < y; i++){
    rand_2d_vect.push_back(random_vector(x));
  }
  return rand_2d_vect;
}

vector<float> NeuralNet::random_vector(int size){
  random_device rd{};
  mt19937 gen{rd()};
  normal_distribution<> dist{0,1};
  float init_const = sqrt(2.0/size);
  vector<float> rand_vect;
  for(int i = 0; i < size; i++){
    rand_vect.push_back(dist(gen)*init_const);
  }
  return rand_vect;
}

string NeuralNet::to_string(){
  stringstream s;
  s << "Inputs:\n";
  for(unsigned int input = 0; input < input_size; input++){
    s << "in" << input << " \t";
  }
  s << "\n";
  for(unsigned int l = 0; l < biases.size(); l++){
    s << "\nWeights:\n";
    for(unsigned int j = 0; j < weights[l].size(); j++){
      for(unsigned int k = 0; k < weights[l][j].size(); k++){
        s << weights[l][j][k] << "  \t";
      }
      s << "\n";
    }
    s << "\nBiases: \n";
    for(unsigned int b = 0; b < (biases[l]).size(); b++){
      s << biases[l][b] << "\t";
    }
    s << "\n";
  }
  return s.str();
}
