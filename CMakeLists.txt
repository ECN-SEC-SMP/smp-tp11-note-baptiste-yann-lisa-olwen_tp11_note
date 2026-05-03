cmake_minimum_required(VERSION 3.16)
project(AventuriersDuRail VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 17)

option(BUILD_DOC_ONLY "Ne construire que la documentation (pas besoin de Qt6)" OFF)

if(NOT BUILD_DOC_ONLY)
    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTORCC ON)
    set(CMAKE_AUTOUIC ON)

    find_package(Qt6 COMPONENTS Core Widgets REQUIRED)

    add_executable(AventuriersDuRail
        main.cpp
        Affichage.cpp  Affichage.h
        Joueur.cpp     Joueur.h
        Plateau.cpp    Plateau.h
        CarteTrain.cpp CarteTrain.h
        Route.cpp      Route.h
        Ville.cpp      Ville.h
        Ticket.cpp     Ticket.h
        CouleurCarte.h
        CouleurRoute.h
        CouleurWagon.h
        modules.h 
    )
configure_file(${CMAKE_SOURCE_DIR}/ticket.csv ${CMAKE_BINARY_DIR}/ticket.csv COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/map.csv ${CMAKE_BINARY_DIR}/map.csv COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/route.csv ${CMAKE_BINARY_DIR}/route.csv COPYONLY)

    target_link_libraries(AventuriersDuRail Qt6::Core Qt6::Widgets)
endif()

# ── Documentation avec Doxygen ────────────────────────────────────────────────
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

    add_custom_target(doc-open
        COMMAND xdg-open ${CMAKE_SOURCE_DIR}/docs/html/index.html 2>/dev/null ||
                open     ${CMAKE_SOURCE_DIR}/docs/html/index.html 2>/dev/null || true
        DEPENDS doc
        COMMENT "Ouverture de la documentation dans le navigateur..."
    )

    message(STATUS "Doxygen trouvé – cibles disponibles :")
    message(STATUS "  cmake --build . --target doc       (générer)")
    message(STATUS "  cmake --build . --target doc-open  (générer + ouvrir)")
else()
    message(WARNING
        "Doxygen non trouvé – la cible 'doc' ne sera pas disponible.\n"
        "  Linux  : sudo apt install doxygen graphviz\n"
        "  macOS  : brew install doxygen graphviz\n"
        "  Windows: https://www.doxygen.nl/download.html"
    )
endif()