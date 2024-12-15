#include "catalogo.h"

Catalogo::Catalogo(){}

void Catalogo::adicionar_produto(std::string nome, float preco){
    // Calcula o ID do novo produto
    int novo_id = catalogo.size();
    
    // Adciona produto ao catalogo
    Produto new_produto(novo_id, nome, preco);
    catalogo.push_back(new_produto);
}

void Catalogo::listar_produtos(){
    for (int i = 0; i < catalogo.size(); i++){
       std::cout << catalogo[i].get_id() << " - " << catalogo[i].get_nome() << " - R$ " << catalogo[i].get_preco() << std::endl;
    }
}

Produto Catalogo::buscar_produto(int id){
    return catalogo[id];
}

int Catalogo::qtd_produtos(){
    return catalogo.size();
}
