#ifndef JEEP_H
#define JEEP_H

#include <Vehicle.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Jeep : public Vehicle
{
    public:
        Jeep();
        virtual ~Jeep();
        void action();
    protected:
    private:
};

#endif // JEEP_H
