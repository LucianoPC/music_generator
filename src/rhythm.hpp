#ifndef _RHYTHM_H_
#define _RHYTHM_H_

#include "MuMaterial.h"

class Rhythm
{
public:
    Rhythm (unsigned short time_unit, unsigned short compass_unit,
            unsigned short bpm);

    unsigned short bpm;
    unsigned short time_unit;
    unsigned short compass_unit;
};

#endif
