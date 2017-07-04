#ifndef _CHORD_H_
#define _CHORD_H_

#include "MuMaterial.h"

class Chord
{
public:
    Chord ();

    MuMaterial GenerateChordMaterial (MuMaterial material, int n_compass);

private:
    int GetDegreeFromMaterial (MuMaterial material);
};

#endif

