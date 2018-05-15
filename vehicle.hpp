#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <string>
#include <vector>
#include "soldier.hpp"

using namespace std;

class Vehicle
{
    public:
        Vehicle();
        virtual ~Vehicle();
        int countSoldier();
        virtual void action();
        void addSoldier(Soldier *);
        std::vector<Soldier*> unload();
    protected:
    private:
        vector<Soldier*> s;
};

#endif // VEHICLE_H
