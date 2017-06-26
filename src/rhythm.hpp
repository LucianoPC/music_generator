#ifndef _RHYTHM_H_
#define _RHYTHM_H_

#include <vector>

using namespace std;

class Rhythm
{
public:
    Rhythm (float time);

    void GenerateBaseRhythm ();

    vector<float> rhythm_times;

    float time;
};

#endif
