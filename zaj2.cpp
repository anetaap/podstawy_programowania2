//1. Proszę o napisanie dwóch z klas: Kolo, Prostokat, Trojkat. 
//Każda z tych klas powinna mieć funkcje składowe liczące pole (area) i obwód (perimeter), oraz posiadać odpowiednie składowe.
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

int main(){
  Circle Kolo(3);
  cout<<"Pole koła wynosi: "<<Kolo.area()<<endl;
  cout<<"Obwód koła jest równy: "<<Kolo.perimeter()<<endl;

  Rectangle Rec(3,4);
  cout<<"Pole prostokąta jest równe: "<<Rec.area()<<endl;
  cout<<"Obwód prostokąta to: "<<Rec.perimeter()<<endl;
  return 0;
}
