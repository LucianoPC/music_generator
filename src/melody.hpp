#ifndef _MELODY_H_
#define _MELODY_H_

#include <vector>

using namespace std;

class Melody
{
public:
    static const short PITCHS[7];

    Melody ();

    void GenerateBaseMelody (unsigned short number_of_notes);

    vector<short> base_melody;
};

#endif
