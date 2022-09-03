#ifndef DELIST_H
#define DELIST_H

#include "ikomponentenelement.h"
#include "iterator.h"

class DeList {
    public:
        DeList() : counter{0}, first{nullptr} {}

        // CopyKonstruktor
        DeList(const DeList &rhs);
                                
        ~DeList() { clear(); }

        // CopyZuweisungsOperator
        DeList& operator=(const DeList &rhs);
                       
        void clear() {
            
        }

        int size() const { return counter; }

        Iterator erase(Iterator pos) {
            
        }
        void push_back(IKomponente *k) {
            if (k != nullptr) {
                IKomponentenElement *newElement = new IKomponentenElement;
                newElement->k = k;
                newElement->next = nullptr;
                IKomponentenElement *tmp = first;
                while (tmp->next != nullptr) {
                    tmp = tmp->next;
                }
                tmp->before = ;
            }
        }

        Iterator end() const { return Iterator(nullptr); }

        Iterator begin() const { return Iterator(first); }

    private:
        int counter;
        IKomponentenElement *first;

        // getElement() noetig fuer erase()
        IKomponentenElement* getElement(Iterator it) const {
            IKomponentenElement *pElement = first;
            Iterator iter = begin();
            while (iter != it && it != end()) {
                pElement = pElement->next;
                ++iter;
            }
            return pElement;
        }
};

#endif
