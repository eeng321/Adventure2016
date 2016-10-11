//
// Created by william on 27/09/16.
//

#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>



int main(int argc, char** argv) {
   // std::ifstream fin("/home/william/cmpt373/adventure2016/src/yaml-parser/smurf.yaml");
   // std::cout << fin.rdbuf();
    YAML::Node node = YAML::LoadFile("\/home/william/cmpt373/adventure2016/src/yaml-parser/smurf.yaml");


    return 0;
}
