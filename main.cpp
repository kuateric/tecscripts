
#include "geometry.h"
#include <iostream>
#include <fstream>      // std::ifstream
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <locale.h>
#include <sstream>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

bool f_data_exist_(string data_name_){
 ifstream datei(data_name_);
 if(datei){
    cout << data_name_ << "\n";
  return true;
 }
 else{
  return false;
 }
}


int main() {

	cout << " ####################### " << endl;
	cout << " Programm wird gestartet " << endl;
	cout << " ####################### " << endl;

/*
	CNode n1{ 10,10,10 };
	n1.ausgabe();
	CNode n2{ 20,20,20 };
	CNode n3{ 50,40,10 };
	n2.ausgabe();
	CLine l1{ &n1,&n3 };
	l1.ausgabe();
	n1.getX();
	l1.linenorm();
	l1.test_new_node_on_line_(&n2);
*/

CGeometry myGeometry;
myGeometry.fAddNode(1,2,3);
myGeometry.fAddNode(4,5,6);
myGeometry.fPrintNodeListe();


//Es gibt mehrere Möglichkeiten, mit der wir eine Linie erstellen könnten

//Eine Möglichkeit über die Erstellung einer CLine über 2 Punktkoordinaten
myGeometry.fAddLineCoordinates(11, 22, 33, 44, 55, 66);
myGeometry.fPrintLineListe();
myGeometry.fAddLineCoordinates(111, 222, 333, 444, 555, 666);
myGeometry.fPrintLineListe();
myGeometry.fPrintNodeListe();


//Hier eine Möglichkeit, bei der ich vorher die Punkte, die zu einer Linie zusammengefügt werden über IDs definiere
//IDs könnten z.B. die Stellen im Array vNodeListe sein:
int NodeID1 = 0; // = vNodeListe[0]
int NodeID2 = 5; // = vNodeListe[5]
//Wie folgt wird dann aus den Nodes vNodeListe[0] und vNodeListe[5] ein CLine Objekt erstellt und in vLineListe gespeichert
myGeometry.fAddLine(NodeID1,NodeID2);
myGeometry.fPrintLineListe();



	//Datei erstellen
    ofstream ziel_;
    string dataname_ = "Ausgabedatei_.txt";
    ziel_.open(dataname_,ios::binary);
	ziel_ << ";" << "\n" ;
	ziel_ <<"Meine Kollegen sind die Besten!";
	ziel_ << ";" << "\n" ;
	ziel_.close();
    ziel_.clear();

	//Datei öffnen und einlesen
	if (f_data_exist_(dataname_)){
		ifstream quelle_;
		quelle_.open(dataname_);
		string zeile_;
		int anzahl_zeilen_ = 0;
		while (quelle_.good()){
			getline(quelle_,zeile_);
			anzahl_zeilen_ = anzahl_zeilen_ +1;
			}
		quelle_.close();
		quelle_.clear();
		quelle_.open(dataname_);
		getline(quelle_,zeile_);
		while (quelle_.good()){
            getline(quelle_,zeile_);
            string test_;
			for (int i8_=0; i8_ <= ((zeile_.length()));i8_++){
                cout << zeile_[i8_] << endl;
                test_ = zeile_[i8_];
                if (test_=="e"){
                    cout << "e!  gefunden" << endl;
                }
            }
        }
		quelle_.close();
    quelle_.clear();

	
    }














//Eine FLAC Datei einlesen
//Datei öffnen und einlesen
//Zuerst einmal nur Netzpunkte einlesen
	dataname_ = "FLACDATEI.FLAC3D";
	if ( f_data_exist_(dataname_)){
		ifstream source_;
		source_.open(dataname_);
		string line_;
		getline(source_,line_);
		while (source_.good()){
            getline(source_,line_);
            string test_;
			//if gridpoint first in line is G
			//example: G 11  -3.63112747000000e+02   3.82686537742510e-01  -3.70486271000000e+02
            test_ = line_[0];
			if (test_ == "G"){
				int number_of_spaces_= 0;
				int end_of_spaces_ = 0;
				int end1_ = 0;
				int end2_ = 0;
				int end3_ = 0;
                string xnummer_;
                string znummer_;
                string ynummer_;
                string nodenummer_;
                int i8_=0;
                while (i8_ <= line_.length() ){
                    test_ = line_[i8_];
					if (test_ == " "){
					    number_of_spaces_ = number_of_spaces_ +1;
                        end_of_spaces_ = i8_ - 1;
                        while (test_ == " "){
                            end_of_spaces_ = end_of_spaces_+1;
                            i8_ = i8_ +1;
                            test_ = line_[i8_];
                        }
                        i8_ = i8_ -1;


                        if (number_of_spaces_ == 1 ) {
							int i9_ = end_of_spaces_ +1;
							while(end1_ ==0){
                                test_ = line_[i9_];
								if (test_ != " "){
									nodenummer_ = nodenummer_ + line_[i9_];
								}
								else{
									end1_ = 1;
								}
								i9_ = i9_ +1;
								if (i9_ >line_.length()){end3_ = 1;}
							}
						}




                        if (number_of_spaces_ == 2 ) {
							int i9_ = end_of_spaces_ +1;
							while(end1_ ==0){
                                test_ = line_[i9_];
								if (test_ != " "){
									xnummer_ = xnummer_ + line_[i9_];
								}
								else{
									end1_ = 1;
								}
								i9_ = i9_ +1;
								if (i9_ >line_.length()){end3_ = 1;}
							}
						}
						if (number_of_spaces_ == 3 ) {
							int i9_ = end_of_spaces_ +1;
							while(end2_ ==0){
                                test_ = line_[i9_];
								if (test_ != " "){
									ynummer_ = ynummer_ + line_[i9_];
								}
								else{
									end2_ = 1;
								}
								i9_ = i9_ +1;
								if (i9_ >line_.length()){end3_ = 1;}
							}
                        }
						if (number_of_spaces_ == 4 ) {
							int i9_ = end_of_spaces_ +1;
							while(end3_ ==0){
                                test_ = line_[i9_];
								if (test_ != " "){
									znummer_ = znummer_ + line_[i9_];
								}
								else{
									end3_ = 1;
								}
								i9_ = i9_ +1;
								if (i9_ >line_.length()){end3_ = 1;}
							}
						}


					}
					i8_ = i8_ +1 ;
				}

				char c_x_[xnummer_.length() + 1];
                        double  x_ = atof(strcpy(c_x_, xnummer_.c_str()));
                        char c_y_[ynummer_.length() + 1];
                        double  y_ = atof(strcpy(c_y_, xnummer_.c_str()));
                        char c_z_[znummer_.length() + 1];
                        double  z_ = atof(strcpy(c_z_, znummer_.c_str()));

                        char n_n_[nodenummer_.length() + 1];
                        double  n_ = atof(strcpy(c_z_, nodenummer_.c_str()));

                        cout << "Node Nummer:" << n_ << endl;

						//myGeometry.fAddNode(x_,y_,z_);
						myGeometry.fAddNodeplusinformation(x_,y_,z_,n_);

            }
		}
		source_.close();
    source_.clear();
	}
    myGeometry.fPrintNodeListe();


	// test of git 
}
