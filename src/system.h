#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <ostream>

using namespace std;

class System {
    protected:
        string name;
        float value;

    public:
        System();
        System(const string name);
        System(float value);
        System(System& obj);
        System(const string name, float value);
        virtual ~System();

        string getName() const;
        void setName(const string name);
        float getValue() const;
        void setValue(float value);

        System& operator= (const System& obj);
};

#endif