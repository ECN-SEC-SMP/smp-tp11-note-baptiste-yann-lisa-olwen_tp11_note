cmake_minimum_required(VERSION 3.16)
project(AventuriersDuRail)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)   # nécessaire pour Q_OBJECT
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

