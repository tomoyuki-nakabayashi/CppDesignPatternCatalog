#ifndef DESIGN_PATTERN_CATALOG_BEHAVIORAL_ACTIVE_OBJECT_H_
#define DESIGN_PATTERN_CATALOG_BEHAVIORAL_ACTIVE_OBJECT_H_

#include <vector>

class ActiveObjectEngine {
 public:
    ActiveObjectEngine() = default;
    void AddCommand(int c);
    void Run();

 private:
    std::vector<int> commands_;
};

#endif  // DESIGN_PATTERN_CATALOG_BEHAVIORAL_ACTIVE_OBJECT_H_