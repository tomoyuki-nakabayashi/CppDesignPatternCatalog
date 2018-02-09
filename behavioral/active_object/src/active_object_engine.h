// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#ifndef DESIGN_PATTERN_CATALOG_BEHAVIORAL_ACTIVE_OBJECT_ENGINE_H_
#define DESIGN_PATTERN_CATALOG_BEHAVIORAL_ACTIVE_OBJECT_ENGINE_H_

#include <vector>
#include <command.h>

namespace active_object {
class ActiveObjectEngine {
 public:
    ActiveObjectEngine() = default;
    void AddCommand(Command *c);
    void Run();

 private:
    std::vector<Command*> commands_;
};
}  // namespace active_object
#endif  // DESIGN_PATTERN_CATALOG_BEHAVIORAL_ACTIVE_OBJECT_ENGINE_H_s