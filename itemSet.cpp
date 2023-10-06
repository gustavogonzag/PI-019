#include <iostream>
#include <vector>
#include <string>

class ItemSet {
private:
    std::vector<std::string> items;

public:
    // Método para inserir um item no conjunto, se ele não existir.
    void inserir(const std::string& s) {
        // Verifica se o item já existe no conjunto.
        bool itemJaExiste = false;
        for (const std::string& item : items) {
            if (item == s) {
                itemJaExiste = true;
                break;
            }
        }

        // Se o item não existir, insere-o no conjunto.
        if (!itemJaExiste) {
            items.push_back(s);
            std::cout << "Item '" << s << "' inserido no conjunto." << std::endl;
        } else {
            std::cout << "Item '" << s << "' já existe no conjunto." << std::endl;
        }
    }

    // Método para excluir um item do conjunto, se ele existir.
    void excluir(const std::string& s) {
        // Procura o item no conjunto e o remove, se encontrado.
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (*it == s) {
                items.erase(it);
                std::cout << "Item '" << s << "' excluído do conjunto." << std::endl;
                return; // Item encontrado e excluído, podemos sair do loop.
            }
        }

        // Se o item não foi encontrado, exibe uma mensagem.
        std::cout << "Item '" << s << "' não encontrado no conjunto." << std::endl;
    }

    // Método para imprimir os itens do conjunto.
    void imprimir() {
        std::cout << "Itens no conjunto: ";
        for (const std::string& item : items) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    ItemSet conjunto;

    conjunto.inserir("Item1");
    conjunto.inserir("Item2");
    conjunto.inserir("Item3");
    conjunto.inserir("Item1"); // Tentando inserir um item repetido.

    conjunto.imprimir();

    conjunto.excluir("Item2");
    conjunto.excluir("Item4"); // Tentando excluir um item que não existe.

    conjunto.imprimir();

    return 0;
}
