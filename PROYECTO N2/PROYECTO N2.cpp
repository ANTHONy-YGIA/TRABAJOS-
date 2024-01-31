
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

void imprimirLista(const std::vector<int>& lista) {

    for (int num : lista) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
}

std::pair<std::vector<int>, int> bubbleSort(std::vector<int> numeros) {

    int ciclos = 0,aux=0;
    bool ordenado = false;
    for (int i = 0; i < 5 && ordenado== false; i++)
    {
		ordenado = true;
        for (int j = 0; j < 4; j++)
        {
            if (numeros[j]>numeros[j+1])
            {
                ordenado=false;
                aux=numeros[j];
                numeros[j]=numeros[j+1];
                numeros[j+1]=aux;
            }
            ciclos++;
        }
    }
     return std::make_pair(numeros, ciclos);
}

std::pair<std::vector<int>, int> insertionSort(std::vector<int> numero) {

    int pos=0,aux=0,ciclos=0;
    for (int i = 0; i < 5; i++)
    {
        for (int i = 0; i < 5; i++)
        {
        pos=i;
        aux=numero[i];
        while (pos>0 && numero[pos-1]>aux)
            {
            numero[pos]=numero[pos-1];
            pos--;
            ciclos++;
            }
        numero[pos]=aux;
        }
    }
    return std::make_pair(numero, ciclos);
}

std::pair<std::vector<int>, int> selectionSort(std::vector<int> numeros) {

    int min,aux=0,ciclos=0;
    for (int i = 0; i < 5; i++)
    {
        min=i;
        for (int j = i+1; j < 5; j++)
        {
            if (numeros[j]<numeros[min])
            {
                min=j;
            }
            ciclos++;
        }
        aux=numeros[i];
        numeros[i]=numeros[min];
        numeros[min]=aux;
    }
    return std::make_pair(numeros, ciclos);
}
std::pair<std::vector<int>, int> countingSort(std::vector<int> numeros) {
    int operaciones = 0;
    int n = numeros.size();

    int maxElement = *std::max_element(numeros.begin(), numeros.end());
    int minElement = *std::min_element(numeros.begin(), numeros.end());

    int range = maxElement - minElement + 1;

    std::vector<int> count(range, 0);
    std::vector<int> output(n);

    for (int i = 0; i < n; ++i) {
        count[numeros[i] - minElement]++;
        ++operaciones;
    }

    for (int i = 1; i < range; ++i) {
        count[i] += count[i - 1];
        ++operaciones;
    }

    for (int i = n - 1; i >= 0; --i) {
        output[count[numeros[i] - minElement] - 1] = numeros[i];
        count[numeros[i] - minElement]--;
        ++operaciones;
    }

    for (int i = 0; i < n; ++i) {
        numeros[i] = output[i];
    }

    return std::make_pair(numeros, operaciones);
}

int particion(std::vector<int>& numeros, int bajo, int alto, int& operaciones) {
    int pivote = numeros[alto];
    int i = bajo - 1;

    for (int j = bajo; j <= alto - 1; ++j) {
        if (numeros[j] <= pivote) {
            ++i;
            std::swap(numeros[i], numeros[j]);
            ++operaciones;
        }
    }

    std::swap(numeros[i + 1], numeros[alto]);
    ++operaciones;
    return i + 1;
}

void quickSort(std::vector<int>& numeros, int bajo, int alto, int& operaciones) {
    if (bajo < alto) {
        int pivote = particion(numeros, bajo, alto, operaciones);
        quickSort(numeros, bajo, pivote - 1, operaciones);
        quickSort(numeros, pivote + 1, alto, operaciones);
    }
}

