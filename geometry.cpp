#include "geometry.h"
#include <iostream>
#include <math.h>

using namespace std;

//#################################   C++    ###################################
//******************************************************************************

CNode::CNode() {
    x = 0;
    y = 0;
    z = 0;
    cout << " ####################### " << endl;
    cout << " Es wurde ein Objekt der Klasse CNode erstellt! " << endl;
}

CNode::CNode(float xtemp, float ytemp, float ztemp) {
    x = xtemp;
    y = ytemp;
    z = ztemp;
    cout << " ####################### " << endl;
    cout << " Es wurde ein Objekt der Klasse CNode erstellt! " << endl;
}

void CNode::ausgabe() const {
    cout << " Punkt mit den Koordinaten (x, y, z): " << x << ", " << y << ", " << z << endl;
}

float CNode::getX() const {
    return x;
}

float CNode::getY() const {
    return y;
}

float CNode::getZ() const {
    return z;
}


//#################################   C++    ###################################
//******************************************************************************

CLine::CLine() {
    e1 = nullptr;
    e2 = nullptr;
    cout << " ####################### " << endl;
    cout << " Es wurde ein Objekt der Klasse CLine erstellt! " << endl;
}

CLine::CLine(CNode* e1temp, CNode* e2temp) {
    e1 = e1temp; //e1temp und e1 sind Pointer
    e2 = e2temp;
    cout << " ####################### " << endl;
    cout << " Es wurde ein Objekt der Klasse CLine erstellt! " << endl;
}

void CLine::ausgabe() const {
    cout << " Endpunkte der Linie: " << endl;
    (*e1).ausgabe(); // elegantere Schreibweise: e1->ausgabe()
    (*e2).ausgabe(); // elegantere Schreibweise: e2->ausgabe()
}

void CLine::linenorm() const {
   double norm = sqrt((e1->getX() - e2->getX())* ((*e1).getX() - (*e2).getX()) + ((*e1).getY() - (*e2).getY()) * ((*e1).getY() - (*e2).getY()) + ((*e1).getZ() - (*e2).getZ()) * ((*e1).getZ() - (*e2).getZ()));
   cout << " Laenge der Linie ist: " <<norm<< endl;
}

void CLine::move() const {

}

void CLine::test_new_node_on_line_(CNode* test_node_) {
    CNode* temp_ = test_node_;
    float n_2_ = (((*test_node_).getZ()) - (*e1).getZ()) / ((*e1).getZ() - (*e2).getZ());
    float n_1_ = (((*test_node_).getX()) - (*e1).getX()) / ((*e1).getX() - (*e2).getX());
    float n_3_ = (((*test_node_).getY()) - (*e1).getY()) / ((*e1).getY() - (*e2).getY());

    if (n_3_ == n_1_ && n_2_ == n_1_) {
        if (n_2_ == n_3_) {
            cout << "Punkt liegt auf der Gerade!" << endl;
        }
        else
        {
            cout << "Punkt liegt nicht auf der Gerade!" << endl;
        }
    }
    else
    {
        cout << "Punkt liegt nicht auf der Gerade!" << endl;
    }
}


//CPLain
CPlain::CPlain() {
    p1 = nullptr;
    p2 = nullptr;
	p3 = nullptr;
    cout << " Es wurde ein Objekt der Klasse CPlain erstellt! " << endl;
}

CPlain::CPlain(CNode* e1temp, CNode* e2temp,CNode* e3temp) {
    p1 = e1temp;
    p2 = e2temp;
	p3 = e3temp;
    cout << " Es wurde ein Objekt der Klasse CPlain erstellt! " << endl;
}

CPlain::CPlain(CLine* l1temp, CNode* l2temp) {
	p1 = (*l1temp).get_first_point();
	p2 = (*l1temp).get_second_point();
	p3 = l2temp;
	cout << " Es wurde ein Objekt der Klasse CPlain erstellt! " << endl;
	cout << "Das ist der erste der drei Ebenenpunkten:" << endl;
	(*p1).ausgabe() ;
	cout << "Das ist der zweite der drei Ebenenpunkten:" << endl;
	(*p2).ausgabe() ;
	cout << "Das ist der dritte der drei Ebenenpunkten:" << endl;
	(*p3).ausgabe() ;
	}


//#################################   C++    ###################################
//******************************************************************************

void CGeometry::fAddNode(float x_, float y_, float z_) {
  CNode MyNode{x_,y_,z_};
  vNodeListe.push_back(MyNode);
  cout << " ####################### " << endl;
  cout << " Das Objekt wurde dem Array vNodeListe zugefügt" << endl;
}

void CGeometry::fAddNodeplusinformation(float x_, float y_, float z_,float information_) {
    CNode MyNode{x_,y_,z_};
    vNodeListe.push_back(MyNode);
    vNodeInformationListe.push_back(information_);
}








void CGeometry::fPrintNodeListe(){
    cout << " ####################### " << endl;
    cout << " Printing vNodeListe: " << endl;
    for (int j=0; j<vNodeListe.size(); j++){
        cout << " Node | ID: " << j << endl;
        vNodeListe[j].ausgabe();
    }
    //cout << " ####################### " << endl;
}

void CGeometry::fAddLine(int NodeID1_, int NodeID2_){
    CLine MyLine{&(vNodeListe[NodeID1_]),&(vNodeListe[NodeID2_])};
    vLineListe.push_back(MyLine);
    cout << " ####################### " << endl;
    cout << " Das Objekt wurde dem Array vLineListe zugefügt" << endl;
    //double *erg = &(v1[0]);
}

void CGeometry::fAddLineCoordinates(float x1_, float y1_, float z1_, float x2_, float y2_, float z2_){
    this->fAddNode(x1_, y1_, z1_); //hier wird ein Objekt CNode aus x1,y1,z1 erstellt und in vNodeListe gespeichert
    this->fAddNode(x2_, y2_, z2_); //hier wird ein Objekt CNode aus x2,y2,z2 erstellt und in vNodeListe gespeichert
    int j = vNodeListe.size(); // Größe von vNodeListe auslesen
    this->fAddLine(j-2,j-1); //aus letzten beiden Einträge in vNodeListe wird ein Objekt CLine erstellt
}

void CGeometry::fPrintLineListe(){
    cout << " ####################### " << endl;
    cout << " Printing vLineListe: " << endl;
    for (int j=0; j<vLineListe.size(); j++){
        cout << " Line | ID: " << j << endl;
        vLineListe[j].ausgabe();
    }
}




















