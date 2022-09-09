#include "werkstueck.h"

Werkstueck::~Werkstueck() {}

/*
Die private Hilfsmethode getNearest(const IKomponente* pk) sucht unter den Elementen in der Komponenten-Liste das Element aus, welches den kleinsten euklidischen Abstand zur Komponente hat, auf die der Ubergabeparameter ¨ pk zeigt. Die
Ruckgabe erfolgt in der Form eines Iterators, dessen ¨ curr Attribut auf das entsprechende IKomponentenElement zeigt. Man kann dabei davon ausgehen, dass das
IKomponente-Objekt, auf das pk zeigt, nicht selber in der Komponenten-Liste vorhanden ist, denn im Algorithums, der in der Methode optimizePath() implementiert ist
(s. u.), wird genau dieses Objekt vorher aus der Komponenten-Liste entfernt.
*/
Iterator Werkstueck::getNearest(const IKomponente *pk) const {

}

// Solve approximately the Traveling Sales Man Problem (TSP) using a
// nearses neighbour strategy:
// round trip starts at the linking point of the Werkstueck.
// then go always to the nearest neighbour among the components
// that are not already on the new path
void Werkstueck::optimizePath() {
    if (!pathIsOptimized && komponenten.size() > 0) {
        // first call optimizePath for all Components,
        // which are of type Werkstueck recursively
        Iterator it = komponenten.begin();
        while (it != komponenten.end()) {
            Werkstueck* w = dynamic_cast<Werkstueck*>(*it);
            if (w != nullptr) {
            w->optimizePath();
            }
            ++it;
        }
        // Now determine a nearest neighbour-sorting
        // of all components
        DeList komponentenSortiert;
        IKomponente* pcurrent = this;
        Iterator nearest = getNearest(pcurrent);
        komponentenSortiert.push_back(*nearest);
        pcurrent = *nearest;
        komponenten.erase(nearest);
        while (komponenten.size() > 0) {
            nearest = getNearest(pcurrent);
            komponentenSortiert.push_back(*nearest);
            pcurrent = *nearest;
            komponenten.erase(nearest);
        }
        komponenten = komponentenSortiert;
        pathIsOptimized = true;
    }
}

/*
Frage: In welcher/welchen Methode(n) der Klasse Werkstueck ist das Attribut pathIsOptimized
wieder auf false zu setzen?
*/