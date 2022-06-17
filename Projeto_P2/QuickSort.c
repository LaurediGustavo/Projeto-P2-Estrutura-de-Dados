#include <stdio.h>
#include <stdlib.h>
#include "QuickSort.h"

void quicksort(funcionario *funcionario, int e, int d){
    int i;
    if(d > e){
        i = particao(funcionario, e, d);
        quicksort(funcionario, e, i - 1);
        quicksort(funcionario, i + 1, d);
    }
}

int particao(funcionario *func, int e, int d){
    funcionario v, t;
    int i, j;
    v = func[d];
    i = e - 1;
    j = d;

    do{
        do{
            i = i + 1;
	    }
	    while ((func[i].id) < ( v.id));

        do{
            j = j - 1;
	    }
	    while ((func[j].id) > (v.id));

        t = func[i];
        func[i] = func[j];
        func[j] = t;
    }
    while (j > i);

	func[j] = func[i];
	func[i] = func[d];
	func[d] = t;
	return i;
}
