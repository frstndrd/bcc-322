/**
 * @file flow.h
 * @author Iago Andrade (iago.andrade@aluno.ufop.edu.br)
 * @brief Contains the specifications of the flow class
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef FLOW_H
#define FLOW_H

#include <iostream>
#include <string>
#include "system.h"

/**
 * @brief Define the interface with the methods to be implemented
 * 
 */
class Flow {
    protected:
        /**
         * @brief Name the flow
         * 
         */
        string name;
        /**
         * @brief Assign the flow's source
         * 
         */
        System *source;
        /**
         * @brief Assign the flow's target
         * 
         */
        System *target;
    public:
        /**
         * @brief Construct a new Flow object
         * 
         */
        Flow();
        /**
         * @brief Copy a Flow object
         * 
         * @param obj flow to be copied
         */
        Flow(Flow &obj);
        /**
         * @brief Construct a new Flow object
         * 
         * @param name of the flow
         * @param source system
         * @param target system
         */
        Flow(const string name, System *source, System *target);
        /**
         * @brief Destroy the Flow object
         * 
         */
        virtual ~Flow();

        /**
         * @brief Get the Name object
         * 
         * @return string The name of a flow
         */
        string getName() const;
        /**
         * @brief Set the Name object
         * 
         * @param name the flow
         */
        void setName(const string name);
        /**
         * @brief Get the Source object
         * 
         * @return System* The system that acts as a source for the flow
         */
        System *getSource() const;
        /**
         * @brief Set the Source object
         * 
         * @param source system
         */
        void setSource(System *source);
        /**
         * @brief Get the Target object
         * 
         * @return System* The system that acts as a target for the flow
         */
        System *getTarget() const;
        /**
         * @brief Set the Target object
         * 
         * @param target system
         */
        void setTarget(System *target);

        bool operator==(const Flow &obj) const;
        bool operator!=(const Flow &obj) const;
        /**
         * @brief Overload the '=' operator, cloning from one to the other
         * 
         * @param obj flow to be cloned
         * @return Flow& A clone of the flow
         */
        Flow &operator= (const Flow &obj);
        /**
         * @brief Purely virtual method to be inherited by subclasses created by the user.
         * 
         * @return float 
         */
        virtual float execute() = 0;
};

#endif