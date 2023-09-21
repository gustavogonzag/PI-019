#include <iostream>
#include <vector>
#include <algorithm> // Para a função std::find
using namespace std;

class ItemSet {
private:
    vector<string> itens;

public:
    // Método para inserir um item no conjunto, se ele não existir
    void inserir(const string& item) {
        // Verificar se o item já existe no conjunto
        if (find(itens.begin(), itens.end(), item) == itens.end()) {
            itens.push_back(item);
            cout << "Item \"" << item << "\" inserido com sucesso." << endl;
        } else {
            cout << "Item \"" << item << "\" já existe no conjunto." << endl;
        }
    }

    // Método para excluir um item do conjunto, se ele existir
    void excluir(const string& item) {
        auto it = find(itens.begin(), itens.end(), item);
        if (it != itens.end()) {
            itens.erase(it);
            cout << "Item \"" << item << "\" excluído com sucesso." << endl;
        } else {
            cout << "Item \"" << item << "\" não encontrado no conjunto." << endl;
        }
    }

    // Método para exibir o conjunto de itens
    void mostrarItens() const {
        cout << "Itens no conjunto:";
        for (const string& item : itens) {
            cout << " " << item;
        }
        cout << endl;
    }
};

int main() {
    ItemSet conjunto;

    conjunto.inserir("Item1");
    conjunto.inserir("Item2");
    conjunto.inserir("Item3");
    conjunto.inserir("Item1"); // Tentando inserir um item repetido

    conjunto.mostrarItens();

    conjunto.excluir("Item2");
    conjunto.excluir("Item4"); // Tentando excluir um item que não existe

    conjunto.mostrarItens();

    return 0;
}
