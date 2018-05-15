#ifndef INFANTRY_H
#define INFANTRY_H

#include <Soldier.hpp>
#include <string>
#include <vector>

using namespace std;


class Infantry : public Soldier
{
    public:
        Infantry(string name);
        virtual ~Infantry();
    protected:
    private:
};

#endif // INFANTRY_H
