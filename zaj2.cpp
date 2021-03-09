//1. Proszę o napisanie dwóch z klas: Kolo, Prostokat, Trojkat. 
//Każda z tych klas powinna mieć funkcje składowe liczące pole (area) i obwód (perimeter), oraz posiadać odpowiednie składowe.
//2.Proszę aby dostęp bezpośredni do składowych niefunkcyjnych był prywatny, a do ustawiania wszystkiego proszę użyć setterów,
//proszę też o zrobienie co najmniej jednego gettera działającego dla obiektów stałych.
#include <iostream>
#include <string>
using namespace std;

class Circle
{  
private :
    int radius;
public :
    Circle(int r){ radius=r; }
    void setRadius(int r){ radius=r; }
    double area() const{return 3.14*radius*radius;}
    double perimeter() const{return 3.14*2*radius;}
};

class Rectangle
{  
private :
    int side1,side2;
public :
    Rectangle(int a,int b){ 
      side1=a;
      side2=b;
      }
    void setSides(int a, int b){ 
      side1=a;
      side2=b;
      }
    double area() const{return side1*side2;}
    double perimeter() const{return 2*side1+2*side2;}
};

//3. Proszę o zrobienie gadających (wypisujących na cout) konstruktorów dla zadanych klas
class Rectangle2
{
private :
    int side1, side2;
public:
    Rectangle2(int a){
      side1=a;
      cout<<"Kwadrat\n";
    }
    Rectangle2(int a, int b){
      side1=a;
      side2=b;
      cout<<"Prostokąt\n";
    }
};

class Triangle
{
private:
    int side1,side2,side3;
public:
    Triangle(int a){ 
      side1=a;
      cout<<"Trójąkt równoboczny\n"; 
        }
    Triangle(int a, int b, int c){
       side1=a;
       side2=b;
       side3=c;
       cout<<"Trójąt różnoboczny\n";   
    }
};

class Circle2
{
private:
    int radius;
public:
    Circle2(int r=3){
      radius=r;
      cout<<"Koło\n";
    }
};


int main(){
  Circle Kolo(3);
  cout<<"Pole koła wynosi: "<<Kolo.area()<<endl;
  cout<<"Obwód koła jest równy: "<<Kolo.perimeter()<<endl;

  Rectangle Rec(3,4);
  cout<<"Pole prostokąta jest równe: "<<Rec.area()<<endl;
  cout<<"Obwód prostokąta to: "<<Rec.perimeter()<<endl;
  Rectangle2 Rec2(3,4);
  Triangle troj(3);
  Triangle troj2(2,4,5);
  Circle2 sth;
  return 0;
}
