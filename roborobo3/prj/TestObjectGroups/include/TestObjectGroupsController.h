/**
 * @author Nicolas Bredeche <nicolas.bredeche@upmc.fr>
 *
 */



#ifndef TESTOBJECTGROUPSCONTROLLER_H
#define TESTOBJECTGROUPSCONTROLLER_H

#include "TemplateEE/include/TemplateEEController.h"

using namespace Neural;

class RobotWorldModel;

class TestObjectGroupsController : public TemplateEEController
{
    public:
    
        TestObjectGroupsController(RobotWorldModel *wm);
        ~TestObjectGroupsController();
    
        double getFitness();

    protected:
    
        void initController();
        void stepController();
    
        void performSelection();
        void performVariation();
    
        void broadcastGenome();
    
        void resetFitness();
        void updateFitness();

        void logCurrentState();
};


#endif

