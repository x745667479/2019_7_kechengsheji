#ifndef LEN_POINT_H
#define LEN_POINT_H
#include <math.h>

class len_point
{
public:
    len_point(float a=0,float b=0)
    {
        x = a;
        y = b;
    }
    float get_x()
    {
        return  x;
    }
    float get_y()
    {
        return y;
    }

private:
    float x;
    float y;
};

class len_length
{
public:
    len_length(len_point q1,len_point q2)
    {
      p1 = q1;
      p2 = q2;
      float q = q1.get_x()-q2.get_x();
      float p = q1.get_y()-q2.get_y();
      length = int(sqrt(p*p+q*q));
    }
    float get_length()
    {
        return  length;
    }

private:
    len_point p1,p2;
    float length;

};

#endif // LEN_POINT_H
