#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 
class ItemSet {
    private:
        vector<string> itens;

    public:
        void inserir(const string& s) {
            if (find(itens.begin(), itens.end(), s) == itens.end()) {
                itens.push_back(s);
                cout << "Item '" << s << "' inserido com sucesso." << endl;
            }
            else {
                cout << "Item '" << s << "' já existe no conjunto." << endl;
            }
        }
    void excluir(const string& s) {
        auto it = find(itens.begin(), itens.end(), s);
        if (it != itens.end()) {
            itens.erase(it);
            cout << "Item '" << s << "' excluído com sucesso." << endl;
        }
        else {
            cout << "Item '" << s << "' não encontrado no conjunto." << endl;
        }
    }
};

int main() {
    ItemSet conjunto;

    conjunto.inserir("Arroz");
    conjunto.inserir("Macarrão");
    conjunto.inserir("Feijão");

    conjunto.excluir("Feijão");
    conjunto.excluir("Biscoito Cream Cracker");

    return 0;
}
