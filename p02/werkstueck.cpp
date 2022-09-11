#include "werkstueck.h"
/*
Design Pattern/Entwurfsmuster: Composite
hier:   Um Objekte zu Baumstrukturen hinzuzufuegen und um 
        Teil-Ganzes-Hierarchie zu realisieren.
*/

Werkstueck::~Werkstueck() {}

/*
Die Methode add(IKomponente* k) fugt die als Zeiger ¨ ubergebene Komponente am 
¨ Ende der Komponenten-Liste komponenten ein nachdem this als parent dieser 
Komponente gesetzt wurde.
*/
void Werkstueck::add(Komponente *k) {
    if (k != nullptr) {
        k->setParent(this);
        komponenten.push_back(k);
        pathIsOptimized = false;
    }
}

/*
Die Methode remove(const IKomponente* k) l¨ oscht die Komponente, auf die der
ubergebene Zeiger ¨ k zeigt aus der Komponenten-Liste komponenten und setzt 
parent der Komponente zuruck auf ¨ nullptr.
*/
void Werkstueck::remove(const IKomponente * k) {   
    if (k != nullptr) {
        Iterator it = komponenten.begin();
        while (it != komponenten.end() && *it != k) {
            ++it;
        }
        if (*it != nullptr) {
            (*it)->setParent(nullptr);
        }
        komponenten.erase(it);
    }
}

/*
Die Methode getChild(int i) liefert einen Zeiger auf die Komponente, die unter
Index-Position i in der Komponenten-Liste gespeichert ist, zuruck. Wie ¨ ublich 
beginnt ¨die Index-Nummerierung bei 0.
*/
const IKomponente* Werkstueck::getChild(int i) const {
    Iterator it = komponenten.end();
    if(0 <= i && i < komponenten.size()) {
        it = komponenten.begin();
        for (int j = 0; j < i; ++j) {
            ++it;
        }
    }
    return *it;
}

/*
Die Methode calcPathLength() berechnet nur die reine Laenge des Weges, die der
Bohrkopf zurueck legt, um vom eigenen Verankerungspunkt die Koordinaten 
der Kinder anzufahren und dann wieder zu seinem Verankerungspunkt zurueck zu 
kehren. 
Z. B. wenn im Werkstuck ¨ w1 der obigen Abbildung die Kinder in der 
Reihenfolge b5, b6, f4, w2 abgespeichert sind, berechnet diese Methode die 
Laenge des Weges wie folgt:
In lokalen Koordinaten bzgl. des Werkstueckes ¨ w1
(0,0) -> (1, 2) -> (5, 1) -> (3,3) -> (6,3) -> (0,0)

In absoluten Koordinaten wird dieser Weg beschrieben durch
(6,10) -> (7, 12) -> (11, 11) -> (9,13) -> (12,13) -> (6,10)

und er hat die Laenge 18.89580.

Der zurueckgelegte Weg des Bohrkopfes fuer das Ausfraesen der Fraesung f4 und 
der zurueckgelegte Weg um die Kinder von ¨ w2 zu bearbeiten wird von dieser 
Methode also nicht beruecksichtigt, dies geschieht erst in der 
Methode ¨ calcTotalPath() (s.u.).

Tipp: Bei der Implementierung wird man die geerbte Methode distance() verwenden.
*/
double calcTotalPath() {

}

/*
Die Methode calcTotalPath() berechnet den total vom Bohrkopf zurueckgelegten ¨
Weg, um alle Komponenten des Werkstueckes zu bearbeiten. ¨
Hierfur wird man am Guenstigsten zunaechst fuer alle Kinder wiederum die Methode 
¨calcTotalPath() aufrufen und die Ergebnisse aufsummieren. Zu dieser Summe wird
man dann noch das Ergebnis der eigenen Methode calcPathLength() addieren.
*/
double calcTotalLength() {

}

/*
Die private Hilfsmethode getNearest(const IKomponente* pk) sucht unter den 
Elementen in der Komponenten-Liste das Element aus, welches den kleinsten 
euklidischen Abstand zur Komponente hat, auf die der 
Ubergabeparameter ¨ pk zeigt. Die Ruckgabe erfolgt in der Form eines 
Iterators, dessen ¨ curr Attribut auf das entsprechende 
IKomponentenElement zeigt. Man kann dabei davon ausgehen, dass das
IKomponente-Objekt, auf das pk zeigt, nicht selber in der 
Komponenten-Liste vorhanden ist, denn im Algorithums, der in der Methode 
optimizePath() implementiert ist
(s. u.), wird genau dieses Objekt vorher aus der Komponenten-Liste 
entfernt.
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
Frage: 
In welcher/welchen Methode(n) der Klasse Werkstueck ist das 
Attribut pathIsOptimized wieder auf false zu setzen?

Antwort: 
void add(Komponente *k);
*/