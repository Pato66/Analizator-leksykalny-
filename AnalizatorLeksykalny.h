#include<iostream>
#include<string>
#include <cstdlib>
#include<cstring>
#include<fstream>
#include<vector>
#include<regex>
using namespace std;
const int N=7;
const int S=35;
const int LICZBA=6;
const int ID=20;
//-------------------------------------------------------------------------------------
typedef struct TablicaSymboli
{
	int lp;
	string rodzaj;
	string wartosc;
}TablicaSymboli;
//-------------------------------------------------------------------------------------

typedef struct Symbole
{
       string leksem;
       string rodzaj;
       string zwracany;
}Symbole;
//-------------------------------------------------------------------------------------
typedef struct Wzorce
{
	string leksem;
	string wzorzec;
}Wzorce;
//-------------------------------------------------------------------------------------

public class AnalizatorLeksykalny
{
public:
    vector < struct Symbole > tabSym;
    vector < struct Wzorce > tabWzo;
	vector < struct TablicaSymboli> dlaParsera;

public:
	Symbole daj_leksem(string kod,vector <struct Symbole> tab,vector <struct Wzorce> tab2,int *koniec,int* tablica);
	vector <struct TablicaSymboli> dodajDoTablicy(vector <struct TablicaSymboli> tab, struct Symbole obiekt, struct TablicaSymboli nowy);
	vector <struct Wzorce> zapisz1(string gdzie);
	vector <struct Symbole> zapisz2(string gdzie);
	AnalizatorLeksykalny(){};
};

