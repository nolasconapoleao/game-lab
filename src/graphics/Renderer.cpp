//
// Created by nolasco on 09/05/20.
//

#include "Renderer.h"

#include <iostream>

#include "config/cmakeconfig.h"
#include "utils/PrintUtils.h"

void Renderer::start() {
  std::cout << "Begin game!" << std::endl;
  std::cout << sepatator << std::endl;
  std::cout << sepatator << std::endl;
}

void Renderer::end() {
  paintConvos();
  std::cout << std::endl;
  std::cout << sepatator << std::endl;
  std::cout << sepatator << std::endl;
  std::cout << "Game ended!" << std::endl;
}

void Renderer::paintScreen() {
  clearScreen();
  paintConvos();
  std::cout << sepatator;
  paintRoom();
  paintHUD();
  std::cout << sepatator2;
  paintOptions();
  std::cout << "What do you wanna do? ";
}

void Renderer::clearScreen() {
#ifdef COMPILE_FOR_NON_UNIX
  std::system("cls");
#else
  std::system("clear");
#endif
};

void Renderer::paintConvos() {
  std::cout << convos;
  convos.clear();
}

void Renderer::paintHUD() {
  std::cout << sepatator3;
  std::cout << hud;
  hud.clear();
}

void Renderer::paintRoom() {
  std::cout << "You are at: ";
  std::cout << room;
  room.clear();
}

void Renderer::paintOptions() {
  std::cout << options;
}
