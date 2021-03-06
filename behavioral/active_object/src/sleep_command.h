// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef BEHAVIORAL_ACTIVE_OBJECT_SLEEP_COMMAND_H_
#define BEHAVIORAL_ACTIVE_OBJECT_SLEEP_COMMAND_H_

#include <command.h>
#include <active_object_engine.h>
#include <chrono>
#include <functional>

namespace active_object {
class WakeUpCommand : public Command {
 public:
    WakeUpCommand() : executed {false} {}
    ~WakeUpCommand() = default;
    void Execute() override { executed = true; }
    bool IsExecuted() { return executed; }
 private:
    bool executed;
};

using time_point = std::chrono::system_clock::time_point;
class SleepCommand : public Command {
 public:
    explicit SleepCommand(ActiveObjectEngine* = nullptr,
                          Command* = nullptr,
                          const int ms = 0);
    ~SleepCommand() = default;
    void Execute() override;
 private:
    void ExecuteAtStart();
    void ExecuteAfterStarted();
 private:
    std::function<void()> executor_;
    ActiveObjectEngine *engine_;
    Command *wakeup_command_;
    const int sleep_time_;
    time_point start_time_;
};
}  // namespace active_object
#endif  // BEHAVIORAL_ACTIVE_OBJECT_SLEEP_COMMAND_H_