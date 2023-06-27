#include <stdio.h>

/*
* QuickSort(A, p, r)
* if p < r
*	 then q <- Partition(A, p, r)    // Creates configuration, returns index of pivot
*	QuickSort(A, p, q-1)
*	QuickSort(A, q+1, r)
* 
* 
* Partition(A, p, r)
* x = A[r]
* i = p-1
* for j = p to r-1
*	 do if A[j] <= x
*		then i <- i+1
*			swap(A[i], A[j])
* swap([A[i+1], A[r]])
* return i+1
*
* Pro p < r provede Quicksprt (A, p, r) setrideni casti A [p...r]
* Tedy QuickSrt( A, 0, n-1) setridi cele pole A[0...n-1]
*
* Pritom Partition(A, p, r) provede vyse opsane premisteni prvku pole A a vrati index q pivota
*/

