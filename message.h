#pragma once
#include <string>

class Message {
private:
	std::string time;
	std::string message;
public:
	Message(std::string time, std::string message) : time(time), message(message) {};
	Message() : time(""), message("") {};
	const std::string getTime() const { return time; };
	const std::string getMessage() const { return message; };
};
