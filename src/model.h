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
#include "flowConcrete.h"
#include "system.h"
#include "systemConcrete.h"

using namespace std;

class Model {
    private:

    public:
        virtual ~Model() {};
        typedef typename vector<Flow*>::iterator itFlow;
        typedef typename vector<System*>::iterator itSystem;
        virtual string getName() const = 0;
        virtual void setName(const string name) = 0;
        virtual itFlow getFlowBegin() = 0;
        virtual itFlow getFlowEnd() = 0;
        virtual int getFlowSize() = 0;
        virtual itSystem getSystemBegin() = 0;
        virtual itSystem getSystemEnd() = 0;
        virtual int getSystemSize() = 0;    
        virtual void add(System*) = 0;
        virtual void add(Flow*) = 0;
        virtual bool remove(System*) = 0;
        virtual bool remove(Flow*) = 0;
        virtual void clear() = 0;
        virtual void show() = 0;
        virtual void run(int, int, int) = 0;    

};

#endif