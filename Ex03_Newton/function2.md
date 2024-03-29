### funkcja findSurface
####  int findSurface(FuncPointer f, double* x, unsigned k1, unsigned k2, double h1, double h2);
Funkcja ta ma obliczyć i wydrukować na ekran wybrane punkty x1,x2,...,xk1*k2 spełniające równanie f(xi)=0 z dokładnością |f(xi)|≤10-14. Argumentami tej funkcji są
* f - wskaźnik do funkcji R3 -> R
* x - tablica liczb double długości 3, zawierająca punkt początkowy bliski miejsca zerowego funkcji (czyli f(x)≈0)
* k1,k2 - określają liczby punktów do wyznaczenia
* h1,h2 - kroki zmiany parametrów. Przy ustalonej wartości ostatnich dwóch zmiennych b,c jest to funkcja jednej zmiennej fb,c:R ->R, której miejsca zerowe możemy wyliczyć na przykład za pomocą metody Newtona.<br>
Państwa zadaniem jest obliczenie i wydrukowanie na ekran miejsc zerowych fb,c oraz wartości b,c dla (b,c) równych (w podanej kolejności)<br>
 ```
  (x[2]+h1,x[3]+h2)
  (x[2]+h1,x[3]+2*h2)
  ...
  (x[2]+h1,x[3]+k2*h2)
  
  (x[2]+2*h1,x[3]+h2)
  (x[2]+2*h1,x[3]+2*h2)
  ...
  (x[2]+2*h1,x[3]+k2*h2)

  ...
  
  (x[2]+k1*h1,x[3]+h2)
  (x[2]+k1*h1,x[3]+2*h2)
   ...
  (x[2]+k1*h1,x[3]+k2*h2)
```  
Dodatkowo, dla większej czytelności wyjścia, po każdym zestawie punktów z ustaloną wartością b wstawiamy wolną linię.<br>
**Zwracana wartość**: <br>
jeśli dla pewnego i=1,...,k1, j=1,...,k2 nie uda się wyznaczyć zera funkcji dla parametrów b=x[1]+i*h1, c=x[2]+j*h2 z tolerancją absolutną 10-14, to należy zakończyć działanie funkcji bez wypisywania błędnego miejsca zerowego i zwrócić wartość i*k1+j. W przeciwnym przypadku zwracamy wartość 0 oznaczającą brak błędu.

**Test jawny:**
```c++
  #include "source.cpp"

  void implicitSurface(const double* x, double* y, double* Df){
    // funkcja dana jest wzorem f(a,b,c) = (a+b+c)/(a^2+b^2+c^2)-1
    // zmienne pomocnicze
    const double n = x[0]*x[0] + x[1]*x[1] + x[2]*x[2];
    const double s = x[0] + x[1] + x[2];
    
    // obliczam wartosc funkcji
    *y = s/n - 1.;
    
    //obliczam pierwszy i jedyny wiersz macierzy
    const double r = 1./n;
    const double r2 = 2.*(*y)*r;
    Df[0] = r - x[0]*r2;
    Df[1] = r - x[1]*r2;
    Df[2] = r - x[2]*r2;
  }

  int main(){
    double x[3] = {0.25*(1.+sqrt(5.)),0.25*(1.-sqrt(5.)),0.5};
    findSurface(implicitSurface,x,4,4,1./32,1./32);
    return 0;
  }

/**
spodziewane wyjscie:
0.12039238685063169 -0.27776699437494745 0.53125000000000000 
0.12427103856508417 -0.27776699437494745 0.56250000000000000 
0.13082600313543147 -0.27776699437494745 0.59375000000000000 
0.14020352633612365 -0.27776699437494745 0.62500000000000000 

0.06212351672030310 -0.24651699437494745 0.53125000000000000 
0.06548172983245609 -0.24651699437494745 0.56250000000000000 
0.07113718439412973 -0.24651699437494745 0.59375000000000000 
0.07918248954042481 -0.24651699437494745 0.62500000000000000 

0.01274589354441671 -0.21526699437494745 0.53125000000000000 
0.01576154969082753 -0.21526699437494745 0.56250000000000000 
0.02082981701922552 -0.21526699437494745 0.59375000000000000 
0.02801681517470467 -0.21526699437494745 0.62500000000000000 

-0.03023031684944523 -0.18401699437494745 0.53125000000000000 
-0.02746042638880794 -0.18401699437494745 0.56250000000000000 
-0.02281133203696253 -0.18401699437494745 0.59375000000000000 
-0.01623226497988585 -0.18401699437494745 0.62500000000000000  
*/
```
