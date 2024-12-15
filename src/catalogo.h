/**
 * @file catalogo.h
 * @author Júlia Guilhermino (juh.guilhermino03@gmail.com)
 * @brief Definição da classe Catalogo que gerencia os produtos.
 * @version 0.1
 * @date 2024-12-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef CATALOGO_H
#define CATALOGO_H

#include <iostream>
#include <vector>
#include "produto.h"

class Catalogo {
    private:
        std::vector <Produto> catalogo; //> Simula um banco de dados com todos os produtos.
    
    public:
        /**
         * @brief Método cosntrutor da classe
         * 
         */
        Catalogo();

        /**
         * @brief Adiciona um novo produto ao catálogo.
         * 
         * @param nome 
         * @param preco 
         */
        void adicionar_produto(std::string nome, float preco);

        /**
         * @brief Lista todos os produtos do catálogo.
         * 
         */
        void listar_produtos();

        /**
         * @brief 
         * 
         * @param id 
         * @return Produto = um objeto do tipo porduto.
         */
        Produto buscar_produto(int id);

        /**
         * @brief Retorna a quantidade de produtos no catálogo
         * 
         * @return int 
         */
        int qtd_produtos();
};

#endif
