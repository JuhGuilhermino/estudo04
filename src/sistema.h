/**
 * @file sistema.h
 * @author Júlia Guilhermino (juh.guilhermino03@gmail.com)
 * @brief Declaração da classe queimplemnta a arquitetura Game Loop e o funcionamento do sistema.
 * @version 0.1
 * @date 2024-12-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include "pedido.h"
#include "catalogo.h"

class Sistema{
    private:
        //* Estados do Game Loop
        enum estados{
            INICIALIZAR = 0,
            MENU,
            ATUALIZAR_CATALOGO,
            COMPRAR,
            FINALIZAR,
            CANCELAR,
            SAIR
        };

        //* Tipos de usuário
        enum usuarios{
            ADMINISTRADOR = 0,
            CLIENTE
        };

        int estado = 0;               //> Controle do estado do loop.
        int usuario;                  //> Controle do tipo de usuário.

        std::string nome_usuario;     //> Nome do usário.
        std::string nome_produto;     //> Nome do novo produto.
        float preco;                  //> Preco do novo produto.
        int qtd_novos_produtos = 0;   //> Quantidade de produtos adicinados ao catálogo em um acesso do adm.


        bool sair = false;            //> Gatilho para encerrar o loop.
        bool atualizar = true;        //> Gatilho para continuar a add itens.
        int operacao;                 //> Determina operações do usuário: add um item ao pedido, finaizar, sair da compra.

        Catalogo catalogo;            //> Catalogo de produtos.
        Pedido pedido;                

    public:
        /**
         * @brief Método consturtor da classe
         * 
         */
        Sistema();

        /**
         * @brief Processamento de dados de entrada
         * 
         */
        void process_events();

        /**
         * @brief Atualização do sistema e estados
         * 
         */
        void update();

        /**
         * @brief Renderização do sistema
         * 
         */
        void render();

        /**
         * @brief Condição de parada do loop
         * 
         */
        bool game_over();
};

#endif
