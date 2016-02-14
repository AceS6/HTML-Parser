# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION 3.0)

# Notre projet est étiqueté hello
project(parser)

set( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin )

# Crée des variables avec les fichiers à compiler
file(GLOB SRC
    "src/*.c"
)
file(GLOB HEADER
    "include/*.h"
)

# On indique que l'on veut un exécutable "hello" compilé à partir des fichiers décrits par les variables SRCS et HEADERS
add_executable(parser ${SRC} ${HEADER})
