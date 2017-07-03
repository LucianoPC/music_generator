#ifndef _RHYTHM_H_
#define _RHYTHM_H_

#include <vector>

using namespace std;

class Rhythm
{
public:
    Rhythm (int n_compass, float compass_time);

    void GenerateBaseRhythm ();

    vector<float> rhythm_times;

    int n_compass;
    float compass_time;

private:
    vector< vector<float> > rhythms;

    void initializeRythms ();
};

#endif
