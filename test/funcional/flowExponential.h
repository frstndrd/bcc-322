#ifndef FLOWEXPONENTIAL_H
#define FLOWEXPONENTIAL_H

#include "../../src/flow.h"

class FlowExponential : public Flow {
    public:    
        FlowExponential();
        FlowExponential(Flow &obj);
        FlowExponential(const string name, System *source, System *target);
        virtual ~FlowExponential();

        virtual float execute();  
};

#endif