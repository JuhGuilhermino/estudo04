/**
 * @file produto.h
 * @author Júlia Guilhermino (juh.guilhermino03@gmail.com)
 * @brief Definição da classe Produto que representa um porduto do catálogo da loja.
 * @version 0.1
 * @date 2024-12-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>

class Produto {
    private:
        int id;             //> Identificador do produto
        std::string nome;
        float preco;

    public:
        /**
         * @brief Método construtor de um novo objeto Produto
         * 
         * @param novo_id 
         * @param novo_nome 
         * @param novo_preco 
         */
        Produto(int novo_id, std::string novo_nome, float novo_preco);

        /**
         * @brief Retorna o id do produto.
         * 
         * @return int 
         */
        int get_id();

        /**
         * @brief Retorna o nome do produto.
         * 
         * @return std::string 
         */
        std::string get_nome();

        /**
         * @brief Retorna o preço do produto.
         * 
         * @return float 
         */
        float get_preco();
};

#endif
