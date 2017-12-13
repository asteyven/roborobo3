/**
 * @author Nicolas Bredeche <nicolas.bredeche@upmc.fr>
 *
 */

#include "TestObjectGroups/include/TestObjectGroupsWorldObserver.h"
#include "TestObjectGroups/include/TestObjectGroupsController.h"
#include "TestObjectGroups/include/TestObjectGroupsSharedData.h"
#include "RoboroboMain/roborobo.h"
#include "WorldModels/RobotWorldModel.h"
#include "World/World.h"
#include "Utilities/Misc.h"
#include "World/PhysicalObject.h"
#include "World/PhysicalObjectGroup.h"


TestObjectGroupsWorldObserver::TestObjectGroupsWorldObserver( World* world ) : TemplateEEWorldObserver( world )
{
    // superclass constructor called before

	// ==== loading project-specific properties
	gProperties.checkAndGetPropertyValue("gPhysicalObjectRepositioning",&TestObjectGroupsSharedData::gPhysicalObjectRepositioning,false);
	gProperties.checkAndGetPropertyValue("gPhysicalObjectRepositionStartTime",&TestObjectGroupsSharedData::gPhysicalObjectRepositionStartTime,false);
	gProperties.checkAndGetPropertyValue("gPhysicalObjectRepositionInterval",&TestObjectGroupsSharedData::gPhysicalObjectRepositionInterval,false);

	std::cout << "[INFO] gPhysicalObjectRepositioning: " << TestObjectGroupsSharedData::gPhysicalObjectRepositioning << std::endl;
	std::cout << "[INFO] gPhysicalObjectRepositionStartTime: " << TestObjectGroupsSharedData::gPhysicalObjectRepositionStartTime << std::endl;
	std::cout << "[INFO] gPhysicalObjectRepositionInterval: " << TestObjectGroupsSharedData::gPhysicalObjectRepositionInterval << std::endl;
}

TestObjectGroupsWorldObserver::~TestObjectGroupsWorldObserver()
{
    // superclass destructor called before
}

void TestObjectGroupsWorldObserver::initPre()
{
    // nothing to do.
}

void TestObjectGroupsWorldObserver::initPost()
{
    // nothing to do.
}

void TestObjectGroupsWorldObserver::stepPre()
{
    TemplateEEWorldObserver::stepPre();
}

void TestObjectGroupsWorldObserver::stepPost()
{
    TemplateEEWorldObserver::stepPost();
}

void TestObjectGroupsWorldObserver::updateEnvironment()
{
    // moving PhysicalObjectGroups
    if ( TestObjectGroupsSharedData::gPhysicalObjectRepositioning
    		&& gWorld->getIterations() > TestObjectGroupsSharedData::gPhysicalObjectRepositionStartTime
    		&& gWorld->getIterations() % TestObjectGroupsSharedData::gPhysicalObjectRepositionInterval == 0 )
    {
        for ( int i = 0 ; i != gNbOfPhysicalObjectGroups ; i++ )
        {
            PhysicalObjectGroup *g = gPhysicalObjectGroups[i];
            double angle = M_PI/6;
			int xOrigin = (int) gAreaWidth/2,
				yOrigin = (int) gAreaHeight/2,
				x = g->getInitAreaX(),
				y = g->getInitAreaY();

			/* https://stackoverflow.com/a/32161713 */
            int _x, _y;
            _x = ((x - xOrigin) * cos(angle)) - ((y - yOrigin) * sin(angle)) + xOrigin;
            _y = ((x - xOrigin) * sin(angle)) + ((y - yOrigin) * cos(angle)) + yOrigin;



            g->setInitAreaX(_x);
            g->setInitAreaY(_y);

            if ( gVerbose )
            	std::cout << "[ INFO: new position for group " << g->getId() << " is ( " << _x << ", " << _y << ") ]" << std::endl;
        }

//        for ( int i = 0 ; i != gNbOfPhysicalObjectGroups ; i++ )
        for (std::vector<PhysicalObjectGroup*>::iterator itG = gPhysicalObjectGroups.begin(); itG < gPhysicalObjectGroups.end() ; itG++ )
		{
//        	PhysicalObjectGroup *g = gPhysicalObjectGroups[i];
//        	std::vector<PhysicalObject*> _g= g->getGroupObjects();
        	std::vector<PhysicalObject*> _g= (*itG)->getGroupObjects();
        	for ( std::vector<PhysicalObject*>::iterator itO = _g.begin(); itO < _g.end() ; itO++  )
//            for ( std::vector<PhysicalObject*>::iterator itO = (*itG)->getGroupObjects().begin(); itO < (*itG)->getGroupObjects().end() ; itO++  )
            {

            	(*itO)->relocateObject();
            }
		}
    }
}

void TestObjectGroupsWorldObserver::monitorPopulation( bool localVerbose )
{
    TemplateEEWorldObserver::monitorPopulation(localVerbose);
}
