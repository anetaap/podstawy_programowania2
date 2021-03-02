//Proszę o napisanie funkcji doubleCopy przyjmującej tablice liczb (w postaci wskaźników od-do) i zwracającą kopię (alokacja przy pomocy new) tablicy z podwojonymi wartościami
//proszę pamiętać aby sprawdzić czy wskaźniki nie są nullptr

#include <iostream>
#include <string>
using namespace std;

void doubleCopy(int *a, int n){
    
    int * tablica2 = new int[n];
    for(int i=0;i<n;i++){
      tablica2[i]=*(a + i) *2;
    }
    cout <<"Tablica druga: " << endl; 
    for (int i=0; i<n; i++){
           cout << tablica2[i] << "";
    }
   delete [] tablica2;
}
int main()
{
    int tab[5] = {1,2,3,4,5};
    cout <<"Tablica pierwsza: " << endl; 
    for (int i=0; i<5; i++){
        cout << tab[i] << "";
    }
    cout << endl;
    doubleCopy(tab,5);
    
    return 0;
} 
 
