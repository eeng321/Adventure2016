
#include "parser.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace parser;

int main(){
    std::string test = "test";
    std::string test2 = "test2";

    YAML::Node nodeTest = parser::serializeLogin(test, test2);
    cout << "test: " << nodeTest["USERNAME"] << endl;


    string test3;
    string test4;

    parser::deserializeLogin(test3, test4, nodeTest);

    cout << "Test 3 and 4: " << test3 << " " << test4 << endl;
    return 0;
}


YAML::Node parser::serializeLogin(const std::string username, const std::string password){

    YAML::Node node;
    node["USERNAME"] = username;
    node["PASSWORD"] = password;
    return node;
}

void parser::deserializeLogin(std::string &username, std::string &password, const YAML::Node node){
    
    username = node["USERNAME"].as<string>();
    password = node["PASSWORD"].as<string>();
}


