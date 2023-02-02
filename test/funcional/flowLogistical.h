#ifndef FLOWLOGISTICAL_H  
#define FLOWLOGISTIC_H

#include "../../src/flow.h"

class FlowLogistical : public Flow {
public:    
    FlowLogistical();
    FlowLogistical(Flow &obj);
    FlowLogistical(const string name, System *source, System *target);
    virtual ~FlowLogistical();

    virtual float execute();
};

#endif