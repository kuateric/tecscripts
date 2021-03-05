#ifndef GEOMETRY_H
#define GEOMETRY_H


//#include "geometry.h"
//#include <iostream>
//#include <fstream>      // std::ifstream
//#include "geometry.h"
//#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

//#################################   C++    ###################################
//******************************************************************************

class CNode {

private:

    float x;
    float y;
    float z;

public:

    //Konstruktur
    CNode();
    //
    CNode(float xtemp, float ytemp, float ztemp);

    //Ausgabe der Koordinaten des Punktes in Kommandozeile
    void ausgabe() const;

    //Getter Methode f�r x
    float getX() const;

    //Getter Methode f�r y
    float getY() const;

    //Getter Methode f�r z
    float getZ() const;


};


//#################################   C++    ###################################
//******************************************************************************

class CLine {

private:

    CNode* e1;
    CNode* e2;

public:

    //Standardkonstruktur
    CLine();

    //Konstruktur
    CLine(CNode* e1temp, CNode* e2temp);

    ////Ausgabe der Koordinaten der Punkte der Linie in der Kommandozeile
    void ausgabe() const;

    ////Berechne die Laenge der Linie
    void linenorm() const;

    ////verschiebe einen Punkt der Linie
    void move() const;
    void test_new_node_on_line_(CNode* test_node_);


    //Ausgabe erster und zweiter Datenpunkt
	CNode* get_first_point(){
		return e1;
	}
	CNode* get_second_point(){
		return e2;
	}
};




class CPlain {
	private:
		CNode* p1;
		CNode* p2;
		CNode* p3;

	public:
	    //Standardkonstruktur
		CPlain();

		//Konstruktur
		CPlain(CNode* e1temp, CNode* e2temp,CNode* e3temp);
		CPlain(CLine* l1temp, CNode* l2temp);
};



//#################################   C++    ###################################
//******************************************************************************

class CGeometry {

    private:
    std::vector<float>vNodeInformationListe;
    std::vector<CNode> vNodeListe;
    std::vector<CLine> vLineListe;

    public:
    //Erstellen eines Nodes
    void fAddNode(float x_, float y_, float z_);
    void fAddNodeplusinformation(float x_, float y_, float z_,float information_);


    //Konsolenausgabe der NodeListe
    void fPrintNodeListe();
    //Erstellung Objekt CLine über IDs
    void fAddLine(int NodeID1_, int NodeID2_);
    //Erstellung Objekt CLine über Punktkoordinaten
    void fAddLineCoordinates(float x1_, float y1_, float z1_, float x2_, float y2_, float z2_);
    //Konsolenausgabe der LineListe
    void fPrintLineListe();
};


#endif

