#include "zcl.h"
#include "AF.h"
#include "zcl_ha.h"

#include "LightController.h"


#define DEVICE_VERSION     0
#define FLAGS              0


const cId_t lightControllerInClusterList[] ={
	ZCL_CLUSTER_ID_GEN_BASIC,
	ZCL_CLUSTER_ID_GEN_IDENTIFY,
	ZCL_CLUSTER_ID_GEN_POWER_CFG
};

const cId_t lightControllerOutClusterList[] ={
	ZCL_CLUSTER_ID_GEN_BASIC,
    ZCL_CLUSTER_ID_GEN_IDENTIFY
};



SimpleDescriptionFormat_t litghControllerSimpleDesc = {
	ENDPOINT,                  			//  int Endpoint;
	ZCL_HA_PROFILE_ID,                	//  uint16 AppProfId[2];
	ZCL_HA_DEVICEID_DIMMABLE_LIGHT,     	//  uint16 AppDeviceId[2];
	DEVICE_VERSION,           			//  int   AppDevVer:4;
	FLAGS,                    			//  int   AppFlags:4;
	sizeof(lightControllerInClusterList)/2,              //  byte  AppNumInClusters;
	(cId_t *)lightControllerInClusterList, 	//  byte *pAppInClusterList;
	sizeof(lightControllerOutClusterList)/2,           //  byte  AppNumInClusters;
	(cId_t *)lightControllerOutClusterList 	//  byte *pAppInClusterList;
};

