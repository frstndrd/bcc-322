#ifndef FLOW_H
#define FLOW_H

#include <iostream>
#include <string>
#include "system.h"

class Flow {
    protected:
        string name;
        System *source;
        System *target;
    public:
        Flow();
        Flow(Flow &obj);
        Flow(const string name, System *source, System *target);
        virtual ~Flow();

        string getName() const;
        void setName(const string name);
        System *getSource() const;
        void setSource(System *source);
        System *getTarget() const;
        void setTarget(System *target);

        bool operator==(const Flow &obj) const;
        bool operator!=(const Flow &obj) const;
        Flow &operator= (const Flow &obj);

        virtual float execute() = 0;
};

#endif