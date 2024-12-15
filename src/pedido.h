/**
 * @file pedido.h
 * @author Júlia Guilhermino (juh.guilhermino03@gmail.com)
 * @brief Rperesenta um produto do catálogo da loja.
 * @version 0.1
 * @date 2024-12-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef PEDIDO_H
#define PEDIDO_H

#include <iostream>
#include <vector>
#include "produto.h"
#include "catalogo.h"

class Pedido{
    private:
        std::vector <Produto> produtos;  //> Carrinho de compras
        std::string nome;                //> Nome do cliente.
        float total = 0;

    public:
        /**
         * @brief Método construtor da classe.
         * 
         */
        Pedido();

        /**
         * @brief Adiciona um novo produto a lista de compras (vetor produtos).
         * 
         * @param Produto objeto produto
         */
        void adicionar_produto(Produto produto);

        /**
         * @brief Lista todos os produtos do pedido.
         * 
         */
        void listar_produtos();

        /**
         * @brief Soma o preco de todos os produtos da lista produtos.
         * 
         * @return float 
         */
        float calcular_total();

        /**
         * @brief Retorna a quantidade de produtos da lista de pedidos
         * 
         * @return int 
         */
        int qtd_itens();

        /**
         * @brief Limpa o vetor de produtos
         * 
         */
        void limpar_produtos();

        float aplicar_desconto();
};

#endif