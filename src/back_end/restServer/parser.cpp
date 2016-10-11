
#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>

using namespace std;
int main(int argc, char** argv) {


    // std::ifstream fin("/home/william/cmpt373/adventure2016/src/yaml-parser/smurf.yaml");
    // std::cout << fin.rdbuf();
    YAML::Node node = YAML::LoadFile("/home/william/cmpt373/adventure2016/src/back_end/lib/yaml-parser/smurf.yaml");
    std::cout << "test\n";
//    YAML::Node roomNode = node["ROOMS"];//desc, doors(), extended_descriptions, id, name
//
//    for(auto i : roomNode){
//    	std::cout << i["id"] << "\n";
//    }
    return 0;
}
