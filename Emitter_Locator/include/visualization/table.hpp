#ifndef TTT_Table_H
#define TTT_Table_H

#include "drawable_object.hpp"
#include "microphone.hpp"
#include <glm/glm.hpp>

namespace TTT {

class Table : DrawableObject {

  private:
    sf::RectangleShape table_rectangle_shape_;
    sf::RectangleShape middle_line1_;
    sf::RectangleShape middle_line2_;
    sf::RectangleShape left_line_;
    sf::RectangleShape right_line_;
    sf::CircleShape middle_;
    sf::CircleShape left_goal_;
    sf::CircleShape right_goal_;
    // quad array with for error cells
    sf::VertexArray error_vis_;
    // number of cells in error grid
    glm::vec2 grid_dimensions_;

    // builds the vertex array for error visualisation
    void generateErrorGrid();

  public:
    void setErrorDistribution(std::vector<std::vector<float>>);

    virtual void draw(sf::RenderWindow& canvas) const;
    void draw(sf::RenderWindow& canvas, std::vector<Microphone> const& microphones, glm::vec4 const& toas) const;
    virtual void recalculateGeometry();
    void setFillColor(sf::Color const& in_fill_color);
};


};

#endif