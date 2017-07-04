#include <iostream>
#include <vector>
#include "MuMaterial.h"
#include "rhythm.hpp"
#include "melody.hpp"
#include "chord.hpp"

using namespace std;

void PrintVector (auto const v, string message);

int main ()
{
    MuInit();

    int n_compass = 4;
    float compass_time = 2.0f;

    int n_melodies = 10;

    Rhythm rhythm(n_compass, compass_time);
    rhythm.GenerateBaseRhythm();
    vector<Melody> melodies_begin;
    for(int i = 0; i < n_melodies; i++)
    {
        Melody melody;
        melody.GenerateBaseMelody(rhythm.rhythm_times);

        melodies_begin.push_back(melody);
    }

    rhythm = Rhythm(n_compass / 2, compass_time * 2.0f);
    rhythm.GenerateBaseRhythm();
    vector<Melody> melodies_middle;
    for(int i = 0; i < n_melodies; i++)
    {
        Melody melody;
        melody.GenerateBaseMelody(rhythm.rhythm_times);

        melodies_middle.push_back(melody);
    }

    Chord chord;
    MuMaterial material, tmp;

    int index = Between(0, n_melodies - 1);
    tmp = melodies_begin[index].material;
    material += chord.GenerateChordMaterial(tmp, n_compass);

    index = Between(0, n_melodies - 1);
    tmp = melodies_begin[index].material;
    int degree = Between(2, 5);
    tmp.DiatonicTranspose(0, MAJOR_MODE, degree, ASCENDING);
    material += chord.GenerateChordMaterial(tmp, n_compass);

    index = Between(0, n_melodies - 1);
    tmp = melodies_middle[index].material;
    int times = Between(1, 5);
    tmp.CycleRhythm(times);
    material += chord.GenerateChordMaterial(tmp, n_compass);

    index = Between(0, n_melodies - 1);
    tmp = melodies_middle[index].material;
    tmp.Scale(0.5f);
    material += tmp;

    index = Between(0, n_melodies - 1);
    tmp = melodies_middle[index].material;
    tmp.Retro();
    degree = Between(2, 5);
    tmp.DiatonicTranspose(0, MAJOR_MODE, degree, ASCENDING);
    material += chord.GenerateChordMaterial(tmp, n_compass);

    index = Between(0, n_melodies - 1);
    tmp = melodies_middle[index].material;
    material += chord.GenerateChordMaterial(tmp, n_compass);

    index = Between(0, n_melodies - 1);
    tmp = melodies_middle[index].material;
    degree = Between(2, 5);
    tmp.DiatonicTranspose(0, MAJOR_MODE, degree, ASCENDING);
    tmp.Retro();
    tmp = chord.GenerateChordMaterial(tmp, n_compass);
    tmp.Scale(0.75f);
    material += tmp;

    index = Between(0, n_melodies - 1);
    tmp = melodies_begin[index].material;
    tmp = chord.GenerateChordMaterial(tmp, n_compass * 2);
    tmp.Scale(0.75f);
    material += tmp;

    index = Between(0, n_melodies - 1);
    tmp = melodies_begin[index].material;
    material += chord.GenerateChordMaterial(tmp, n_compass);


    material.SetDefaultFunctionTables();
    material.Score("./output/score");
    material.Orchestra("./output/orchestra");
    material.Show();

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
