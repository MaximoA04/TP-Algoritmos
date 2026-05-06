cmake_minimum_required(VERSION 3.10)
project(TDA_Lista C)

# 1. Configuración de archivos fuente
set(SOURCES lista.c lista.h)

# 2. Definir la carpeta de destino según el SO
if(WIN32)
    set(OS_DIR "win")
else()
    set(OS_DIR "linux")
endif()
set(NAME_COMUN "comun")

# 3. Crear la librería estática de la Lista
add_library(lista STATIC ${SOURCES})

# 4. Localizar la librería comun ya compilada
find_library(LIB_COMUN_PATH 
    NAMES ${NAME_COMUN}
    PATHS "${CMAKE_CURRENT_SOURCE_DIR}/../comun/lib/${OS_DIR}"
    NO_DEFAULT_PATH
)

# 5. Vincular la Lista con el binario de Comun
target_link_libraries(lista PUBLIC ${LIB_COMUN_PATH})

# 6. Headers
target_include_directories(lista PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/../comun"
)

# 7. Configurar la salida del archivo .a de la Lista
set_target_properties(lista PROPERTIES 
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib/${OS_DIR}"
    OUTPUT_NAME "lista"
)