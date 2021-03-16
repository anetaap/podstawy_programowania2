//1. Proszę o napisanie kilku klas dziedziczących po sobie wg obrazka, ale przy każdym dziedziczeniu aby były pewne dodatkowe cechy....
#include <iostream>
#include <string>
using namespace std;

class CzlowiekZnanyZWidzenia
{
protected:
  string CechaCharakterystyczna;
public:
  void setCechaCharakterystyczna (string cecha)
  {
    CechaCharakterystyczna = cecha;
  }
  string getCechaCharakterystyczna ()
  {
    return this->CechaCharakterystyczna;
  }

};

class CzlowiekZnanyZImienia:public CzlowiekZnanyZWidzenia
{
protected:
  string imie;
public:
  void setImie (string name)
  {
    imie = name;
  }
  string getImie ()
  {
    return this->imie;
  }
};

class CzlowiekZnanyZInternetu
{
protected:
  string GdziePoznany;
  string CzymZwrocilMojaUwage;
public:
  void setGdziePoznany(string gdzie)
  {
      GdziePoznany=gdzie;
  }
  void setCzymZwrocilMojaUwage(string czym)
  {
      CzymZwrocilMojaUwage=czym;
  }
  string getGdziePoznany()
  {
      return this->GdziePoznany;
  }
  string getCzymZwrocilMojaUwage()
  {
      return this->CzymZwrocilMojaUwage;
  }
};

class Zwierze
{
protected:
  string Imie;
  string Gatunek;
public:
  void setImie(string imie)
  {
      Imie=imie;
  }
  void setGatunek(string gat)
  {
      Gatunek=gat;
  }
  string getImie()
  {
      return this->Imie;
  }
  string getGatunek()
  {
      return this->Gatunek;
  }
};

class DobrzeZnanyKolega:public CzlowiekZnanyZImienia, public CzlowiekZnanyZInternetu
{
protected:
  string SkadGoZnam;
  Zwierze ZwierzeDomowe;
public:
  static void powiadomienie()
  {
      cout<<"Dobrze znany kolega"<<endl;
  }
  void setSkadGoZnam(string skad)
  {
      SkadGoZnam=skad;
  }
 
  string getSkadGoZnam()
  {
      return this->SkadGoZnam;
  }
  string setZwierzeDomowe(Zwierze zwierz)
  {
      ZwierzeDomowe=zwierz;
  }
  Zwierze getZwierzeDomowe()
  {
      return this->ZwierzeDomowe;
  }
};

int main ()
{
  Zwierze Luna;
  Luna.setGatunek("Kundelek");
  Luna.setImie("Luna");
  
  DobrzeZnanyKolega Kinga;
  Kinga.setImie("Kinga");
  Kinga.setZwierzeDomowe(Luna);
  Kinga.setSkadGoZnam("Z Liceum");
  Kinga.setCzymZwrocilMojaUwage("Tym, że jest bardzo miła");
  Kinga.setCechaCharakterystyczna("Niski wzrost"); 
  return 0;
}



//2. Proszę o napisanie klasy tekst, opakowującej const char* o nazwie String, zawierający tekst, oraz aktualny rozmiar tekstu. Proszę zaimplementować:.....

#include <iostream>
#include <cstring>
using namespace std;

class Tekst
{
  char* string;
  size_t length;
public:
  Tekst()
  {
    string=new char[0];
    length=0;
  }
  Tekst(const char* string)
  {
    length=strlen(string);
    char* n= new char [length+1];
    strcpy(n, string);
  }
  Tekst(const Tekst &s) 
  {
    length=strlen(s.string);
    char *n=new char [length+1];
    strcpy(n, s.string);
  }
  ~Tekst() {delete string;}
  void setNewText(const char* newText)
  {
    length=strlen(newText);
    char *n=new char [length+1];
    strcpy(n, newText);
  }
  int getSize() const {return length;}
};


int main() {
  return 0;
}
