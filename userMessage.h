#pragma once
#include <message.h>
#include <user.h>

class UserMessage {
private:
	Message* msg;
	User* user;
public:
	UserMessage(Message* msg, User* user) : msg(msg), user(user) {};
	UserMessage() : msg(nullptr), user(nullptr) {};
	const Message& getMessage() const { return *msg; };
	const User& getUser() const { return *user; };

};
