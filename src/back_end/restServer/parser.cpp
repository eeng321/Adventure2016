
#include "../lib/yaml-parser/include/yaml-cpp/yaml.h"

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    // std::ifstream fin("/home/william/cmpt373/adventure2016/src/yaml-parser/smurf.yaml");
    // std::cout << fin.rdbuf();

    YAML::Node node = YAML::LoadFile();
    std::cout << "test\n";
    YAML::Node roomNode = node["ROOMS"];//desc, doors(), extended_descriptions, id, name

    return 0;
}

