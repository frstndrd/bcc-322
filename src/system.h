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

/**
 * @brief The System Interface is the interface that defines the methods to be implemented
 * 
 */
class System {
    public:
        /**
         * @brief A virtual destructor of the class
         * 
         */
        virtual ~System() {};
        /**
         * @brief Get the name of a system
         * 
         * @return string containing the name of the system
         */
        virtual string getName() const = 0;
        /**
         * @brief Set the name of a system
         * 
         * @param name being the string that names a system
         */
        virtual void setName(const string name) = 0;
        /**
         * @brief Get the value contained in a system
         * 
         * @return float Measures the amount contained in that system
         */
        virtual float getValue() const = 0;
        /**
         * @brief Set the value contained in a system
         * 
         * @param value defines the content of a system
         */
        virtual void setValue(float value) = 0;
        /**
         * @brief Overload the '=' operador in order to "clone" a system
         * 
         * @param obj being the system that's gonna be cloned
         * @return System& A system object is returned identical to the one that was passed as a parameter
         */
        virtual System& operator= (const System& obj) = 0;
};

#endif