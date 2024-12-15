#include "sistema.h"

Sistema::Sistema(){}

void Sistema::process_events(){
    if (estado == estados::INICIALIZAR){
        std::cout << "============================= GERENCIADOR DE VENDAS =============================\n";
        std::cout << "Informe seu nome >>>    ";
        std::cin >> nome_usuario;
        std::cout << "Informe seu tipo de usuário:\n 0 - Adminstrador\n 1 - Cliente\n>>> ";
        std::cin >> usuario;

    } else if (estado == estados::ATUALIZAR_CATALOGO){
        std::cout << "Digite:\n 0 - para trocar tipo de usuário.\n 1 - para adiconar outro produto. \n>>>    ";
        std::cin >> atualizar;

        if (atualizar){
            std::cout << "\nNome do produto >>>    ";
            std::cin >> nome_produto;
            std::cout << "Preço >>>    ";
            std::cin >> preco;
        }
    } else if (estado == estados::MENU){
        std::cout << "Digite:\n 0 - Adicionar itens ao pedido.\n 1 - Finalizar pedido. \n 2 - Cancelar pedido. \n>>>    ";
        std::cin >> operacao;
    }
}

void Sistema::update(){
    if (estado == estados::INICIALIZAR){
        // Adiciona alguns itens ao catálogo
        catalogo.adicionar_produto("Tela 20x30", 20.00);
        catalogo.adicionar_produto("Kit Tinta Guache", 15.50);
        catalogo.adicionar_produto("Estojo de Aquarela em Patilha", 59.99);
        catalogo.adicionar_produto("Pincel Redondo nº 5", 59.99);

        // Atualiza para próximo estado.
        if (usuario == usuarios::ADMINISTRADOR){
            estado = estados::ATUALIZAR_CATALOGO;
        }
        if (usuario == usuarios::CLIENTE){
            estado = estados::MENU;
        }

    } else if (estado == estados::ATUALIZAR_CATALOGO){
        if (atualizar){
            // Adcionar produto ao catálogo
            catalogo.adicionar_produto(nome_produto, preco);
            qtd_novos_produtos++;

        } else {
            estado = estados::MENU;
        }

    } else if (estado == estados::MENU){
        if (operacao == 0){
            //estado = estados::COMPRAR;
            std::cout << "Comprar \n";
            estado = estados::SAIR;
        } else if (operacao == 1){
            //estado = estados::FINALIZAR;
            std::cout << "Finalizar compra \n";
            estado = estados::SAIR;
        } else if (operacao == 2){
            //estado = estados::CANCELAR;
            std::cout << "Cancelar \n";
            estado = estados::SAIR;
        } 

    } else if (estado == estados::SAIR){
        sair = true;
    }
}

void Sistema::render(){
    if (estado == estados::INICIALIZAR){
        // Não faz nada
    } else if (estado == estados::ATUALIZAR_CATALOGO){
        if (qtd_novos_produtos == 0) {
            std::cout << "--------------------------------- ADMINSTRADOR ----------------------------------\n";
            std::cout << "Bem vinde " << nome_usuario << "!\n";
        } else {
            // Exibir mensagem de confirmação
            std::cout << "'"<< catalogo.buscar_produto(catalogo.qtd_produtos()-1).get_nome() << "' foi adicionado com sucesso!\n\n";
        }

    } else if (estado == estados::MENU){
        std::cout << "------------------------------------- USUÁRIO -----------------------------------\n";
        std::cout << "USUÁRIO: " << nome_usuario << "\n";
        std::cout << "ITENS DO CARRINHO: ";
        if (pedido.qtd_itens() > 0) {
            std::cout << "\n";
            pedido.listar_produtos();
        } else {
            std::cout << " VAZIO\n";
        }
        std::cout << "TOTAL: R$ ";
        if (pedido.qtd_itens() > 0) {
            std::cout << pedido.calcular_total() << "\n";
            pedido.listar_produtos();
        } else {
            std::cout << " 0.0\n";
        } 
        

    } else if (estado == estados::SAIR){
        // Não faz nada
    }
}

bool Sistema::game_over(){
    return sair;
}