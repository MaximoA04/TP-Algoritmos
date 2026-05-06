cmake_minimum_required(VERSION 3.10)
project(TDA_Pila C)

# 1. Configuración de archivos fuente
set(SOURCES pila.c pila.h)

# 2. Definir la carpeta de destino según el SO
if(WIN32)
    set(OS_DIR "win")
else()
    set(OS_DIR "linux")
endif()

# 3. Crear la librería estática
add_library(pila STATIC ${SOURCES})

# 4. Localizar la librería comun ya compilada
find_library(LIB_COMUN_PATH 
    NAMES "libcomun.a"
    PATHS "${CMAKE_CURRENT_SOURCE_DIR}/../comun/lib/${OS_DIR}"
    NO_DEFAULT_PATH
)

# 5. Vincular
target_link_libraries(pila PUBLIC ${LIB_COMUN_PATH})

# 6. Headers
target_include_directories(pila PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/../comun"
)

# 7. Configurar la salida del archivo .a
set_target_properties(pila PROPERTIES 
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib/${OS_DIR}"
    OUTPUT_NAME "pila"
)