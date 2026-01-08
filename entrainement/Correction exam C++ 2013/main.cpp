//
//  main.cpp
//  exam2013
//
//  Created by Jean-Marc Perronne on 19/03/13.
//  Copyright (c) 2013 Jean-Marc Perronne. All rights reserved.
//

#include <iostream>
#include "Complex.h"
#include "Line.h"
#include "Path.h"
#include "Value.h"

using namespace std;

/*
 Ecrire la classe Complex
 Cette classe modélise un nombre complexe possédant deux données membres de type double nommées: re et im;
 La fonction double sqrt(double) est supposée exister.
 racine carrée.
 Le constructeur par défaut est interdit.
 */

void complex()
{
    cout << endl << "complex" << endl;
    Complex c1(10,20);
	Complex c2(2,2);
	Complex c3=100;
	c3.printOn(cout<<endl);
	(c1+c2).printOn(cout << endl);
	cout << endl << c2.module();
}
#ifndef complex_h 
#define compex_h 
#include <iostream>




/*
 Ecrire les classes Geometric et Line
 La classe Geometric:
 elle est abstraite,
 elle définit le comportement virtuel pure move (déplacement relatif) prenant en paramètre deux entiers;
 La classe Line
 elle est une sorte de  Geometric et modélise une ligne possédant deux données membres de type Point nommées: start et end;
 La classe Point est supposée exister,  elle hérite de la classe Geometric.
 un point sait fournir sa représentation texxtuelle.  -> ostream& printOn(ostream&) const
 */

void line()
{
    cout << endl << endl << "line" << endl;
    Line l1;
	Line l2(Point(), Point(10, 50));
	l1.printOn(cout << endl <<"l1: ");
	l2.printOn( cout << endl <<"l2: ");
	l2.move(5,10);
	l2.printOn(cout << endl <<"l2: ");
	l2.getStart().printOn(cout << endl << "l2 start: ");
	l2.getEnd().printOn(cout << endl << "l2 end: ");
}

/*
 Ecrire la classe Path
 La classe Path:
 définit un chemin composé d'une collection de points.
 elle possède une donnée membre de type vector<Point*> appelée path.
 Les points de la collection sont créés dynamiquement en interne, ce qui suppose que leur durée de vie doit être prise en compte.
 La classe Point est supposée exister
 un point sait se construire à partir de deux entiers. -> Point(int, int)
 un point sait effectuer une translation.-> void move(int,int)
 un point sait fournir sa représentation textuelle.  -> ostream& printOn(ostream&) const
 */

void path()
{
    cout << endl << endl << "path" << endl;
    Path path;
    path.addPoint(10,0);
    path.addPoint(20, 0);
    path.addPoint(30,0);
    cout << endl << "path size: " << path.size();
    path.printOn(cout << endl);
    path.move(0,10);
    path.printOn(cout << endl);
}

/*
 Ecrire la classe générique Value
 La classe Value:
 elle est générique,
 elle possède une donnée membre de type T appelée value.
 Ecrire l'opérateur global / permettant la division entre Value<T> et fournissant en résultat un Value<T>
 On considèrera que pour son usage particulier le type T supporte l'opérateur /.
 */

void value()
{
    cout << endl << endl <<  "value" << endl;
    Value<int> vint1(9), vint2(2), vint4(0);
    Value<string> vstring("hello");
    try{
        cout << endl << "value of vint1: "<<vint1.getValue();
        vint1.setValue(10);
        vint1.printOn(cout << endl);
        vstring.printOn(cout << endl);
        (vint1/vint2).printOn(cout << endl);
        (vint1/vint4).printOn(cout << endl);
    }
    catch(const char* ex){
        cout << endl << ex;
    }
}

int main(int argc, const char * argv[])
{

    //complex();
    //line();
    path();
    //value();
    return 0;
}

