#include "len_point.h"

len_point::len_point(float x,float y)
{
    this->x = x;
    this->y = y;
}

float len_point::get_x()
{
    return x;
}

float len_point::get_y()
{
    return y;
}

len_length::len_length(len_point p1,len_point p2)
{

    this->p1 = p1;
    this->p2 = p2;
}
