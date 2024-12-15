# Versão mínima do CMake
cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(MyProject)

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
add_executable(estudo04 ${SOURCES})
