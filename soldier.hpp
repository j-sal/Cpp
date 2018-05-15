#ifndef SOLDIER_H
#define SOLDIER_H
#include <iostream>
#include <string>
#include <vector>
#include "weapon.hpp"

using namespace std;

class Soldier
{
    public:
        Soldier();
        Soldier(string name, string rank);
        virtual ~Soldier();
        void scream();
        virtual void identification();
        virtual void setLeft(Weapon *);
        virtual void fireLeft();
        virtual void setRight(Weapon *);
        virtual void fireRight();
    protected:
    private:
        string name;
        string rank;
        Weapon* left;
        Weapon* right;
};

#endif // SOLDIER_H
