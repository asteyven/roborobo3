#if defined PRJ_TESTOBJECTGROUPS || !defined MODULAR

#include "Config/TestObjectGroupsConfigurationLoader.h"
#include "TestObjectGroups/include/TestObjectGroupsWorldObserver.h"
#include "TestObjectGroups/include/TestObjectGroupsAgentObserver.h"
#include "TestObjectGroups/include/TestObjectGroupsController.h"
#include "WorldModels/RobotWorldModel.h"

TestObjectGroupsConfigurationLoader::TestObjectGroupsConfigurationLoader()
{
}

TestObjectGroupsConfigurationLoader::~TestObjectGroupsConfigurationLoader()
{
	//nothing to do
}

WorldObserver* TestObjectGroupsConfigurationLoader::make_WorldObserver(World* wm)
{
	return new TestObjectGroupsWorldObserver(wm);
}

RobotWorldModel* TestObjectGroupsConfigurationLoader::make_RobotWorldModel()
{
	return new RobotWorldModel();
}

AgentObserver* TestObjectGroupsConfigurationLoader::make_AgentObserver(RobotWorldModel* wm)
{
	return new TestObjectGroupsAgentObserver(wm);
}

Controller* TestObjectGroupsConfigurationLoader::make_Controller(RobotWorldModel* wm)
{
    return new TestObjectGroupsController(wm);
}

#endif
