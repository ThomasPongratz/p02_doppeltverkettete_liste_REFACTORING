#ifndef ITERATOR_H
#define ITERATOR_H

#include "ikomponentenelement.h"

class Iterator {
    public:
        explicit Iterator(IKomponentenElement *begin = nullptr) : curr{begin} {}
        ~Iterator();
        Iterator& operator++() {
            if (curr->next != nullptr) {
                curr = curr->next;
            } else {
                curr = nullptr;
            }
            return *this;
        }
        bool operator!=(const Iterator &it) {
            bool erg;
            if (this->curr != it.curr) {
                erg = true;
            } else {
                erg = false;
            }
            return erg;
        }
        bool operator==(const Iterator &it) {
            bool erg;
            if (this->curr == it.curr) {
                erg = true;
            } else {
                erg = false;
            }
            return erg;
        }
        IKomponente* operator*() const { return curr->k; }
        
    private:
        IKomponentenElement *curr;
};

#endif