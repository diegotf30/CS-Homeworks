/*
 * =====================================================================================
 *
 *    Description: Given 2 array sizes, it creates 2 arrays with random numbers, sorts
 *	  them using Insertion Sort, and then merges them.
 *
 *        Created:  20/01/2017
 *       Compiler:  gcc
 *
 *         Author:  Diego E. Treviño Ferrer A00819313
 *   Organization:  ITESM Campus Monterrey
 *
 * =====================================================================================
 */

#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

void fill( int W[], int iLW ) {
    for ( int iK = 0; iK < iLW; iK++ )
        W[iK] = rand() % 30 + 1;
}
void output( int W[], int iLW ) {
    for(int iK = 0; iK < iLW; iK++ )
        cout << W[iK] << " ";
    cout << endl;
}
void insertionSort (int iArr[], int iCantidad){
    for ( int iI = 1; iI < iCantidad; iI++ )
    {
        int iAux = iArr[iI];
        int iJ = iI - 1;
        while ( iJ >= 0 && iAux < iArr[iJ] )
        {
            iArr[iJ + 1] = iArr[iJ];
            iJ--;
        }
        iArr[iJ + 1] = iAux;
    }
}

void merge(int A[], int iLA, int B[], int iLB, int C[]) {
	if( iLA > iLB ){
        for( int i = 0; i < iLA; i++ ){
            C[i] = A[i];
        }
        int iLC = iLA;
        for( int j = 0; j < iLB; j++ ){
            C[iLC] = B[j];
            iLC++;
        }
	}
	else{
        for( int k = 0; k < iLB; k++ ){
            C[k] = B[k];
        }
        int iLC = iLB;
        for( int l = 0; l < iLA; l++ ){
            C[iLC] = A[l];
            iLC++;
        }
	}
}

int main() {
    //Init. seed to get random sequence in each execution
    srand( time(NULL) );
    //Creates arrays
    int iLA, iLB;
    cout << "How many elements in A? ";
    cin >> iLA;
    cout << "How many elements in B? ";
    cin >> iLB;
    int* A = new int[iLA];
    int* B = new int[iLB];
    int* C = new int[iLA + iLB + 5];

    //Fills arrays and sorts them.
    fill(A,iLA);
    insertionSort(A, iLA);
    output(A, iLA);

    fill(B, iLB);
    insertionSort(B, iLB);
    output(B, iLB);

    merge(A, iLA, B, iLB, C);
    //output(C, iLA+iLB);
    return 0;
}
