#ifndef IKOMPONENTENELEMENT_H
#define IKOMPONENTENELEMENT_H

#include "ikomponente.h"

struct IKomponentenElement {
    IKomponente *k;
    IKomponentenElement *before;
    IKomponentenElement *next;
};

#endif