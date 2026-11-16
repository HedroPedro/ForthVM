#include "sensor.h"

void sensor_init(sensor_t *sensors, size_t size) {
	memset((void *) sensors, 0, sizeof(sensor_t) * size);
}

word sensor_get_value(sensor_t *sensors, word id) {
	return sensors[id];
}

void sensor_write_value(sensor_t *sensors, word id, word value) {
	sensors[id] = value;
}
