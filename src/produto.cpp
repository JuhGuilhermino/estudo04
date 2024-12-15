#include "produto.h"

Produto::Produto(int novo_id, std::string novo_nome, float novo_preco): id(novo_id), nome(novo_nome), preco(novo_preco) {}

int Produto::get_id(){
    return id;
}

std::string Produto::get_nome(){
    return nome;
}

float Produto::get_preco(){
    return preco;
}
