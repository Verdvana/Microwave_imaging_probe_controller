#ifndef __SEGMENTDISPLAY_H
#define __SEGMENTDISPLAY_H

#include "stm32f10x.h"

void Segment_GPIO_Config(void);

void Segment1(uint8_t s);
void Segment2(uint8_t s);
void Segment_Reset(void);

#endif /* __SEGMENTDISPLAY_H */

