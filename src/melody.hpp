#ifndef _MELODY_H_
#define _MELODY_H_

#include <vector>
#include "MuMaterial.h"

using namespace std;

class Melody
{
public:
    static const short PITCHS[];

    Melody ();

    void GenerateBaseMelody (vector<float> rhythm_times);

    MuMaterial material;
    vector<short> base_melody;
};

#endif
