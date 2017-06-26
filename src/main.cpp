#include <iostream>
#include "MuMaterial.h"
#include "rhythm.hpp"

using namespace std;

int main ()
{
    MuInit();

    Rhythm rhythm(4, 4, 60);

    cout << "Ok!" << endl;
    return 0;
}
