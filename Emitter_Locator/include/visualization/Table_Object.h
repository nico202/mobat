#ifndef TTT_TABLE_OBJECT_H
#define TTT_TABLE_OBJECT_H

#include "drawable_object.h"
#include "microphone_object.h"
#include <glm/glm.hpp>

namespace TTT {

class Table_Object : DrawableObject {

	private:
		sf::RectangleShape table_rectangle_shape_;
		sf::RectangleShape middle_line1_;
		sf::RectangleShape middle_line2_;
		sf::RectangleShape left_line_;
		sf::RectangleShape right_line_;
		sf::CircleShape middle_;
		sf::CircleShape left_goal_;
		sf::CircleShape right_goal_;

	public:
		virtual void Draw(sf::RenderWindow& canvas) const;
		void Draw(sf::RenderWindow& canvas, std::vector<MicrophoneObject> const& microphones, glm::vec4 const& toas) const;
		virtual void recalculateGeometry();
		void setFillColor(sf::Color const& in_fill_color);
};


};

#endif