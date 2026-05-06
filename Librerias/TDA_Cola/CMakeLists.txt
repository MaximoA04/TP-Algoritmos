cmake_minimum_required(VERSION 3.10)
project(TDA_Cola C)

# 1. Configuración de archivos fuente
set(SOURCES cola.c cola.h)

# 2. Definir la carpeta de destino y el nombre de la librería según el SO
if(WIN32)
    set(OS_DIR "win")
else()
    set(OS_DIR "linux")
endif()

# 3. Crear la librería estática
add_library(cola STATIC ${SOURCES})

# 4. Localizar la librería comun ya compilada
find_library(LIB_COMUN_PATH 
    NAMES "libcomun.a"
    PATHS "${CMAKE_CURRENT_SOURCE_DIR}/../comun/lib/${OS_DIR}"
    NO_DEFAULT_PATH
)

# 5. Vincular
target_link_libraries(cola PUBLIC ${LIB_COMUN_PATH})

# 6. Headers
target_include_directories(cola PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/../comun"
)

# 7. Salida de la librería cola
set_target_properties(cola PROPERTIES 
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib/${OS_DIR}"
    OUTPUT_NAME "cola"
)