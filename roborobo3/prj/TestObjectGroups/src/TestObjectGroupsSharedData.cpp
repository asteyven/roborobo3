/**
 * @author Nicolas Bredeche <nicolas.bredeche@upmc.fr>
 *
 */

#include "TestObjectGroups/include/TestObjectGroupsSharedData.h"

// cf. super class for many parameter values initialization.
// Add here initialization for parameters that are specific to current implementation.
//
// Quick help:
//  if parameter is already defined in TemplateEEShareData, then use TemplateEEShareData::parametername
//  to define a new parameter, do it in TestObjectGroupsSharedData.h, initialize it in TestObjectGroupsSharedData.cpp, then use TestObjectGroupsSharedData::parametername
//

bool TestObjectGroupsSharedData::gPhysicalObjectRepositioning = false;
int TestObjectGroupsSharedData::gPhysicalObjectRepositionStartTime = gEvaluationTime * 0.1;
int TestObjectGroupsSharedData::gPhysicalObjectRepositionInterval = gEvaluationTime * 0.05;
