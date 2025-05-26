#pragma once
#include "userMessage.h"
#include <vector>
#include <subject.h>

class ChatSession : public Subject {
private:
    std::vector<UserMessage> sessions;
public:
    void addMessage(User* user, Message* msg) 
    {
        sessions.emplace_back(msg, user);
        notify(); 
    }
    std::vector<UserMessage> getAll() { return sessions; };
};