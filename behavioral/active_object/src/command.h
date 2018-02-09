#ifndef DESIGN_PATTERN_CATALOG_BEHAVIORAL_ACTIVE_OBJECT_COMMAND_H_
#define DESIGN_PATTERN_CATALOG_BEHAVIORAL_ACTIVE_OBJECT_COMMAND_H_

class Command {
 public:
    Command() = default;
    ~Command() = default;
    virtual void execute() = 0;
};

#endif  // DESIGN_PATTERN_CATALOG_BEHAVIORAL_ACTIVE_OBJECT_COMMAND_H_