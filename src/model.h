#ifndef MODEL_H
#define MODEL_H
#include <cstring>
#include <ostream>
#include <vector>
#include "flow.h"
//#include "flowExponential.h"
//#include "flowLogistic.h"
#include "system.h"
#include "model.h"

class Model {
    protected:
        string name;
        vector<Flow*> flows;
        vector<System*> systems;
        
    private:
        Model(Model& obj);
        Model& operator= (const Model& obj);

    public:
        Model();
        Model(const string name);
        Model(const string name, vector<Flow*> &flows, vector<System*> &systems);
        virtual ~Model();

        typedef typename vector<Flow*> :: iterator itFlow;
        typedef typename vector<System*> :: iterator itSystem;
        
        string getName() const;
        void setName(const string name);

        itFlow getFlowBegin();
        itFlow getFlowEnd();
        int getFlowSize();

        itSystem getSystemBegin();
        itSystem getSystemEnd();
        int getSystemSize();
            
        void add(System*);
        void add(Flow*);
        bool remove(System*);
        bool remove(Flow*);
        void clear();
        void show();
        void run(int, int, int);    
};

#endif