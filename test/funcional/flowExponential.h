/**
 * @file flowExponential.h
 * @author Iago Andrade (iago.andrade@aluno.ufop.edu.br)
 * @brief Contains the code used to run the functional exponential tests
 * 
 * @copyright Copyright (c) 2023
 * 
*/

#ifndef FLOWEXPONENTIAL_H
#define FLOWEXPONENTIAL_H

#include "../../src/flow.h"

/**
 * @brief This flow class connects two systems to evaluate their final values
 * after running an equation for a given time
 * 
 */
class FlowExponential : public Flow {
    public:    
        /**
         * @brief Construct a new Flow Exponential object
         * 
         */
        FlowExponential();
        /** 
         * @brief Copy a Flow Exponential object
         * @param obj flow to be copied
        */
        FlowExponential(Flow &obj);
        /**
         * @brief Construct a new Flow Exponential object
         * 
         * @param name of the flow
         * @param source system
         * @param target system
         */
        FlowExponential(const string name, System *source, System *target);
        /**
         * @brief Destroy the Flow Exponential object
         * 
         */
        virtual ~FlowExponential();
        /**
         * @brief Run the flow's equation
         * 
         * @return float The result of the calculations
         */
        virtual float execute();  
};

#endif