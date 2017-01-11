/*
 * LiskovSubstitution.h
 *
 *  Created on: Jan 11, 2017
 *      Author: LMA
 */

#ifndef LISKOVSUBSTITUTION_H_
#define LISKOVSUBSTITUTION_H_

/**
http://www.tomdalling.com/blog/software-design/solid-class-design-the-liskov-substitution-principle/

The Liskov Substitution Principle (LSP):
Functions that use pointers to base classes must be able to use objects of
derived classes without knowing it.

 */

class Bird
{
public:
	virtual ~Bird();
    virtual void setLocation(double longitude, double latitude) = 0;
    virtual void setAltitude(double altitude) = 0;
    virtual void draw() = 0;
};

// Penguin is-a-kind-of Bird, but it cannot fly
class Penguin : public Bird
{
    void setLocation(double longitude, double latitude);

    void setAltitude(double altitude)
    {
        //altitude can't be set because penguins can't fly
        //this function does nothing
    }

    void draw();
};

//The wrong way to do it, Open Closed Principle violated
void ArrangeBirdInPattern(Bird* pBird)
{
	Penguin* pPenguin = dynamic_cast<Penguin*>(pBird);
    if (pPenguin)
        ArrangeBirdOnGround(pPenguin);
    else
        ArrangeBirdInSky(pBird);
}

void ArrangeBirdOnGround(Penguin*);
void ArrangeBirdInSky(Bird*);

/**
The solution should be to make sure non-flying bird classes don't inherit flying functionality
from their super classes
 */
//Proper inheritance
class BirdBase
{
public:
	virtual ~BirdBase();
    virtual void draw() = 0;
    virtual void setLocation(double longitude, double latitude) = 0;
};

class FlyableBird : public BirdBase
{
public:
	virtual ~FlyableBird();
    virtual void setAltitude(double altitude) = 0;
};

class Penguin2 : public BirdBase
{
    void setLocation(double longitude, double latitude);
    void draw();
};

#endif /* LISKOVSUBSTITUTION_H_ */
