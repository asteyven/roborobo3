/**
 * @author Nicolas Bredeche <nicolas.bredeche@upmc.fr>
 *
 */

#ifndef TESTOBJECTGROUPSWORLDOBSERVER_H
#define TESTOBJECTGROUPSWORLDOBSERVER_H

#include "TemplateEE/include/TemplateEEWorldObserver.h"

class World;

class TestObjectGroupsWorldObserver : public TemplateEEWorldObserver
{
public:
    TestObjectGroupsWorldObserver(World *world);
    ~TestObjectGroupsWorldObserver();
    
    void initPre();
    void initPost();

    void stepPre();
    void stepPost();
    
    void updateEnvironment();

    void monitorPopulation( bool localVerbose );
};

#endif
