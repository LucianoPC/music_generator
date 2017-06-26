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
    this->rhythm_times.clear();

    for (unsigned short bar_index = 0; bar_index < number_of_bars; bar_index++)
    {
        float bar_time = this->time_unit;
        while(bar_time > 0)
        {
            vector<float> possible_times;
            for (float time = 0.25f; time <= 2.0f; time += 0.25)
            {
                if (time > bar_time) continue;
                int add_chance = 1;
                if ((int)(time * 100) % 50 == 0) add_chance = 3;
                if ((int)(time * 100) % 100 == 0) add_chance = 5;

                for (int index = 0; index < add_chance; index++)
                {
                    possible_times.push_back(time);
                }

                int time_index = Between(0, possible_times.size() - 1);
                float selected_time = possible_times[time_index];
                this->rhythm_times.push_back(selected_time);

                bar_time -= selected_time;
            }
        }
    }
}
