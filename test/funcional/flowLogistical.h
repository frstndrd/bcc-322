/**
 * @file flowExponential.h
 * @author Iago Andrade (iago.andrade@aluno.ufop.edu.br)
 * @brief Contains the code necessary to run the functional logistical tests
 * 
 * @copyright Copyright (c) 2023
 * 
*/

#ifndef FLOWLOGISTICAL_H  
#define FLOWLOGISTICAL_H

#include "../../src/flowConcrete.h"

/**
 * @brief This flow class connects two systems to evaluate their final value
 * after running an equation for a given time
 * 
 */
class FlowLogistical:public FlowConcrete{
public:
    /**
     * @brief Construct a new Flow Logistical object
     * 
     */
    FlowLogistical();
    /**
     * @brief Construct a new Flow Logistical object
     * 
     * @param obj flow to be copied
     */
    FlowLogistical(Flow &obj);
    /**
     * @brief Construct a new Flow Logistical object
     * 
     * @param name of the flow
     * @param source system with content to be moved by the flow
     * @param target system to receive the content moved by the flow
     */
    FlowLogistical(const string name, System *source, System *target);
    /**
     * @brief Destroy the Flow Logistical object
     * 
     */
    virtual ~FlowLogistical();
    /**
     * @brief Run the flow's equation
     * 
     * @return float The result of the calculations described by the flow
     */
    virtual float execute();
};

#endif