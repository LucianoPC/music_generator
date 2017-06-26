#ifndef _RHYTHM_H_
#define _RHYTHM_H_

#include <vector>
#include "MuMaterial.h"

class Rhythm
{
public:
    Rhythm (unsigned short time_unit, unsigned short compass_unit,
            unsigned short bpm);

    void GenerateBaseRhythm (unsigned short number_of_bars);
    float GetRandomNoteTime ();

    vector<float> base_rhythm;

    unsigned short bpm;
    unsigned short time_unit;
    unsigned short compass_unit;
};

#endif
