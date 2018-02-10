// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#include <active_object_engine.h>
#include <iostream>

namespace active_object {
void ActiveObjectEngine::AddCommand(Command *c) {
  commands_.push_back(c);
}

void ActiveObjectEngine::Run() {
  while (!commands_.empty()) {
    auto c = commands_.front();
    commands_.erase(commands_.begin());
    c->Execute();
  }
}
}  // namespace active_object
