#ifndef CAPTAINAMERICA_H
#define CAPTAINAMERICA_H

#include <Soldier.hpp>
#include <string>
#include <vector>

using namespace std;


class CaptainAmerica : public Soldier
{
    public:
        CaptainAmerica();
        virtual ~CaptainAmerica();
        void identification();
        void setRight(Weapon *);
        void setLeft(Weapon *);
        void fireLeft();
        void fireRight();
    protected:
    private:
};

#endif // CAPTAINAMERICA_H
