#include <iostream>
#include <vector>
#include "MuMaterial.h"
#include "rhythm.hpp"
#include "melody.hpp"

using namespace std;

void PrintVector (auto const v, string message);

int main ()
{
    MuInit();

    Rhythm rhythm(4, 4, 60);
    rhythm.GenerateBaseRhythm(4);
    PrintVector(rhythm.rhythm_times, "rhythm_times");

    Melody melody;
    melody.GenerateBaseMelody(rhythm.rhythm_times);
    PrintVector(melody.base_melody, "base_melody");

    melody.material.SetDefaultFunctionTables();
    melody.material.Score("./output/score");
    melody.material.Orchestra("./output/orchestra");
    melody.material.Show();

    cout << endl << "Ok!" << endl;
    return 0;
}

void PrintVector (auto const v, string message)
{
    cout << message << ": ";
    for (unsigned int index = 0; index < v.size(); index++)
    {
        cout << v[index] << " ";
    }
    cout << endl;
}
