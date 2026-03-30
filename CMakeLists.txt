cmake_minimum_required(VERSION 3.10)

project(aventuriers_du_rail)

set(CMAKE_CXX_STANDARD 17)

add_executable(aventuriers_du_rail
main.cpp
CarteTrain.cpp
Joueur.cpp
Plateau.cpp
Route.cpp
Ticket.cpp
Ville.cpp
)
