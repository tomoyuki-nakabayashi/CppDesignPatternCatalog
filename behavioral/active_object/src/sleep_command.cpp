// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#include <sleep_command.h>

namespace active_object {
SleepCommand::SleepCommand(ActiveObjectEngine* e, Command* c, const int ms)
    : engine_ {e}
    , wakeup_command_ {c}
    , sleep_time_ {ms}
    , start_time_ {}
    , started_ {false} {  
}

void SleepCommand::Execute() {
  auto current = std::chrono::system_clock::now();
  int elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(current - start_time_).count();
  if (!started_) {
    started_ = true;
    start_time_ = current;
    engine_->AddCommand(this);
  } else if (elapsed < sleep_time_) {
    engine_->AddCommand(this);
  } else {
    engine_->AddCommand(wakeup_command_);
  }
}

}  // namespace active_object
