/*
 * midi_msg.h
 *
 *  Created on: Oct 28, 2020
 *      Author: Zac
 */

#ifndef INC_MIDI_MSG_H_
#define INC_MIDI_MSG_H_

#include <stdint.h>

#define MIDI_PACKET_SIZE   (uint8_t)3

#define MIDI_NOTE_OFF      (uint8_t)0x80
#define MIDI_NOTE_ON       (uint8_t)0x90
#define MIDI_AFTERTOUCH    (uint8_t)0xA0
#define MIDI_CC_MESSAGE    (uint8_t)0xB0
#define MIDI_PATCH_CHANGE  (uint8_t)0xC0
#define MIDI_CHAN_PRESSURE (uint8_t)0xD0
#define MIDI_PITCH_BEND    (uint8_t)0xE0

typedef struct NoteMsg
{
	uint8_t channel;
	uint8_t command;
	uint8_t note;
	uint8_t velocity;
};

typedef struct CCMsg
{
	uint8_t channel;
	uint8_t command;
	uint8_t control_channel;
	uint8_t value;
};


#endif /* INC_MIDI_MSG_H_ */
