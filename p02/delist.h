#ifndef DELIST_H
#define DELIST_H

#include "ikomponentenelement.h"
#include "iterator.h"

class DeList {
    public:
        DeList() : counter{0}, first{nullptr} {}

        // CopyKonstruktor
        DeList(const DeList &rhs) : DeList() {
            auto it = rhs.begin();
            while (it != rhs.end()) {
                push_back(*it);
                ++it;
            }   
        }
                                
        ~DeList() { clear(); }

        // CopyZuweisungsOperator
        DeList& operator=(const DeList &rhs) {
            if (this != &rhs) {
                clear();
                Iterator it = rhs.begin();
                while (it != rhs.end()) {
                    push_back(*it);
                    ++it;
                }
            }
            return *this;
        }

        void clear() {
            IKomponentenElement* tmp = nullptr;
            while (first != nullptr) {
                tmp = first->next;
                delete first;
                first = tmp;
            }
            counter = 0;
        }

        int size() const { return counter; }

        Iterator erase(Iterator pos) {
            IKomponentenElement* pActual = getElement(pos);
            Iterator iResult = Iterator{pActual};
            if (pActual != nullptr) {
                IKomponentenElement* pNext = pActual->next;
                IKomponentenElement* pBefore = pActual->before;
                if (pNext != nullptr) {
                    pNext->before = pBefore;
                }
                if (pBefore != nullptr) {
                    pBefore->next = pNext;
                }
                if (pActual == first) {
                    first = pActual->next;
                    if (first != nullptr) {
                        first->before = nullptr;
                    }
                }
                delete pActual;
                --counter;
                iResult = Iterator(pNext);
            }
            return iResult;
        }
        
        void push_back(IKomponente *k) {
            if (k != nullptr) {
                IKomponentenElement *pNewElement = new IKomponentenElement;
                pNewElement->k = k;
                pNewElement->next = nullptr;
                if (first != nullptr) {
                    IKomponentenElement *pCurrent = first;
                    for (int i = 0; i < counter && pCurrent->next != nullptr; ++i) {
                        pCurrent = pCurrent->next;
                    }
                    pCurrent->next = pNewElement;
                    pNewElement->before = pCurrent;
                } else {
                    pNewElement->before = nullptr;
                    first = pNewElement;
                }
                ++counter;
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
            while (it != end() && iter != it) {
                pElement = pElement->next;
                ++iter;
            }
            return pElement;
        }
};

#endif
