#ifndef BLACKBIRD_H
#define BLACKBIRD_H

#include <Vehicle.hpp>
#include <string>
#include <vector>

using namespace std;


class BlackBird : public Vehicle
{
    public:
        BlackBird();
        virtual ~BlackBird();
        void action();
    protected:
    private:
};

#endif // BLACKBIRD_H
