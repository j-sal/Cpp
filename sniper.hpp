#ifndef SNIPER_H
#define SNIPER_H

#include <Soldier.hpp>
#include <string>
#include <vector>

using namespace std;


class Sniper : public Soldier
{
    public:
        Sniper(string name);
        virtual ~Sniper();
    protected:
    private:
};

#endif // SNIPER_H
