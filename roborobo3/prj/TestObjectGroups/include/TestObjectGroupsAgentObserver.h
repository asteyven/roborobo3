/**
 * @author Nicolas Bredeche <nicolas.bredeche@upmc.fr>
 *
 */


#ifndef TESTOBJECTGROUPSAGENTOBSERVER_H
#define TESTOBJECTGROUPSAGENTOBSERVER_H

#include "TemplateEE/include/TemplateEEAgentObserver.h"

class RobotWorldModel;

class TestObjectGroupsAgentObserver : public TemplateEEAgentObserver
{
	public:
        TestObjectGroupsAgentObserver( RobotWorldModel *wm );
		~TestObjectGroupsAgentObserver();

        virtual void step();
};

#endif

