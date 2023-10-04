#include <iostream>
#include <vector>
#include <string>
using namespace std;

class ItemSet {
    private:
    vector<string> itens;
    public:
    void escreveItens(){
        cout << "Lista de Itens:" << endl;
        for(string s: itens)
            cout << s << endl;
    }
    void insereItem(string item){
        for(string s: itens){
            if (s == item){
                cout << "O item " << item << " ja esta no conjunto" << endl;
                return;
            }
        }
        itens.push_back(item);
    }
    void excluiItem(string item){
          for(auto s=itens.begin();s!=itens.end();s++){
            if (*s == item){
                itens.erase(s);
                cout << "O item " << item << " foi excluido" << endl;
                return;
            }
        }
        cout << "O item " << item << " nao esta na lista" << endl;
    }
};


int main(void){
    ItemSet lista;
    lista.insereItem("arroz");
    lista.insereItem("feijao");
    lista.insereItem("batata");
    lista.escreveItens();
    lista.insereItem("feijao");
    lista.excluiItem("arroz");
    lista.excluiItem("carne");
    lista.escreveItens();
}