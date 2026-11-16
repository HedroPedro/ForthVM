#ifndef SENSOR_H_
#define SENSOR_H_
#include "common.h"

typedef word sensor_t;

void sensor_init(sensor_t *sensors, size_t size);
word sensor_get_value(sensor_t *sensors, word id);
void sensor_write_value(sensor_t *sensors, word id, word value);

#endif
