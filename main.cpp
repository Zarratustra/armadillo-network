#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
  {

  cout << "No a teraz drogie dzieci" << "\n" ;
  cout << "Trzeba dane łapać w sieci." << "\n";
  cout << "Zmalujemy coś w gnuplocie" << "\n";
  cout << "Wywiesimy to na płocie." << "\n";


  mat A = randu<mat>(4,5);
  mat B = randu<mat>(4,5);

  cout << A*B.t() << endl;

  return 0;
  }