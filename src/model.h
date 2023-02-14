/**
 * @file model.h
 * @author Iago Andrade (iago.andrade@aluno.ufop.edu.br)
 * @brief Contains the public methods of the model (simulation) class
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef MODEL_H
#define MODEL_H
#include <cstring>
#include <ostream>
#include <vector>
#include "flow.h"

using namespace std;

/**
 * @brief This class represents the general simulation model, with all of its flows and systems
 * 
 */
class Model {
    public:
        /**
         * @brief A virtual destructor of the class
         * 
         */
        virtual ~Model() {};
        /**
         * @brief Set the type for the vector of flows
         * 
         */
        typedef typename vector<Flow*>::iterator itFlow;
        /**
         * @brief Set the type for the vector of systems
         * 
         */
        typedef typename vector<System*>::iterator itSystem;
        /**
         * @brief Get the name of a model
         * 
         * @return string containing the name of the model
         */
        virtual string getName() const = 0;
        /**
         * @brief Set the name of a model
         * 
         * @param name being the string that names a model
         */
        virtual void setName(const string name) = 0;
        /**
         * @brief Get the first flow of a vector
         * 
         * @return itFlow type
         */
        virtual itFlow getFlowBegin() = 0;
        /**
         * @brief Get the last flow of a vector
         * 
         * @return itFlow type
         */
        virtual itFlow getFlowEnd() = 0;
        /**
         * @brief Get the size of the flow vector
         * 
         * @return int Integer that represents its size
         */
        virtual int getFlowSize() = 0;
        /**
         * @brief Get the first system of a vector
         * 
         * @return itSystem type
         */
        virtual itSystem getSystemBegin() = 0;
        /**
         * @brief Get the last system of a vector
         * 
         * @return itSystem type
         */
        virtual itSystem getSystemEnd() = 0;
        /**
         * @brief Get the size of the system vector
         * 
         * @return int Integer that represents its size
         */
        virtual int getSystemSize() = 0;
        /**
         * @brief Add a system to the model
         * 
         * @param System* being a pointer to the system to be added
         */
        virtual void add(System*) = 0;
        /**
         * @brief Add a flow to the model
         * 
         * @param Flow* being a pointer to the flow to be added
         */
        virtual void add(Flow*) = 0;
        /**
         * @brief Remove a system from the model
         * 
         * @return true if the object and item share the same memory address
         * @return false if they do not
         */
        virtual bool remove(System*) = 0;
        /**
         * @brief Remove a flow from the model
         * 
         * @return true if the object and item share the same memory address
         * @return false if they do not
         */
        virtual bool remove(Flow*) = 0;
        /**
         * @brief Clear the model, removing all of its systems and flows
         * 
         */
        virtual void clear() = 0;
        /**
         * @brief Show the names and values contained in the model
         * 
         */
        virtual void show() = 0;
        /**
         * @brief Run the model with a start time, an end time and a set time interval between each execution
         * 
         * @param int start time
         * @param int end time
         * @param int how many units of time shall pass between one execution and the next
         * 
         */
        virtual void run(int, int, int) = 0;    

};

#endif