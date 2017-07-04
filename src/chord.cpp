#include <map>
#include <vector>
#include "MuUtil.h"
#include "chord.hpp"

Chord::Chord ()
{
}

MuMaterial
Chord::GenerateChordMaterial(MuMaterial material, int n_compass)
{
    MuMaterial chord_material = material;

    int segments = n_compass;

    MuMaterial segments_material = material.Segments(segments);
    int voices = segments_material.NumberOfVoices();

    for(int index = 0; index < voices; index++)
    {
        MuMaterial voice_material = segments_material.GetVoice(index);

        int degree;
        if( (index == 0) || (index == (voices - 1)) )
            degree = 1;
        else
            degree = GetDegreeFromMaterial(voice_material);

        MuMaterial triad_material;
        triad_material.MajorTriad(voice_material.Dur());

        if(degree != 1)
        {
            triad_material.DiatonicTranspose(0, MAJOR_MODE, degree, ASCENDING);
            triad_material.DiatonicTranspose(0, MAJOR_MODE, 8, DESCENDING);
        }

        triad_material.DiatonicTranspose(0, MAJOR_MODE, 8, DESCENDING);

        chord_material.Append(1, triad_material, 0);
    }

    chord_material.SetAmp(0, 1.0f);
    chord_material.SetAmp(1, 0.1f);
    chord_material.SetInstrument(0, 1);
    chord_material.SetInstrument(1, 2);

    return chord_material;
}

int
Chord::GetDegreeFromMaterial (MuMaterial material)
{
    int note_pitch = material.GetFirstNote().Pitch() % 12;

    map<int, int> degree_map = { {0, 1}, {1, 1}, {2, 2}, {3, 2}, {4, 3},
                                 {5, 4}, {6, 4}, {7, 5}, {8, 5}, {9, 6},
                                 {10, 6}, {11, 7}};

    vector<int> possible_degrees = { degree_map[note_pitch],
                                     degree_map[note_pitch] };

    for(int index = 0; index < material.NumberOfNotes(); index++) {
        int note_degree = degree_map[material.GetNote(index).Pitch()];

        possible_degrees.push_back(note_degree);
        possible_degrees.push_back((note_degree + 4) % 7);
        possible_degrees.push_back((note_degree + 6) % 7);
    }

    int degree_index = Between(0, possible_degrees.size() - 1);

    int degree = possible_degrees[degree_index] % 12;

    return degree;

}
