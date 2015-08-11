#ifndef TTT_TEST_H
#define TTT_TEST_H


#include <fstream>

#include <sstream>
#include <map>
#include <vector>

#include <testMapEntry.hpp>

namespace TTT{

  
class Test{
  private:
    std::map<std::string, TTT::TestMapEntry> files_;

  public:
    Test();
    void update(unsigned const& freq, glm::vec2 const& pos);
    void openFiles(std::vector<std::pair<std::string, std::string>> const& names);
    void closeFiles();
    long calculateStandardDeviation(std::string const& path, glm::vec2 const& avg_pos);
    int calculatePercentile(std::string const& path, glm::vec2 const& avg_pos, long standard_deviation);
};

};


#endif