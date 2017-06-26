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
    rhythm.GenerateBaseRhythm(2);
    PrintVector(rhythm.base_rhythm, "base_rhythm");

    Melody melody;
    melody.GenerateBaseMelody(rhythm.base_rhythm);
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
