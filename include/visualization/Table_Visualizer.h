#ifndef TABLE_VISUALIZER_H
#define TABLE_VISUALIZER_H

#include "Table_Object.h"
#include "Microphone_Object.h"
#include "Recognized_Token_Object.h"

#include <vector>
#include <map>
#include <set>

namespace TTT {




class Table_Visualizer : Drawable_Object {

	private:
		Table_Object table_;
		std::vector<Microphone_Object> microphones_;
		//register them with their frequency
		std::map<unsigned, Recognized_Token_Object> recognized_tokens_;

		unsigned token_recognition_timeout_;

		std::set<unsigned> tokens_to_refresh_;

	public:
		Table_Visualizer(sf::Vector2u const& in_canvas_resolution = sf::Vector2u(800, 600),
						 sf::Vector2f const& table_dims = sf::Vector2f(2.0,1.0), 
						 std::vector<sf::Vector2f> const& microphone_positions
						 	= std::vector<sf::Vector2f>(),
						 sf::Color const& in_table_fill_color 
						 	= sf::Color(82,159,153),
						 sf::Color const& in_microphone_fill_color 
						 	= sf::Color(0,255,0, 125),
						 sf::Color const& in_token_fill_color 
						 	= sf::Color(255,0,0) 
						);
		~Table_Visualizer();

		virtual void Draw(sf::RenderWindow& in_canvas) const;

		void Resize_Physical_Table(sf::Vector2f const& in_table_dims);

		void Reset_Microphones(std::vector<Microphone_Object> const& in_microphones);

		void Recalculate_Geometry();

		void Set_Canvas_Resolution( sf::Vector2u const& in_resolution );

		void Set_Table_Fill_Color(sf::Color const& in_table_fill_color);

		void Set_Microphone_Fill_Color( sf::Color const& in_microphone_fill_color );

		void Set_Token_Fill_Color( sf::Color const& in_microphone_fill_color );

		void Set_Token_Recognition_Timeout( unsigned in_timeout_in_ms );

		void Signal_Token(unsigned int in_id, sf::Vector2f const& in_position);

		void Finalize_Visualization_Frame();
};

}; //end TTT
#endif