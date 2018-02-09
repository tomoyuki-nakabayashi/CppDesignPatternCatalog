#ifndef DESIGN_PATTERN_CATALOG_BEHAVIORAL_ACTIVE_OBJECT_COMMAND_H_
#define DESIGN_PATTERN_CATALOG_BEHAVIORAL_ACTIVE_OBJECT_COMMAND_H_

namespace active_object {
class Command {
 public:
    Command() = default;
    virtual ~Command() = default;
    virtual void Execute() = 0;
};

}  // namespace active_object
#endif  // DESIGN_PATTERN_CATALOG_BEHAVIORAL_ACTIVE_OBJECT_COMMAND_H_