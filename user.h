#pragma once
#include <string>

class User {
private:
	std::string name;
	int id;

public:
	User(int id, std::string name) : id(id), name(name) {};
	User() : id(-1), name("") {};
	const std::string getName() const { return name; };
	const int getId() const { return id; };

};
