#include "AnalizatorLeksykalny.h"
//-------------------------------------------------------------------------------------
vector <struct TablicaSymboli> AnalizatorLeksykalny::dodajDoTablicy(vector <struct TablicaSymboli> tab, struct Symbole obiekt, struct TablicaSymboli nowy)
{
	int doTablicy=0,czy_jest=0, numer;
	string sekcje[6] = {"SLOWO_KLUCZOWE","OP_ARYTMETYCZNY","OP_LOGICZNY","OP_BITOWY","OP_POMOCNICZY","KOMENTARZ" };
	for(int a=0;a<6;a++)
	{
		if(obiekt.rodzaj == sekcje[a])
		{
			doTablicy=1;
		}
	}
	if(doTablicy!=1)
	{
		for(int i=0;i< tab.size();i++)
		{
			
			if(obiekt.zwracany == tab[i].wartosc)
			{
				czy_jest=1;
			}
		}

		if(czy_jest == 0)
		{
			nowy.rodzaj=obiekt.rodzaj;
			nowy.wartosc=obiekt.zwracany;
			numer = tab.size()+1;
			nowy.lp= numer;
			tab.push_back(nowy);
		}
	}
	return tab;
}
//--------------------------------------------------------------------------------------
Symbole AnalizatorLeksykalny::daj_leksem(string kod,vector <struct Symbole> tab,vector <struct Wzorce> tab2,int *koniec,int* tablica)
{
	for(int d=0;d<tab2.size();d++)
	{
		tablica[d]=1;
	}

    int i,roz=0,flaga=0,czy_koniec=0,ujemna=0,czy_real=0,end=0;
    string bufor="",buftest="",znak="";
    Symbole pomoc;
	regex wzorzec2("-?[0-9]+");
	smatch wynik;
	for(i=(*koniec); i<(kod.length());i++)//kod[i] != '\0';i++)
    {
		end=0;
		while(kod[i] == ' ' || kod[i] == '\n')
        {
			i++;         
        }
        bufor+=kod[i];
		
		if(bufor =="\""){
			bufor="";
			i++;
			while(kod[i] != '\"'){
				bufor+=kod[i];
				i++;
			}
			pomoc.leksem="$";
			pomoc.rodzaj="NAPIS";
			pomoc.zwracany=bufor;
			bufor="";
			i++;
			*koniec=i;
			return pomoc;
		}
		for(int j=0;j<tab.size();j++)
		{
            if(bufor == tab[j].leksem && tab[j].rodzaj == "KOMENTARZ")
            {
                if(tab[j-1].rodzaj != "KOMENTARZ")
                {
                    bufor="";
                    while(kod[i]!='\n')
                    {
                        i++;
                    }
                }
                else
                {
                    flaga=0;
                    roz=tab[j].leksem.size();
                    bufor="";
                    buftest=tab[j+1].leksem;
                   
                    i++;
                    while(flaga == 0)
                    {
           
                        for(int a=0;a<roz;a++)
                        {
                            if(kod[i-a] != buftest[a])
                            {
                                break;
                            }
                            else
                            {
                                flaga=1;
                            }
                        }
                        i++;
                    }
                    i++;
                }
            }
			else if(bufor == tab[j].leksem && bufor!="")// && ujemna!=1)
            {            
               
				if( (i+1) < kod.length()){
					buftest=bufor+kod[i+1];
					znak=kod[i+1];
				    end=0;
					for(int a=0;a<tab2.size();a++){
						regex wzorzec(tab2[a].wzorzec);
				
						if( regex_search(bufor,wynik,wzorzec)==true && regex_search(znak,wynik,wzorzec)==true){
						     end=1;	
						}
					}
				
					if(end!=1){
					for(int k=0;k<tab.size();k++)
					{
						if(buftest == tab[k].leksem){
							i=i+2;
							*koniec=i;
							bufor="";
							buftest="";
							return tab[k];
						}
					}
					}
				}
				if(end!=1){
				i++;
				*koniec=i;
			    bufor="";
				return tab[j];
		
				}
			}
		}
		for(int a=0;a<tab2.size();a++){
			regex wzorzec(tab2[a].wzorzec);
		
			if( tablica[a]==1 && regex_search(bufor,wynik,wzorzec )){
				czy_koniec=0;
			
				if((i+1)<kod.length() && kod[i+1]!=' '){
					//cout<<"i="<<i<<endl;
					buftest=kod[i+1];
					if(kod[i+1] == '.') {czy_real=1;}
					if( regex_search(buftest,wynik,wzorzec )==false && kod[i+1]!='.' )
					{
						czy_koniec=1;
					}
				}
				else{
					czy_koniec=1;
				}

				if(czy_koniec == 1){	
					pomoc.leksem="$";
					if(czy_real == 1){
						pomoc.rodzaj="L_RZECZYWISTA";
						czy_real=0;
					}
					else{
						pomoc.rodzaj=tab2[a].leksem;
					}
					pomoc.zwracany=bufor;
					bufor="";
					i++;
					*koniec=i;
					return pomoc;
				}
			}
			else{
				tablica[a]=0;
			}
		}  
    }
    pomoc.leksem="";
    return pomoc;
}

vector <struct Wzorce> AnalizatorLeksykalny::zapisz1(string gdzie)
{
	fstream plik;
	vector < struct Wzorce> wzory;
	Wzorce w;
	int flaga=0,nr_sekcji=-1,i=0;
	string linia,leksem,wzorzec;
	plik.open(gdzie.c_str(), ios::in | ios::out);//plik.open("E:/conf.txt",ios::in | ios::out);
	
		if (plik.good() == true)
	{
		while (nr_sekcji<1)
		{
			plik >> leksem;
			if (leksem != "%%")
			{
				plik >> wzorzec;

			}
			else
			{
				getline(plik, linia);
				nr_sekcji++;
				continue;
			}
			w.leksem = leksem;
			w.wzorzec= wzorzec;
			wzory.push_back(w);
			i++;
		}

	}
	plik.close();	
	return wzory;
}
//-------------------------------------------------------------------------------------
vector <struct Symbole>  AnalizatorLeksykalny::zapisz2(string gdzie){
	fstream plik;

	vector < struct Symbole > dane;
	Symbole p;
	string sekcje[N] = {"---","SLOWO_KLUCZOWE","OP_ARYTMETYCZNY","OP_LOGICZNY","OP_BITOWY","OP_POMOCNICZY","KOMENTARZ" };
	int  i = 0, nr_sekcji = -1, q = 1;
	string zwracany,leksem, linia, test = "",lokalizacja="";
	plik.open(gdzie.c_str(), ios::in | ios::out);//plik.open("E:/conf.txt",ios::in | ios::out);
	if (plik.good() == true)
	{
		while (!plik.eof())
		{
			plik >> leksem;
			if (leksem != "%%")
			{
				plik >> zwracany;

			}
			else
			{
				getline(plik, linia);
				nr_sekcji++;
				continue;
			}
			if(nr_sekcji > 0){
				p.leksem = leksem;
				p.rodzaj = sekcje[nr_sekcji];
				p.zwracany = zwracany;
				dane.push_back(p);
			}
			i++;
		}

	}
	plik.close();

	return dane;
}
