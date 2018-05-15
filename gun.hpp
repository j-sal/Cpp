#ifndef GUN_HPP
#define GUN_HPP
#include <iostream>
#include <string>
#include <vector>
#include <Weapon.hpp>

using namespace std;

class Gun : public Weapon
{
    public:
        Gun(string name, int ammo);
        virtual ~Gun();
    protected:
        string name;
        int ammo;
    private:
};

#endif // GUN_HPP
