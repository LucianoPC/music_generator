#include "MuUtil.h"
#include "melody.hpp"

const short Melody::PITCHS[7] = { 60, 62, 64, 65, 67, 69, 71 };

Melody::Melody ()
{

}

void
Melody::GenerateBaseMelody (unsigned short number_of_notes)
{
    this->base_melody.clear();

    this->base_melody.push_back(0);

    for (int index = 1; index < number_of_notes - 1; index++)
    {
        short last_note = this->base_melody[index - 1];
        short note = Between(last_note + 3, last_note - 3);
        this->base_melody.push_back(note);
    }

    this->base_melody.push_back(0);


    for (int index = 0; index < number_of_notes; index++)
    {
        short note = this->base_melody[index];
        int pitch_index = (note + 70) % 7;

        short pitch = Melody::PITCHS[pitch_index];
        pitch += (note / 7) * 12;

        this->base_melody[index] = pitch;
    }
}
