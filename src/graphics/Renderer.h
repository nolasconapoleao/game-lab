//
// Created by nolasco on 09/05/20.
//
#include <common/Match.h>

#include "OptionList.h"
#include "input/Input.h"
#include "rooms/World.h"

#pragma once

class Renderer {
public:
  void start();
  void end();
  void paintScreen();
  std::vector<std::string> convos;
  std::vector<std::string> hud;
  std::vector<std::string> room;
  OptionList options;

private:
  void clearScreen();
  void paintHUD();
  void paintConvos();
  void paintRoom();
  void paintOptions();

  std::string sepatator = "=====================================================================\n";
  std::string sepatator2 = "---------------------------------------------------------------------\n";
  std::string sepatator3 = "\n\t\+++++++++++++++++++++++";
};
