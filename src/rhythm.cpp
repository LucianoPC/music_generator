#include "rhythm.hpp"

Rhythm::Rhythm (unsigned short time_unit, unsigned short compass_unit,
                unsigned short bpm)
{
    this->bpm = bpm;
    this->time_unit = time_unit;
    this->compass_unit = compass_unit;
}
