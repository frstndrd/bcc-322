/**
 * @file flowExponential.h
 * @author Iago Andrade (iago.andrade@aluno.ufop.edu.br)
 * @brief Contains the code necessary to run the functional exponential tests
 * 
 * @copyright Copyright (c) 2023
 * 
*/

#ifndef FLOWEXPONENTIAL_H
#define FLOWEXPONENTIAL_H

#include "../../src/flowConcrete.h"

/**
 * @brief This flow class connects two systems to evaluate their final values
 * after running an equation for a given time
 * 
 */
class FlowExponential:public FlowConcrete {
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
         * @param source system, with contents to be moved from
         * @param target system, where the aforementioned content will be moved to
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
         * @return float The result of the calculations described by the flow
         */
        virtual float execute();  
};

#endif