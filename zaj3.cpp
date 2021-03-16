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
