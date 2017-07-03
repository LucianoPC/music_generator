#include "MuUtil.h"
#include "rhythm.hpp"

Rhythm::Rhythm (int n_compass, float compass_time)
{
    this->n_compass = n_compass;
    this->compass_time = compass_time;
}

void
Rhythm::GenerateBaseRhythm ()
{
    this->rhythm_times.clear();

    for (int compass_i = 0; compass_i < this->n_compass; compass_i++)
    {
        float rhythm_time = compass_time;
        if (compass_i == this->n_compass - 1) rhythm_time -= 1.0f;

        while(rhythm_time > 0)
        {
            vector<float> possible_times;
            for (float time = 0.25f; time <= 2.0f; time += 0.25)
            {
                if (time > rhythm_time) continue;

                int add_chance = 1;
                if ((int)(time * 100) % 50 == 0) add_chance = 2;
                if ((int)(time * 100) % 100 == 0) add_chance = 3;

                for (int index = 0; index < add_chance; index++)
                    possible_times.push_back(time);

                int time_index = Between(0, possible_times.size() - 1);
                float selected_time = possible_times[time_index];
                this->rhythm_times.push_back(selected_time);

                rhythm_time -= selected_time;
            }
        }
    }
    this->rhythm_times.push_back(1.0f);
}
