cmake_minimum_required(VERSION 3.10)
project(TDA_ListaDoble C)

# 1. Configuración de archivos fuente
set(SOURCES listaDoble.c listaDoble.h)

# 2. Definir la carpeta de destino según el SO
if(WIN32)
    set(OS_DIR "win")
else()
    set(OS_DIR "linux")
endif()

# 3. Crear la librería estática de la Lista
add_library(listaDoble STATIC ${SOURCES})

# 4. Localizar la librería comun ya compilada
find_library(LIB_COMUN_PATH
    NAMES "libcomun.a"
    PATHS "${CMAKE_CURRENT_SOURCE_DIR}/../comun/lib/${OS_DIR}"
    NO_DEFAULT_PATH
)

# 5. Vincular la Lista con el binario de Comun
target_link_libraries(listaDoble PUBLIC ${LIB_COMUN_PATH})

# 6. Headers
target_include_directories(listaDoble PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/../comun"
)

# 7. Configurar la salida del archivo .a de la Lista
set_target_properties(listaDoble PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib/${OS_DIR}"
    OUTPUT_NAME "listaDoble"
)
