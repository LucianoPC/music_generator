#include "MuUtil.h"
#include "rhythm.hpp"

Rhythm::Rhythm (int n_compass, float compass_time)
{
    this->n_compass = n_compass;
    this->compass_time = compass_time;

    initializeRythms();

    cout << this->rhythms[0][0] << endl;
    cout << this->rhythms[1][0] << endl;
    cout << this->rhythms[2][0] << endl;
}

void
Rhythm::GenerateBaseRhythm ()
{
    this->rhythm_times.clear();

    for (int compass_i = 0; compass_i < this->n_compass; compass_i++)
    {
        float rhythm_time = compass_time;
        if (compass_i == this->n_compass - 1) rhythm_time -= 2.0f;

        int rhythm_size = this->rhythms.size() - 1;

        while (rhythm_time > 0)
        {
            vector<float> possible_times;

            int rhythm_index = Between(0, rhythm_size);

            float time = 0.0f;
            for (int i = 0; i < this->rhythms[rhythm_index].size(); i++)
                time += this->rhythms[rhythm_index][i];

            if (time <= rhythm_time)
            {
                rhythm_time -= time;
                for (int i = 0; i < this->rhythms[rhythm_index].size(); i++)
                    this->rhythm_times.push_back(this->rhythms[rhythm_index][i]);
            }
            else
            {
                rhythm_size = rhythm_index - 1;
            }
        }
    }
    this->rhythm_times.push_back(1.0f);
}

void
Rhythm::initializeRythms ()
{
    this->rhythms.push_back({ 0.25f });

    this->rhythms.push_back({ 0.50f });
    this->rhythms.push_back({ 0.25f, 0.25f });

    this->rhythms.push_back({ 0.75f });
    this->rhythms.push_back({ 0.50f, 0.25f });
    this->rhythms.push_back({ 0.25f, 0.50f });

    this->rhythms.push_back({ 1.00f });
    this->rhythms.push_back({ 0.50f, 0.50f });
    this->rhythms.push_back({ 0.25f, 0.75f });
    this->rhythms.push_back({ 0.75f, 0.25f });
    this->rhythms.push_back({ 0.50, 0.25f, 0.25f });
    this->rhythms.push_back({ 0.25f, 0.50, 0.25f });
    this->rhythms.push_back({ 0.25f, 0.25f, 0.50 });
    this->rhythms.push_back({ 0.25f, 0.25f, 0.25f, 0.25f });

    this->rhythms.push_back({ 2.00f });
    this->rhythms.push_back({ 1.50f, 0.50f });
    this->rhythms.push_back({ 0.50f, 1.50f });
    this->rhythms.push_back({ 1.50f, 0.25f, 0.25f });
    this->rhythms.push_back({ 0.25f, 1.50f, 0.25f });
    this->rhythms.push_back({ 0.25f, 0.25f, 1.50f });
    this->rhythms.push_back({ 0.75f, 0.75f, 0.50f });
    this->rhythms.push_back({ 0.75f, 0.50f, 0.75f });
    this->rhythms.push_back({ 0.50f, 0.75f, 0.75f });
}
