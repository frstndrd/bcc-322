/**
 * @file model.h
 * @author Iago Andrade (iago.andrade@aluno.ufop.edu.br)
 * @brief Represents the simulation model
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
#include "system.h"
#include "model.h"

/**
 * @brief Store vectors containing the name of the model and flows and systems related to it
 * 
 */
class Model {
    protected:
        /**
         * @brief Name of the model
         * 
         */
        string name;
        /**
         * @brief Store an array of pointer-to-flow variables
         * 
         */
        vector<Flow*> flows;
        /**
         * @brief Store an array of pointer-to-system variables
         * 
         */
        vector<System*> systems;
        
    private:
        /**
         * @brief Copy a Model object
         * 
         * @param obj model to be copied
         */
        Model(Model& obj);
        /**
         * @brief Overload the '=' operator, cloning from one to the other
         * 
         * @param obj model to be cloned
         * @return Model& A clone of the model
         */
        Model& operator= (const Model& obj);

    public:
        /**
         * @brief Empty constructor of the class
         * 
         */
        Model();
        /**
         * @brief Construct a new Model object
         * 
         * @param name of the model
         */
        Model(const string name);
        /**
         * @brief Construct a new Model object
         * 
         * @param name of the model
         * @param flows array of pointer-to-flow variables
         * @param systems array of pointer-to-system variables
         */
        Model(const string name, vector<Flow*> &flows, vector<System*> &systems);
        /**
         * @brief Destroy the Model object
         * 
         */
        virtual ~Model();

        /**
         * @brief Set the flow vector type
         * 
         */
        typedef typename vector<Flow*> :: iterator itFlow;
        /**
         * @brief Set the system vector type
         * 
         */
        typedef typename vector<System*> :: iterator itSystem;
        
        /**
         * @brief Get the Name object
         * 
         * @return string The name of a model
         */
        string getName() const;
        /**
         * @brief Set the Name object
         * 
         * @param name the model
         */
        void setName(const string name);

        /**
         * @brief Get the flow from the beginning of the vector
         * 
         * @return itFlow The flow from the beginning
         */
        itFlow getFlowBegin();
        /**
         * @brief Get the flow from the end of the vector
         * 
         * @return itFlow The flow from the end
         */
        itFlow getFlowEnd();
        /**
         * @brief Get the size of the flow vector
         * 
         * @return int The size of the flow vector
         */
        int getFlowSize();

        /**
         * @brief Get the system from the beginning of the vector
         * 
         * @return itSystem The system from the beginning
         */
        itSystem getSystemBegin();
        /**
         * @brief Get the system from the end of the vector
         * 
         * @return itSystem The system from the end
         */
        itSystem getSystemEnd();
        /**
         * @brief Get the size of the system vector
         * 
         * @return int The size of the system vector
         */
        int getSystemSize();
        
        /**
         * @brief Add a system to the model
         * @param pointer to a system
         * 
         */
        void add(System*);
        /**
         * @brief Add a flow to the model
         * @param pointer to a flow
         * 
         */
        void add(Flow*);
        /**
         * @brief Remove a system from the model
         * 
         * @return true If the object and item have the same memory address
         * @return false If the object and item have different memory addresses 
         */
        bool remove(System*);
        /**
         * @brief Remove a flow from the model
         * 
         * @return true If the object and item have the same memory address
         * @return false If the object and item have different memory addresses
         */
        bool remove(Flow*);
        /**
         * @brief Clean the model
         * 
         */
        void clear();
        /**
         * @brief Display the model
         * 
         */
        void show();
        /**
         * @brief Execute the model based on initial time, end time and time intervals
         * @param int start time
         * @param int end time
         * @param int how many units of time shall pass between one execution and the next
         * 
         */
        void run(int, int, int);    
};

#endif