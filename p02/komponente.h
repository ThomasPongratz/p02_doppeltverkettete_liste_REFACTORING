//-------------------------------------------------------------------
// Komponente
// Copyright 26.04.2022
// Author: Thomas Pongratz
//-------------------------------------------------------------------
#ifndef KOMPONENTE_H
#define KOMPONENTE_H

#include <iostream>
#include <cmath>
#include "ikomponente.h"

class Komponente : public IKomponente {
public:
    explicit Komponente(double xPos = 0.0, double yPos = 0.0) 
        : x{xPos}, y{yPos} {}

    ~Komponente();

    double calcTotalPath() const { return 0.0; }

    double getX() const { return x; }
    
    double getY() const { return y; }
    
    double getXAbsolute() const {
        double erg = getX();
        if (parent != nullptr) {
            erg += parent->getXAbsolute();
        }
        return erg;
    }
    /*
    double getXAbsolute() const {
        double erg = 0.0;
        if (parent != nullptr) {
            erg = getX() + parent->getXAbsolute();
        } else {
            erg = getX();
        }
        return erg;
    }
    */
    double getYAbsolute() const {
        double erg = getY();
        if (parent != nullptr) {
            erg += parent->getYAbsolute();
        }
        return erg;
    }
    /*
    double getYAbsolute() const {
        double erg = 0.0;
        if (parent != nullptr) {
            erg = getY() + parent->getYAbsolute();
        } else {
            erg = getY();
        }
        return erg;
    }
    */
    double distance(const IKomponente *k) const {
        return sqrt(pow(this->getXAbsolute() - k->getXAbsolute(), 2) 
            + pow(this->getYAbsolute() - k->getXAbsolute(), 2));
    }
    
    const IKomponente* getParent() const { return parent; }
    
    void setParent(const IKomponente *p) { parent = p; }
    
    void output(std::ostream& os) const {
        os << "(" << getX() << ", " << getY() << ")";
    }

private:
    double x;
    double y;
    const IKomponente* parent;
};

#endif // KOMPONENTE_H
