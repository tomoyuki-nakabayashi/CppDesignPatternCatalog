// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#include "active_object.h"
#include <iostream>

void ActiveObjectEngine::AddCommand(int c) {
  commands_.push_back(c);
}

void ActiveObjectEngine::Run() {
  for (const auto& c : commands_) {
    std::cout << c << std::endl;
  }
}