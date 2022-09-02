#ifndef DELIST_H
#define DELIST_H

#include "ikomponentenelement.h"
#include "iterator.h"

class DeList {
    public:
        DeList();
        DeList(const DeList &rhs);
        ~DeList();
        DeList& operator=(const DeList &rhs);
        void clear();
        int size();
        Iterator erase(Iterator pos);
        void push_back(IKomponente *k);
        Iterator end();
        Iterator begin();

    private:
        int counter;
        IKomponentenElement *first;
        IKomponentenElement* getElement(Iterator it) const;
};

#endif