void merge(std::vector<int>& numeros, int izquierda, int medio, int derecha, int& operaciones) {
    int n1 = medio - izquierda + 1;
    int n2 = derecha - medio;

    std::vector<int> izquierdaArray(n1);
    std::vector<int> derechaArray(n2);

    for (int i = 0; i < n1; i++) {
        izquierdaArray[i] = numeros[izquierda + i];
    }

    for (int j = 0; j < n2; j++) {
        derechaArray[j] = numeros[medio + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = izquierda;

    while (i < n1 && j < n2) {
        if (izquierdaArray[i] <= derechaArray[j]) {
            numeros[k] = izquierdaArray[i];
            i++;
        } else {
            numeros[k] = derechaArray[j];
            j++;
        }
        k++;
        operaciones++;
    }

    while (i < n1) {
        numeros[k] = izquierdaArray[i];
        i++;
        k++;
        operaciones++;
    }

    while (j < n2) {
        numeros[k] = derechaArray[j];
        j++;
        k++;
        operaciones++;
    }
}

void mergeSort(std::vector<int>& numeros, int izquierda, int derecha, int& operaciones) {
    if (izquierda < derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        mergeSort(numeros, izquierda, medio, operaciones);
        mergeSort(numeros, medio + 1, derecha, operaciones);

        merge(numeros, izquierda, medio, derecha, operaciones);
    }
}

std::pair<std::vector<int>, int> mergeSortWrapper(std::vector<int> numeros) {
    int operaciones = 0;
    int n = numeros.size();

    mergeSort(numeros, 0, n - 1, operaciones);

    return std::make_pair(numeros, operaciones);
}
int main() {

    std::srand(std::time(0));
    int n;
    std::cout << "Ingrese la longitud de elementos : ";
    std::cin >> n;

    std::vector<int> numerosAleatorios;

    for (int i = 0; i < n; ++i) {
        int numeroAleatorio = std::rand() % 100;
        numerosAleatorios.push_back(numeroAleatorio);
    }
    std::cout<<"Los numeros aleatorios son los siguientes:"<<std::endl;
    imprimirLista(numerosAleatorios);

    /*iniciaremos con metodo de ordenamietnoo burbuja*/
    std::pair<std::vector<int>, int> resbubbleSort= bubbleSort(numerosAleatorios);

    std::cout<<"\nORDENAMIENTO POR BUBBLE SORT: "<<std::endl;

    imprimirLista(resbubbleSort.first);

    std::cout << "\nLa cantidad de intercambios fue : " << resbubbleSort.second << std::endl;

    /*metodo de ordenamiento por insercion*/

    std::pair<std::vector<int>, int> resInsertionSort = insertionSort(numerosAleatorios);

    std::cout<<"\nORDENAMIENTO POR INSERTION SORT: "<<std::endl;
    imprimirLista(resInsertionSort.first);
    std::cout<< "\nLa cantidad de intercambios fue : " << resInsertionSort.second << std::endl;

    /*metodo de ordenamiento por seleccion*/

    std::pair<std::vector<int>, int> resSelectionSort = selectionSort(numerosAleatorios);
    std::cout<<"\nORDENAMIENTO POR SELECTION SORT: "<<std::endl;
    imprimirLista(resSelectionSort.first);
    std::cout<< "\nLa cantidad de intercambios fue : " << resSelectionSort.second << std::endl;

    /*ahora por metodo couting sort*/
    std::pair<std::vector<int>, int> resCountingSort = countingSort(numerosAleatorios);
    std::cout<<"\nORDENAMIENTO POR COUNTING SORT: "<<std::endl;
    imprimirLista(resCountingSort.first);
    std::cout<< "\nLa cantidad de intercambios fue : " << resCountingSort.second << std::endl;

    /*ahora por metodo de quick sort, ya tengo sueño pipipipi*/
    int operaciones = 0;
    quickSort(numerosAleatorios, 0, n - 1, operaciones);

    std::cout << "\nORDENAMIENTO POR QUICK SORT " << std::endl;
    imprimirLista(numerosAleatorios);
    std::cout << "\nLa cantidad de ciclos fue: " << operaciones << std::endl;

    /*ahora por metodo merge sort siento como si no hubiera parpadeado en meses XD*/
    std::pair<std::vector<int>, int> resMergeSort = mergeSortWrapper(numerosAleatorios);
    std::cout<<"\nORDENAMIENTO POR MERGE SORT: "<<std::endl;
    imprimirLista(resMergeSort.first);
    std::cout<< "\nLa cantidad de intercambios fue : " << resMergeSort.second << std::endl;

     std::string metodoMasEficiente;
    int ciclosMasEficientes = std::min({resbubbleSort.second, resInsertionSort.second, resSelectionSort.second,
                                        resCountingSort.second, operaciones, resMergeSort.second});

    if (ciclosMasEficientes == resbubbleSort.second) {
        metodoMasEficiente = "Bubble Sort";
    } else if (ciclosMasEficientes == resInsertionSort.second) {
        metodoMasEficiente = "Insertion Sort";
    } else if (ciclosMasEficientes == resSelectionSort.second) {
        metodoMasEficiente = "Selection Sort";
    } else if (ciclosMasEficientes == resCountingSort.second) {
        metodoMasEficiente = "Counting Sort";
    } else if (ciclosMasEficientes == operaciones) {
        metodoMasEficiente = "Quick Sort";
    } else {
        metodoMasEficiente = "Merge Sort";
    }

    std::cout << "\nEl metodo mas eficiente es: " << metodoMasEficiente << " con " << ciclosMasEficientes << " ciclos." << std::endl;

    system("pause");
    return 0;
}
