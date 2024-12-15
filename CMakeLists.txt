# Versão mínima do CMake
cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(GerenciadorDeVendas)

# Definir o padrão de compilação C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Definir o diretório contendo os arquivos de origem e cabeçalhos
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

# Listar os arquivos de origem
file(GLOB SOURCES
    ${SRC_DIR}/*.cpp
)

# Incluir o diretório para encontrar os arquivos de cabeçalhos
include_directories(${SRC_DIR})

# Criar o executável a partir dos arquivos de origem
add_executable(main ${SOURCES})

# Configuração para os testes
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Arquivo de testes
add_executable(tests tests/tests.cpp src/catalogo.cpp src/pedido.cpp src/produto.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES} pthread)

# Registra os testes
add_test(NAME Testes COMMAND tests)