//-------------------------------------------------------------------
// Komponente
// Copyright 26.04.2022
// Author: Thomas Pongratz
//-------------------------------------------------------------------
#ifndef KOMPONENTE_H
#define KOMPONENTE_H

#include <iostream>
#include "ikomponente.h"

class Komponente : public IKomponente {
public:
    explicit Komponente(double xPos = 0.0, double yPos = 0.0);
    ~Komponente();
    double calcTotalPath() const;
    double getX() const;
    double getY() const;
    double getXAbsolute() const;
    double getYAbsolute() const;
    double distance(const IKomponente *k) const;
    const IKomponente* getParent() const;
    void setParent(const IKomponente *p);
    void output(std::ostream& os) const;

private:
    double x;
    double y;
    const IKomponente* parent();
};

#endif // KOMPONENTE_H
