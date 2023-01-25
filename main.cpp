/*---------------------------------------------------
 * Dato de entrada:  filas, col (unsigned int)
 * Dato de Salida : matriz con valores aleatorios
 *                  el mayor
 ---------------------------------------------------*/

#include <iostream>
#include <iomanip>
using namespace std;

void llenarMatriz(int * *pMatriz, unsigned int filas, unsigned col);
void imprimirMatriz( int ** pMat, unsigned int filas, unsigned int col);
int hallaMayor(int **mat, unsigned int filas, unsigned int col);


int main()
{
  unsigned int filas, col;

  srand(time(nullptr));
  cout << "Filas : ";
  cin >> filas;
  cout << "Columnas: ";
  cin >> col;

   int  * * pMat=nullptr;
   pMat = new int*[filas];
   for(int f=0; f<filas; f++)
     pMat[f] = new int[col];
   //--- ahora llenamos la matriz con valores aleatorios
   llenarMatriz(pMat, filas, col);
   imprimirMatriz(pMat, filas, col);
   cout << "El mayor dato de la matriz es : " << hallaMayor(pMat, filas, col) << "\n";
   //--- liberamos la memoria
   for(int f=0; f<filas; f++)
     delete [] pMat[f];
   delete []pMat;
   pMat = nullptr;
  return 0;
}


int hallaMayor(int **mat, unsigned int filas, unsigned int col)
{
  int mayor=mat[0][0];
  for(int f=0; f<filas; f++)
    for (int c = 0; c < col; c++)
      if(mat[f][c]>mayor)
        mayor = mat[f][c];

  return mayor;
}


void imprimirMatriz( int ** pMat, unsigned int filas, unsigned int col)
{
  for(int f=0; f<filas; f++) {
    for (int c = 0; c < col; c++)
      cout << setw(5) << pMat[f][c];
    cout << "\n";
  }
}


void llenarMatriz(int * *pMatriz, unsigned int filas, unsigned col)
{
  for(int f=0; f<filas; f++)
    for(int c=0; c<col; c++)
      pMatriz[f][c]= rand() %100;

}