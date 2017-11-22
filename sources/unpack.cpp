#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Email {
  string nickname;
  string server;
};

struct Person {
  string  first_name;
  string  last_name;
  Email        email;
  size_t       age;
  string  phone;
};

int main(int argc, char* argv[])
{
   try {
      string Path = argv[1];
      Person file;
      YAML::Node node = YAML::LoadFile("config.yaml");
      if (node["person"]) {
         cout << node["person"].as<string>() << "\n";
      }
      if (node["First name"]) {
         cout << node["First name"].as<string>() << "\n";
      }
      if (node["Last name"]) {
         cout << node["Last name"].as<string>() << "\n";
      }
      if (node["Email"]) {
         cout << node["Email"].as<string>() << "\n";
      }
      if (node["Age"]) {
         cout << node["Age"].as<size_t>() << "\n";
      }
      if (node["Phone"]) {
         cout << node["Phone"].as<string>() << "\n";
      }
      
  }
  catch(const exception& e) {
    cout << e.what() << endl;
  }
}
