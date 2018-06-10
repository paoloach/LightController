/**************************************************************************************************

 DESCRIPTION:
  --

 CREATED: 17/06/2016, by Paolo Achdjian

 FILE: ClusterOccupancySensor.h

***************************************************************************************************/

#ifndef __CLUSTER_OCCUPANCY_SENSING__H__
#define __CLUSTER_OCCUPANCY_SENSING__H__
#include "zclReadAttributeFn.h"
#include "zclWriteAttributeFn.h"

void occupancyClusterInit(uint16 taskId);
void occupancyClusterReadAttribute(zclAttrRec_t *);
void occupancyClusterWriteAttribute(ZclWriteAttribute_t *);
void occupancyOn(void);
void occupancyOff(void);

#endif