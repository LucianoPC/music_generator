#include <iostream>
#include <vector>
#include "MuMaterial.h"
#include "rhythm.hpp"

using namespace std;

void PrintVector (auto const v, string message);

int main ()
{
    MuInit();

    Rhythm rhythm(4, 4, 60);

    rhythm.GenerateBaseRhythm(2);

    vector<float> base_rhythm = rhythm.base_rhythm;

    PrintVector(rhythm.base_rhythm, "base_rhythm");


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
