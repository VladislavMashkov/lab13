#include "yaml-cpp/yaml.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
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

Person getInfo() {
	struct Person file;
	/*cout << "Enter data to fields of the Person structure." << endl;
	cout << "First name:" << endl;
	cin >> file.first_name;
	cout << "Last name:" << endl;
	cin >> file.last_name;
	cout << "Email:" << endl;
	cin >> file.email.nickname;
	cout << "Age(optional):" << endl;
	cin >> file.age;
	cout << "Phone(optional):" << endl;
	cin >> file.phone;*/
	file.first_name = "Ivan";
	file.last_name = "Sidorov";
	file.email.nickname = "Ivan_Sidorov@cont.ru";
	file.age = 19;
	file.phone = "8(495)555-55-55";
	return file;
}


int main(int argc, char* argv[]) {
  try {
  	string Path = argv[1];
    Person file = getInfo();
    /*YAML::Node node;
    node ["person"] = file.email.server;
    node["First name"] = file.first_name;
   	node["Last name"] = file.last_name;
   	node["Email"] = file.email.nickname;
   	node["Age"] = file.age;
   	node["Phone"] = file.phone;
	ofstream fout(Path);
    fout << node;*/
   YAML::Emitter out;
   out << YAML::BeginMap;
	out << YAML::Key << "person";
	out << YAML::BeginMap;
	out << YAML::Key << "First name";
	out << YAML::Value << file.first_name;
   	out << YAML::Key << "Last name";
	out << YAML::Value << file.last_name;
	out << YAML::Key << "Email";
	out << YAML::Value << file.email.nickname;
	out << YAML::Key << "Age";
	out << YAML::Value << file.age;
	out << YAML::Key << "Phone";
	out << YAML::Value << file.phone;
	out << YAML::EndMap;
	out << YAML::EndMap;

   ofstream fout(Path);
   fout << out.c_str() << endl; 
   return 0;


  }
  catch(const exception& e) {
    cout << e.what() << endl;
  }
}