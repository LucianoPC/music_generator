#include <cstdlib>
#include "MuUtil.h"
#include "melody.hpp"

const short Melody::PITCHS[7] = { 60, 62, 64, 65, 67, 69, 71 };

Melody::Melody ()
{

}

void
Melody::GenerateBaseMelody (vector<float> rhythm_times)
{
    this->base_melody.clear();
    this->base_melody.push_back(0);

    int max_limit = 6;
    int up_limit = 1 * max_limit;
    int down_limit = -1 * max_limit;

    int notes_to_jump = 0;

    for (unsigned int index = 1; index < rhythm_times.size() - 1; index++)
    {
        short last_note = this->base_melody[index - 1];
        short note_number = Between(last_note + up_limit,
                                    last_note + down_limit);
        this->base_melody.push_back(note_number);

        short interval = note_number - last_note;
        if (abs(interval) >= 3)
        {
            up_limit = interval > 0 ? -1 : 1;
            down_limit = up_limit;
            notes_to_jump = 4;
        }
        else
        {
            up_limit = 1;
            down_limit = -1;
            notes_to_jump -= 1;
            if (notes_to_jump <= 0)
            {
                up_limit   *= max_limit;
                down_limit *= max_limit;
            }
        }
    }

    this->base_melody.push_back(0);


    MuNote note;
    note.SetInstr(1);
    note.SetAmp(1.0f);
    this->material = MuMaterial();
    for (unsigned int index = 0; index < this->base_melody.size(); index++)
    {
        short note_number = this->base_melody[index];
        int pitch_index = (note_number + 70) % 7;

        short pitch = Melody::PITCHS[pitch_index];

        if(note_number >= 0)
            pitch += (note_number / 7) * 12;
        else
            pitch += ((note_number / 7) - 1) * 12;

        note.SetPitch(pitch);
        note.SetDur(rhythm_times[index]);
        this->material += note;
    }
}
