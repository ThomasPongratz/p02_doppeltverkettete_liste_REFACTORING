#ifndef ITERATOR_H
#define ITERATOR_H

#include "ikomponentenelement.h"

class Iterator {
    public:
        explicit Iterator(IKomponentenElement *begin = nullptr) : curr{begin} {}
        ~Iterator();
        Iterator& operator++();
        bool operator!=(const Iterator &it);
        bool operator==(const Iterator &it);
        IKomponente* operator*();
        
    private:
        IKomponentenElement *curr;
};

#endif