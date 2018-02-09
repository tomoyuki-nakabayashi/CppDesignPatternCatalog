// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#include <sleep_command.h>

namespace active_object {
SleepCommand::SleepCommand(ActiveObjectEngine* e, Command* c, const int ms)
    : engine_ {e}
    , wakeup_command_ {c}
    , sleep_time_ {ms}
    , start_time_ {}
    , started {bool} {  
}

SleepCommand::Execute() {
  
}

}  // namespace active_object
