#pragma once
#include <vector>
#include <observer.h>

class Subject {
private:
    std::vector<Observer*> observers;
public:
    void registerObserver(Observer* obs) 
    {
        observers.push_back(obs);
    }
    void unregisterObserver(Observer* obs)
    {
        observers.erase(std::remove(observers.begin(), observers.end(), obs), observers.end());
    }
    void notify()
    {
        for (auto obs : observers) {
            obs->update();
        }
    }
};