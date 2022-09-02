//-------------------------------------------------------------------
// Bohrung
// Copyright 26.04.2022
// Author: Thomas Pongratz
//-------------------------------------------------------------------
#ifndef BOHRUNG_H
#define BOHRUNG_H

#include "komponente.h"

class Bohrung : public Komponente {
public:
    explicit Bohrung(double x_ = 0.0, double y_ = 0.0, double diam = 6.0)
        : Komponente(x_, y_), diameter{diam} {
        diam <= 0 ? diameter = 6.0 : diameter = diam;
    }
    double getDiameter() const { return diameter; }
    void output(std::ostream& os) const {
        os << "Bohrung: ";
        Komponente::output(os);
        os << ", Durchmesser: " << getDiameter();
    }
    
private:
    double diameter;
};

#endif // BOHRUNG_H
