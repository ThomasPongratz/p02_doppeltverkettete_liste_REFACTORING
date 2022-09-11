#ifndef WERKSTUECK_H
#define WERKSTUECK_H

#include "komponente.h"
#include "delist.h"

class Werkstueck : public Komponente {
    public:
        Werkstueck(double xPos = 0.0, double yPos = 0.0, double h = 1, double w = 1) 
            : Komponente{xPos, yPos}, height{h}, width{w}, pathIsOptimized{false} {}
        ~Werkstueck();
        double getHeight() const { return height; }
        double getWidth() const { return width; }
        void add(Komponente *k);
        void remove(const IKomponente * k);
        const IKomponente* getChild(int i) const;
        double calcTotalPath();
        double calcTotalLength();
        void optimizePath();
        void output(std::ostream &os) const;

    private:
        double height;
        double width;
        bool pathIsOptimized;
        DeList komponenten;
        Iterator getNearest(const IKomponente *pk) const;
};

#endif