/*
 * freertos_util.h
 *
 *  Created on: 24 de may. de 2017
 *      Author: cubecat
 */

#ifndef FREERTOS_UTIL_H_
#define FREERTOS_UTIL_H_

#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "queue.h"
#include "semphr.h"
#include "event_groups.h"
#include "FreeRTOSConfig.h"

#include "utils.h"

extern TaskHandle_t ControlTaskHandle;

extern TaskHandle_t InterfaceTaskHandle;

extern TaskHandle_t CommsTaskHandle;
extern TaskHandle_t CommsTxTaskHandle;

extern QueueHandle_t RadioPacketTxQueueHandle;
extern QueueHandle_t RadioPacketRxQueueHandle;

extern QueueHandle_t LinkLayerRxQueueHandle;

extern QueueHandle_t UartQueueRxHandle;
extern QueueHandle_t UartQueueTxHandle;

extern QueueHandle_t ControlPacketQueueHandle;

extern SemaphoreHandle_t SimpleLinkMutexHandle;

extern TaskHandle_t     tasks_ids[4];
extern uint32_t         tasks_full_stack[4];

#define GDO_NOTIFY_GDO0                 (1 << 0)
#define GDO_NOTIFY_GDO2                 (1 << 1)
#define COMMS_NOTIFY_SEND_REQ           (1 << 2)
#define COMMS_NOTITY_PHY_RECEIVED       (1 << 3)
#define COMMS_NOTIFY_END_TX             (1 << 4)
#define COMMS_NOTIFY_RESET              (1 << 5)

#define COMMS_WAIT_TIME                 1000 /* ms */

#define IFACE_NOTIFY_TX_END             (1 << 0)
#define IFACE_NOTIFY_TX_REQ             (1 << 1)
#define IFACE_NOTIFY_RX                 (1 << 2)
#define IFACE_NOTIFY_ERROR              (1 << 3)

#define CTRL_HK_DMA_END                 (1 << 0)

typedef enum return_values_e {
    func_error     = -1,
    func_ok        = 0,
    func_data      = 1,
}return_values_t;

void init_freertos_tasks(void);

#endif /* FREERTOS_UTIL_H_ */
