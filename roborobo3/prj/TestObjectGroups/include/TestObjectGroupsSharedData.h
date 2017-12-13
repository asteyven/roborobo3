/**
 * @author Nicolas Bredeche <nicolas.bredeche@upmc.fr>
 *
 */



#ifndef TESTOBJECTGROUPSSHAREDDATA_H
#define TESTOBJECTGROUPSSHAREDDATA_H

#include "TemplateEE/include/TemplateEESharedData.h"

class TestObjectGroupsSharedData : TemplateEESharedData {

	// cf. super class for many parameter values.

public:

	// -----
    
	// Add here parameters that are specific to current implementation.
	static bool gPhysicalObjectRepositioning;
	static int gPhysicalObjectRepositionStartTime;
	static int gPhysicalObjectRepositionInterval;
}; 


#endif
