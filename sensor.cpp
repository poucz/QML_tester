#include "sensor.h"

void SENSOR::copy(const SENSOR &from, SENSOR &to)
{
    to.ID=from.ID;
    to.Name=from.Name;
}
