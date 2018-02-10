// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#include <sleep_command.h>

namespace active_object {
SleepCommand::SleepCommand(ActiveObjectEngine* e, Command* c, const int ms)
    : executor_ {std::bind(&SleepCommand::ExecuteAtStart, this)}
    , engine_ {e}
    , wakeup_command_ {c}
    , sleep_time_ {ms}
    , start_time_ {} {
}

void SleepCommand::Execute() {
  executor_();
}

void SleepCommand::ExecuteAtStart() {
  start_time_ = std::chrono::system_clock::now();
  engine_->AddCommand(this);
  executor_ = std::bind(&SleepCommand::ExecuteAfterStarted, this);
}

void SleepCommand::ExecuteAfterStarted() {
  auto current = std::chrono::system_clock::now();
  int elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(
    current - start_time_).count();
  if (elapsed < sleep_time_) {
    engine_->AddCommand(this);
  } else {
    engine_->AddCommand(wakeup_command_);
  }
}
}  // namespace active_object
