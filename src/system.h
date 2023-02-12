/**
 * @file system.h
 * @author Iago Andrade (iago.andrade@aluno.ufop.edu.br)
 * @brief Contains the public methods of the system class
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <ostream>

using namespace std;

class System {
    public:
        virtual ~System() {};
        virtual string getName() const = 0;
        virtual void setName(const string name) = 0;
        virtual float getValue() const = 0;
        virtual void setValue(float value) = 0;
        virtual System& operator= (const System& obj) = 0;

};

#endif