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

/**
 * @brief The Flow Interface is the interface that defines the methods to be implemented
 * 
 */
class Flow {
    public:
        /**
         * @brief A virtual destructor of the class
         * 
         */
        virtual ~Flow() {};
        /**
         * @brief Get the name of a flow
         * 
         * @return string containing the name of the flow
         */
        virtual string getName() const = 0;
        /**
         * @brief Set the name of a flow
         * 
         * @param name being the string that names a flow
         */
        virtual void setName(const string name) = 0;
        /**
         * @brief Get the source system for a flow
         * 
         * @return System* Which contents shall be moved to another system by a flow
         */
        virtual System *getSource() const = 0;
        /**
         * @brief Set the source system for a flow
         * 
         * @param source system which will act as a source for the operations of the flow
         */
        virtual void setSource(System *source) = 0;
        /**
         * @brief Get the target system for a flow
         * 
         * @return System* Points to the system that will act as a recipient for the flow
         */
        virtual System *getTarget() const = 0;
        /**
         * @brief Set the target object
         * 
         * @param target system that will be the recipient for the operations of the flow
         */
        virtual void setTarget(System *target) = 0;
        /**
         * @brief Overload the '=' operator in order to "clone" a flow
         * 
         * @param obj being the flow that's gonna be cloned
         * @return Flow& A flow object is returned identical to the one that was cloned
         */
        virtual Flow &operator= (const Flow &obj) = 0;
        /**
         * @brief Purely virtual method that contains the equation that defines a flow
         * 
         * @return float 
         */
        virtual float execute() = 0;
};

#endif