#include <iostream>
#include "MuMaterial.h"
#include "rhythm.hpp"

using namespace std;

int main ()
{
    MuInit();

    Rhythm rhythm(4, 4, 60);

    float note_time = rhythm.GetRandomNoteTime();

    cout << "note_time: " << note_time << endl;

    cout << endl << "Ok!" << endl;
    return 0;
}
