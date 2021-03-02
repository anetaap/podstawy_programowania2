//Proszę o napisanie funkcji doubleCopy przyjmującej tablice liczb (w postaci wskaźników od-do) i zwracającą kopię (alokacja przy pomocy new) tablicy z podwojonymi wartościami
//proszę pamiętać aby sprawdzić czy wskaźniki nie są null

#include <iostream>
#include <string>
using namespace std;

void doubleCopy(int *a, int n){
    
    int * tablica2 = new int[n];
    for(int i=0;i<n;i++){
      tablica2[i]=*(a + i) *2;
    }
    for (int i=0; i<n; i++){
           cout << tablica2[i] << " ";
    }
   delete [] tablica2;
}
int main()
{
    int tab[5] = {1,2,3,4,5}; 
    int *ptab;
    doubleCopy(tab,5);
    
    return 0;
} 
