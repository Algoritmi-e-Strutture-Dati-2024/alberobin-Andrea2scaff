template <typename T>
class AlberoBinario {
private:
    T nodi[100];
    bool presente[100] = {false}; 

public:
    AlberoBinario() {}

    bool alberoVuoto() const {
        return !presente[0];   // ! restituisce il valore contrario
    }

    void insRadice(const T& valore) {
        nodi[0] = valore;
        presente[0] = true;
    }

    T radice() const {
        if (alberoVuoto()) {
            return T(); 
        }
        return nodi[0];
    }

    bool isFoglia(int indice) const {
        if (indice < 0 || indice >= 100 || !presente[indice]) {
            return false;
        }
        return !(presente[2 * indice + 1] || presente[2 * indice + 2]);
    }

    int figlioSinistro(int indice) const {
        return 2 * indice + 1;
    }

    int figlioDestro(int indice) const {
        return 2 * indice + 2;
    }

    void insFiglioSinistro(int indice, const T& valore) {
        int sinistro = figlioSinistro(indice);
        if (indice >= 0 && indice < 100 && presente[indice] && sinistro < 100) {
            nodi[sinistro] = valore;
            presente[sinistro] = true;
        }
    }

    void insFiglioDestro(int indice, const T& valore) {
        int destro = figlioDestro(indice);
        if (indice >= 0 && indice < 100 && presente[indice] && destro < 100) {
            nodi[destro] = valore;
            presente[destro] = true;
        }
    }

    void rimuovi(int indice) {
        if (indice >= 0 && indice < 100 && presente[indice] && isFoglia(indice)) {
            presente[indice] = false; 
        }
    }

    void stampa() const {
        for (int i = 0; i < 100; ++i) {
            if (presente[i]) {
                std::cout << "Posizione " << i << ", Valore: " << nodi[i];
                int sinistro = figlioSinistro(i);
                int destro = figlioDestro(i);
                if (sinistro < 100 && presente[sinistro])
                    std::cout << ", Figliosinistro: " << nodi[sinistro];
                else
                    std::cout << ", Figliosinistro: vuoto";
                
                if (destro < 100 && presente[destro])
                    std::cout << ", Figliodestro: " << nodi[destro];
                else
                    std::cout << ", Figliodestro: vuoto";
                
                std::cout << std::endl;
            }
        }
    }
};
