//-------------------------------------------------------------------
// Fraesung
// Copyright 26.04.2022
// Author: Thomas Pongratz
//-------------------------------------------------------------------
#ifndef FRAESUNG_H
#define FRAESUNG_H

#include <cmath>
#include "bohrung.h"

class Fraesung : public Bohrung {
public:
    explicit Fraesung(double x, double y, double diam, double l, double a = 0.0)
        : Bohrung(x, y, diam), length{l}, angle{a} {
        l < 0 ? length = 0 : length = l;
    }
    ~Fraesung();
    double calcTotalPath() const { return 2 * length; }
    double getLength() const { return length; }
    double getAngle() const { return angle; }
    double getEndX() const {
        return getX() + cos(getAngle()) * getLength();
    }
    double getEndY() const {
        return getY() + sin(getAngle()) * getLength();
    }
    void output(std::ostream& os) const {
        os << "Fraesung mit Start: ";
        Komponente::output(os);
        os << " und Endpunkt: ("
        << getEndX() << ", "
        << getEndY() << "), Durchmesser: "
        << getDiameter();
    }

private:
    double length;
    double angle;
};

#endif // FRAESUNG_H
