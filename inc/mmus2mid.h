#if !defined(__MMUS2MID_H__)
#define __MMUS2MID_H__

#include "doomtype.h"

#define MIDI_TRACKS 32

typedef struct                          // a midi file
{
    int                 divisions;      // number of tics per quarter note

    struct
    {
        unsigned char   *data;          // MIDI message stream
        size_t          len;            // length of the track data
    } track[MIDI_TRACKS];
} MIDI;

dboolean mmuscheckformat(uint8_t *mus, int size);
dboolean mmus2mid(uint8_t *mus, size_t size, MIDI *mididata);
void MIDIToMidi(const MIDI *mididata, uint8_t **mid, int *midlen);
void FreeMIDIData(MIDI *mididata);

#endif
