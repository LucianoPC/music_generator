#include "MuUtil.h"
#include "rhythm.hpp"

Rhythm::Rhythm (unsigned short time_unit, unsigned short compass_unit,
                unsigned short bpm)
{
    this->bpm = bpm;
    this->time_unit = time_unit;
    this->compass_unit = compass_unit;
}

void
Rhythm::GenerateBaseRhythm (unsigned short number_of_bars)
{

}

float
Rhythm::GetRandomNoteTime ()
{
    float note_times[] =      { 0.5f, 0.75f, 1.0f, 1.5f, 2.0f };
    int note_times_chance[] = {   10,    20,   40,   20,   10 };

    int chance = 0;
    int random_chance = Between(1, 100);
    for (int index = 0; index < 5; index++)
    {
        chance += note_times_chance[index];
        if (chance >= random_chance)
        {
            return note_times[index];
        }
    }

    return 1.0f;
}
