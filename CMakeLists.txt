cmake_minimum_required(VERSION 3.16)
project(AventuriersDuRail)
 
set(CMAKE_CXX_STANDARD 17)
 
option(BUILD_DOC_ONLY "Ne construire que la documentation (pas besoin de Qt6)" OFF)
 
if(NOT BUILD_DOC_ONLY)
    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTORCC ON)
    set(CMAKE_AUTOUIC ON)
 
    find_package(Qt6 COMPONENTS Core Widgets REQUIRED)
 
    add_executable(AventuriersDuRail
        main.cpp
        Affichage.cpp
        Affichage.h
        Joueur.cpp
        Joueur.h
        Plateau.cpp
        Plateau.h
        CarteTrain.cpp
        CarteTrain.h
        Route.cpp
        Route.h
        Ville.cpp
        Ville.h
        Ticket.cpp
        Ticket.h
        CouleurCarte.h
        CouleurRoute.h
        CouleurWagon.h
    )
 
    target_link_libraries(AventuriersDuRail Qt6::Core Qt6::Widgets)
endif()
 
# ── Documentation avec Doxygen ─────────────────────────────────────────────────
find_package(Doxygen QUIET)
 
if(DOXYGEN_FOUND)
    set(DOXYGEN_IN  ${CMAKE_SOURCE_DIR}/Doxyfile)
    set(DOXYGEN_OUT ${CMAKE_BINARY_DIR}/Doxyfile.generated)
 
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
 
    add_custom_target(doc
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Génération de la documentation Doxygen..."
        VERBATIM
    )
 
    message(STATUS "Doxygen trouvé – cible 'doc' disponible (cmake --build . --target doc)")
else()
    message(WARNING
        "Doxygen non trouvé – la cible 'doc' ne sera pas disponible.\n"
        "  Linux  : sudo apt install doxygen graphviz\n"
        "  macOS  : brew install doxygen graphviz\n"
        "  Windows: https://www.doxygen.nl/download.html"
    )
endif()