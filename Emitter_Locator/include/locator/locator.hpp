#ifndef LOCATOR_H
#define LOCATOR_H

#include "microphone.hpp"

class Locator{
  public:

    Locator(double c,
           Microphone const& m1, Microphone const& m2, Microphone const& m3, Microphone const& m4);

    // set the speed of sound
    void set_c(double c);

    // set the signal arrival times
    void update_times(double a, double b, double c, double d);


    // calculate position from current parameters
    glm::vec2 locate() const;
    
  private:
    // calculates the difference of ?
    double dif(glm::vec2 const& p, Microphone const& mic1, Microphone const& mic2) const;

    double c_;
    Microphone mics_[4];
    glm::vec2 min_;
    glm::vec2 max_;
};




#endif