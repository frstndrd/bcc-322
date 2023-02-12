/**
 * @file flow.h
 * @author Iago Andrade (iago.andrade@aluno.ufop.edu.br)
 * @brief Contains the public methods of the flow class
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef FLOW_H
#define FLOW_H
#include <iostream>
#include <string>
#include "system.h"

using namespace std;

class Flow {
    public:
        virtual ~Flow() {};
        virtual string getName() const = 0;
        virtual void setName(const string name) = 0;
        virtual System *getSource() const = 0;
        virtual void setSource(System *source) = 0;
        virtual System *getTarget() const = 0;
        virtual void setTarget(System *target) = 0;
        virtual Flow &operator= (const Flow &obj) = 0;
        virtual float execute() = 0;
};

#endif