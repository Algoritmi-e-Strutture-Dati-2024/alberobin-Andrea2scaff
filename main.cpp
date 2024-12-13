#include <iostream>
#include "AlberoBinario.cpp" 

int main() {
    AlberoBinario<int> albero;

    albero.insRadice(1);

    albero.insFiglioSinistro(0, 2);  // Figlio sinistro di 1
    albero.insFiglioDestro(0, 3);    // Figlio destro di 1
    albero.insFiglioSinistro(1, 4);  // Figlio sinistro di 2
    albero.insFiglioDestro(1, 5);    // Figlio destro di 2
    albero.insFiglioSinistro(2, 6);  // Figlio sinistro di 3
    albero.insFiglioDestro(2, 7);    // Figlio destro di 3
    albero.insFiglioSinistro(3, 8);  // Figlio sinistro di 4
    albero.insFiglioDestro(7, 9);    // Figlio destro di 8

    // Stampa dei figli di nodo 4 all'indice 3
    std::cout << "Nodi figli di 4 (indice 3):" << std::endl;
    
    int figlioSinistro = albero.figlioSinistro(3);
    int figlioDestro = albero.figlioDestro(3);

    // Stampa dei figli sinistro e destro
    std::cout << "  Figlio sinistro di 4: ";
    if (figlioSinistro != -1) {
        std::cout << figlioSinistro << std::endl;
    } else {
        std::cout << "vuoto" << std::endl;
    }

    std::cout << "  Figlio destro di 4: ";
    if (figlioDestro != -1) {
        std::cout << figlioDestro << std::endl;
    } else {
        std::cout << "vuoto" << std::endl;
    }

    // Rimozione del nodo 9 all'indice 8
    albero.rimuovi(8);

    // Stampa della struttura del novo albero dopo la rimozione
    std::cout << "Struttura dell'albero dopo la rimozione del nodo 9:" << std::endl;
    albero.stampa();

    return 0;
}


