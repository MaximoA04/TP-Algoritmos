cmake_minimum_required(VERSION 3.10)
project(comun C)

# 1. Configuración de archivos fuente
set(SOURCES comun.c comun.h)

# 2. Definir la carpeta de destino según el SO
if(WIN32)
    set(OS_DIR "win")
else()
    set(OS_DIR "linux")
endif()

# 3. Crear la librería estática
add_library(comun STATIC ${SOURCES})

# 4. Configurar la salida del archivo .a
set_target_properties(comun PROPERTIES 
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib/${OS_DIR}"
    OUTPUT_NAME "comun"
)
