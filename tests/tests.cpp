#include <gtest/gtest.h>
#include "../src/catalogo.h"  
#include "../src/pedido.h"   

// Testar a adição de um novo produto ao catálogo
TEST(catalogo_test, adicionar_produto){
    Catalogo catalogo;
    catalogo.adicionar_produto("Produto", 10.00);

    ASSERT_EQ(catalogo.qtd_produtos(), 1);
}

// Testar a busca de um produto no catalogo
TEST(catalogo_test, buscar_produto){
    Catalogo catalogo;
    catalogo.adicionar_produto("Produto", 10.00);

    ASSERT_EQ(catalogo.buscar_produto(0).get_nome(), "Produto");
}

// Testar adicionar produtos do catalogo ao pedido
TEST(pedido_test, buscar_produto){
    Catalogo catalogo;
    Pedido pedido;

    // Adicionar produtos ao catálogo;
    catalogo.adicionar_produto("Produto 1", 10.00);

    // Adicicionar produtos do catalogo ao pedido
    pedido.adicionar_produto(catalogo.buscar_produto(0));

    ASSERT_EQ(pedido.qtd_itens(), 1);
}

// Testar adicionar produtos do catalogo ao pedido
TEST(pedido_test, calcular_preco_pedido){
    Catalogo catalogo;
    Pedido pedido;

    // Adicionar produtos ao catálogo;
    catalogo.adicionar_produto("Produto 1", 10.00);
    catalogo.adicionar_produto("Produto 2", 20.50);

    // Adicicionar produtos do catalogo ao pedido
    pedido.adicionar_produto(catalogo.buscar_produto(0));
    pedido.adicionar_produto(catalogo.buscar_produto(1));

    ASSERT_EQ(pedido.calcular_total(), 30.50);
}

// Testar aplicação do desconto no preço dos produtos
TEST(pedido_test, calcular_desconto){
    Catalogo catalogo;
    Pedido pedido;

    // Adicionar produtos ao catálogo;
    catalogo.adicionar_produto("Produto 1", 150.00);

    // Adicicionar produtos do catalogo ao pedido
    pedido.adicionar_produto(catalogo.buscar_produto(0));

    ASSERT_EQ(pedido.calcular_total(), 135);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
