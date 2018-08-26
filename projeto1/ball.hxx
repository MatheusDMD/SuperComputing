#ifndef __BALL_HXX__
#define __BALL_HXX__

class ball {
private:
    int id;
    double radius; 
    double mass;

public:
    double x0;
    double y0;
    double vx0;
    double vy0;
    ball(int id, double radius, double mass, double x0, double y0, double vx0, double vy0);
    ball(int id, double radius, double mass, double x0, double y0, double vx0, double vy0)
    : id(id),
    radius(radius), 
    mass(mass),
    x0(x0),
    y0(y0),
    vx0(vx0),
    vy0(vy0)
    {};

    ~ball();
};

#endif