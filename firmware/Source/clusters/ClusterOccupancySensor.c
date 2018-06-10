/**************************************************************************************************

 DESCRIPTION:
  --

 CREATED: 17/06/2016, by Paolo Achdjian

 FILE: ClusterOccupancySensor.c

***************************************************************************************************/

#include "ClusterOccupancySensor.h"
#include "zcl.h"
#include "ioCC2530.h"
#include "ClusterOSALEvents.h"
#include "hal_mcu.h"
#include "zcl_general.h"
#include "AddrMgr.h"
#include "bitIO.h"

static uint8 occupancy=0;
static uint16 occCounter;
static uint8 occupancySensorType=0;
static uint16 occupiedToUnoccupied=0;
static uint16 unoccupiedToOccupied=0;
static uint8  unoccupiedToOccupiedThreshold=1;
static uint16 mainAppTaskId;

#define SENSOR_IN	P0_0
#define SENSOR_DIR DIR0_0
#define SENSOR_SEL	P0SEL_0
#define SENSOR_IEN  P0IEN_0
#define SENSOR_IF   P0IF0
#define SENSOR_IPORT P0ICON
#define SENSOR_IPORT_ENABLE P0IE



static void sendCmdToBindDevices(uint8 cmd);

void occupancyClusterInit(uint16 taskId ) {
	mainAppTaskId = taskId;
	occupancy=0;
	occupancySensorType=0;
	occupiedToUnoccupied=0;
	unoccupiedToOccupied=0;
	unoccupiedToOccupiedThreshold=1;
	
	SENSOR_SEL =0;
	SENSOR_DIR=0;
	SENSOR_IF=0;
	SENSOR_IPORT=0;
	SENSOR_IEN=1;
	SENSOR_IPORT_ENABLE = 1;
	EA=1;
}

void occupancyClusterReadAttribute(zclAttrRec_t *statusRec){
	if (statusRec == NULL){
		return;
	}
	statusRec->status=ZCL_STATUS_SUCCESS;
	switch(statusRec->attrId){
		case 0:
			statusRec->dataType = ZCL_DATATYPE_BITMAP8;
			statusRec->dataPtr = (void *)&occupancy;
			break;
		case 1:
			statusRec->dataType = ZCL_DATATYPE_ENUM8;
			statusRec->dataPtr = (void *)&occupancySensorType;
			break;
		case 0x10:
			statusRec->dataType = ZCL_DATATYPE_UINT16;
			statusRec->dataPtr = (void *)&occupiedToUnoccupied;
			break;
		case 0x11:
			statusRec->dataType = ZCL_DATATYPE_UINT16;
			statusRec->dataPtr = (void *)&unoccupiedToOccupied;
			break;
		case 0x12:
			statusRec->dataType = ZCL_DATATYPE_UINT8;
			statusRec->dataPtr = (void *)&unoccupiedToOccupiedThreshold;
			break;
		default:
			statusRec->status = ZCL_STATUS_UNSUPPORTED_ATTRIBUTE;
	}
}
void occupancyClusterWriteAttribute(ZclWriteAttribute_t *writeAttribute){
		if (writeAttribute == NULL){
		return;
	}
	writeAttribute->status=ZCL_STATUS_SUCCESS;
	switch(writeAttribute->attrId){
		case 0:
		case 1:
			writeAttribute->status=ZCL_STATUS_READ_ONLY;
			break;
		case 0x10:
			if (writeAttribute->dataType == ZCL_DATATYPE_UINT16){
				occupiedToUnoccupied = *(uint16 *)writeAttribute->dataPtr;
			}else
				writeAttribute->status = ZCL_STATUS_INVALID_DATA_TYPE;
		break;
		case 0x11:
			if (writeAttribute->dataType == ZCL_DATATYPE_UINT16){
				unoccupiedToOccupied = *(uint16 *)writeAttribute->dataPtr;
			}else
				writeAttribute->status = ZCL_STATUS_INVALID_DATA_TYPE;
		break;
		case 0x12:
			if (writeAttribute->dataType == ZCL_DATATYPE_UINT8){
				unoccupiedToOccupiedThreshold = *(uint8 *)writeAttribute->dataPtr;
			}else
				writeAttribute->status = ZCL_STATUS_INVALID_DATA_TYPE;
		break;
		default:
			writeAttribute->status = ZCL_STATUS_UNSUPPORTED_ATTRIBUTE;
	}
}

void occupancyOn(void) {
	occupancy=1;
	sendCmdToBindDevices(COMMAND_ON);
}
void occupancyOff(void){
	occupancy=0;
	sendCmdToBindDevices(COMMAND_OFF);
}

void sendCmdToBindDevices(uint8 cmd){
	/*
	BindingEntry_t * bindEntry;
	bindEntry = bindFind(ENDPOINT_ONOFF_SWITCH, ZCL_CLUSTER_ID_GEN_ON_OFF,0);
	if( bindEntry){
		AddrMgrEntry_t entry;
		entry.user = ADDRMGR_USER_BINDING;
		entry.index = bindEntry->dstIdx;
		uint8 stat = AddrMgrEntryGet( &entry );
		if (stat){
			afAddrType_t onOffSendaddr;
			onOffSendaddr.addrMode = afAddr16Bit;
			onOffSendaddr.addr.shortAddr = entry.nwkAddr;
			onOffSendaddr.endPoint=bindEntry->dstEP;
			zcl_SendCommand(ENDPOINT_ONOFF_SWITCH, &onOffSendaddr, ZCL_CLUSTER_ID_GEN_ON_OFF,cmd, TRUE, ZCL_FRAME_CLIENT_SERVER_DIR, TRUE, 0, 0, 0,NULL);
		}
	}
*/
}

HAL_ISR_FUNCTION(occupancySensor_ISR, P0INT_VECTOR){
	HAL_ENTER_ISR();
	if (SENSOR_IF){
		if (SENSOR_IPORT == 0){
			SENSOR_IPORT=1;
		} else{
			SENSOR_IPORT=0;
		}
	}
	SENSOR_IF=0;
	HAL_EXIT_ISR();
}