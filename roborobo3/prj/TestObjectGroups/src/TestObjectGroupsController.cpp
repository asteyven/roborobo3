/**
 * @author Nicolas Bredeche <nicolas.bredeche@upmc.fr>
 *
 */

#include "TestObjectGroups/include/TestObjectGroupsController.h"

using namespace Neural;

TestObjectGroupsController::TestObjectGroupsController( RobotWorldModel *wm ) : TemplateEEController( wm )
{
    // superclass constructor called before this baseclass constructor.
    resetFitness(); // not used
}

TestObjectGroupsController::~TestObjectGroupsController()
{
    // superclass destructor automatically called after this baseclass destructor.
}

void TestObjectGroupsController::stepController()
{
    TemplateEEController::stepController();
}

void TestObjectGroupsController::initController()
{
    TemplateEEController::initController();
}

void TestObjectGroupsController::performSelection()
{
    TemplateEEController::performSelection();
}

void TestObjectGroupsController::performVariation()
{
    TemplateEEController::performVariation();
}

void TestObjectGroupsController::broadcastGenome()
{
    TemplateEEController::broadcastGenome();
}

double TestObjectGroupsController::getFitness()
{
    // mEDEA uses no fitness. Set to zero by default.
//    return 0;
	return TemplateEEController::getFitness();
}

void TestObjectGroupsController::resetFitness()
{
    // nothing to do
}

void TestObjectGroupsController::updateFitness()
{
    // nothing to do
}

void TestObjectGroupsController::logCurrentState()
{
    TemplateEEController::logCurrentState();
}
