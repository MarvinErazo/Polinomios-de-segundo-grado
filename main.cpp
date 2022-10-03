#include <iostream>
#include <exception>
#include <math.h>
#include <iomanip>

using namespace std;

double validNumber(string coeficiente){

  double num;
  string numAux;
  bool isValid;

  do{
    cout << "Ingrese el valor de " + coeficiente + " : ";

    try{
      isValid = true;
      cin >> numAux;
      num = stof(numAux); //convierte el string a float

      if(coeficiente.compare("A") == 0 & num == 0){throw(num);} //En caso de que a = 0 devuelve un error

    } catch (...){
      cout << "Dato no valido\n";
      isValid = false;
    }

  }while(!isValid);

  return num;
}

int main() {
  double a,b,c,raiz1,raiz2, discriminante;

  cout << "FORMULA GENERAL \n";
  cout << "Ax^2 +- Bx + C\n";
  cout << "=================\n";

  a = validNumber("A");
  b = validNumber("B");
  c = validNumber("C");

  cout << "=================\n";

  discriminante = (b*b) - (4*a*c);

  if(discriminante < 0){
    cout << setprecision(2) << "Raiz 1 ==> (" << b*-1 << " - " << sqrt((discriminante*-1)) << "i) / " << 2*a <<"\n";
    cout << setprecision(2) << "Raiz 2 ==> (" << b*-1 << " + " << sqrt((discriminante*-1)) << "i) / " << 2*a <<"\n";
  }

  else if(discriminante == 0){
    cout << setprecision(2) << "Raiz ==> " << (b*-1)/(2*a);
  }

  else{ //discriminante > 0

    raiz1 = ((b*-1) - sqrt(discriminante))/(2*a);
    raiz2 = ((b*-1) + sqrt(discriminante))/(2*a);

    cout << setprecision(4) << "Raiz 1 ==> " << raiz1 << "\n";
    cout << setprecision(4) << "Raiz 2 ==> " << raiz2 << "\n";
  }

  return 0;
}
