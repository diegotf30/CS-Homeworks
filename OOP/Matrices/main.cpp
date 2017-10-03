///Author: Diego Treviño Ferrer A00819313
///Date: Agosto 2016
///Basic arithmetic operations between square Matrices A y B:

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Dimensions of the square Matrix
const int iN = 4;

int iMatA[iN][iN] = {1, 2, 3, 4,
					 1, 2, 3, 4,
					 1, 2, 3, 4,
					 1, 2, 3, 4};

int iMatB[iN][iN] = {1, 2, 3, 4,
					 1, 2, 3, 4,
					 1, 2, 3, 4,
					 1, 2, 3, 4};

//Support Variable
int iMatC[iN][iN];


//The first dimension of the matrix isn't necessary
void imprimeMatriz(const int iMatrix[][iN]) {
   for(int i=0; i<iN; i++)
    {
        cout << "|  " ;

        for(int j=0; j<iN; j++)
        {
            cout << iMatrix[i][j] << "  ";
        }

        cout << "|" << endl;
   }

   cout << "\n";
}

int main() {
    cout << "Matrix iA:" << endl;
    imprimeMatriz(iMatA);

    cout << "Matrix iB:" << endl;
    imprimeMatriz(iMatB);

   ///Sum.
   for(int i=0; i<iN; i++)
   {
       for(int j=0; j<iN; j++)
       {
           iMatC[i][j] = iMatA[i][j] + iMatB[i][j];
       }
   }
   cout << "Sum:" << endl;
   imprimeMatriz(iMatC);

   ///Subtraction
   for(int i=0; i<iN; i++)
   {
       for(int j=0; j<iN; j++)
       {
           iMatC[i][j] = iMatB[i][j] - iMatA[i][j];
       }
   }
   cout << "iB - iA:" << endl;
   imprimeMatriz(iMatC);

   ///Transposition.
   for(int i=0; i<iN; i++)
   {
       for(int j=0; j<iN; j++)
       {
           iMatC[i][j] = iMatA[j][i];
       }
   }
   cout << "Transposition of matrix iA:" << endl;
   imprimeMatriz(iMatC);

   ///Multiplication
   for(int i=0; i<iN; i++)
   {
       for(int j=0; j<iN; j++)
       {
           //Acumulador.
           iMatC[i][j] = 0;
           for(int k=0; k<iN; k++)
           {
               iMatC[i][j]+=iMatA[i][k] * iMatB[k][j];
           }
       }
   }
   cout << "Multiplication of matrices iA x iB:" << endl;
   imprimeMatriz(iMatC);

   return 0;
}
