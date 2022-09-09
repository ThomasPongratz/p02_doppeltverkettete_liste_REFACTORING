#include <iostream>
#include <cmath>
#include "bohrung.h"
#include "fraesung.h"
#include "werkstueck.h"
#include "komponente.h"
#include "delist.h"

using std::cout;
using std::endl;

int main(){
    Bohrung b1{1, 2, 8}, b2{2, 6, 4}, b3{10, 8, 7}, b4{7, 2, 5};
    Bohrung b5{1, 2, 6}, b6{5, 1, 8};
    Bohrung b7{5, 2.5, 8}, b8{6, 0.5, 6};
    Fraesung f1{2, 3, 5, 2*sqrt(2), 45*M_PI/180}, f2{6, 7, 6, 3, 0}, f3{17, 6, 4, 4*sqrt(2), 225*M_PI/180};
    Fraesung f4{3, 3, 3, sqrt(5), (atan(2) + 90) * M_PI/180};
    Fraesung f5{1, 2, 4, sqrt(2),  315*M_PI/180};
    Werkstueck w0{0, 0, 18, 25}, w1{6, 10, 7, 18}, w2{6, 3, 3, 10};

    w0.add(&b1);
    w0.add(&b2);
    w0.add(&b3);
    w0.add(&b4);
    w0.add(&f1);
    w0.add(&f2);
    w0.add(&f3);
    w0.add(&w1);

    w1.add(&b5);
    w1.add(&b6);
    w1.add(&f4);
    w1.add(&w2);

    w2.add(&b7);
    w2.add(&b8);
    w2.add(&f5);

    DeList list;
    list.push_back(&w0);
    list.push_back(&w1);
    list.push_back(&w2);
/*
    cout << list.size() << endl;
    cout << "Ausgabe der Liste" << endl;
    for (int i = 0; i < list.size(); ++i) {
        list.at(i)->output(cout);
        cout << endl;
    }
*/
    return 0;
}