#ifndef WEAPON_H
#define WEAPON_H

#include <string>

using namespace std;

class Weapon
{
    public:
        Weapon();
        virtual ~Weapon();
    protected:
    private:

    public:
        virtual string model();
        virtual int countAmmunition();
        virtual void fire();
};

#endif // WEAPON_H
