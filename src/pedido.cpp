#include "pedido.h"

Pedido::Pedido(){}

void Pedido::adicionar_produto(Produto produto){
    produtos.push_back(produto);
}

void Pedido::listar_produtos(){
    for (int i = 0; i < produtos.size(); i++){
       std::cout << "     > " << produtos[i].get_id() << " - " << produtos[i].get_nome() << " - R$ " << produtos[i].get_preco() << std::endl;
    }
}

float Pedido::calcular_total(){
    float total = 0;
    for (int i = 0; i < produtos.size(); i++){
        total += produtos[i].Produto::get_preco();
    }
    return total;
}

int Pedido::qtd_itens(){
    return produtos.size();
}
