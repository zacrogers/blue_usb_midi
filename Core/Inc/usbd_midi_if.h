/**
  ******************************************************************************
  * @file           : usbd_midi_if.h
  * @brief          : Header for usbd_midi_if file.
  ******************************************************************************
*/

#ifndef __USBD_MIDI_IF_H
#define __USBD_MIDI_IF_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "usbd_midi.h"
#include "usbd_desc.h"
#include "stdbool.h"

extern USBD_HandleTypeDef hUsbDeviceFS;
extern USBD_MIDI_ItfTypeDef  USBD_Interface_fops_FS;

extern void sendMidiMessage(uint8_t *msg, uint16_t size);
extern uint8_t USBD_MIDI_SendData (USBD_HandleTypeDef *pdev, uint8_t *pBuf, uint16_t length);


void midi_note_on(uint8_t channel, uint8_t note, uint8_t velocity);
void midi_note_off(uint8_t channel, uint8_t note, uint8_t velocity);
void midi_note_send(uint8_t channel, bool on, uint8_t note, uint8_t velocity);

void midi_send_cc();

// Call in main loop
extern void processMidiMessage(void);
extern void USBD_MIDI_SendPacket(void);



#ifdef __cplusplus
}
#endif
  
#endif /* __USBD_MIDI_IF_H */
