/*
 * TestObjectGroupsConfigurationLoader.h
 */

#ifndef TESTOBJECTGROUPSCONFIGURATIONLOADER_H
#define TESTOBJECTGROUPSCONFIGURATIONLOADER_H

#include "Config/ConfigurationLoader.h"

class TestObjectGroupsConfigurationLoader : public ConfigurationLoader
{
	private:

	public:
		TestObjectGroupsConfigurationLoader();
		~TestObjectGroupsConfigurationLoader();

		WorldObserver *make_WorldObserver(World* wm) ;
		RobotWorldModel *make_RobotWorldModel();
		AgentObserver *make_AgentObserver(RobotWorldModel* wm) ;
		Controller *make_Controller(RobotWorldModel* wm) ;
};



#endif
