#ifndef SIGNAL_ANALYZER_H
#define SIGNAL_ANALYZER_H

#include "FFT_Transformer.h"

#include <array>

class Signal_Analyzer {

	private:
		unsigned short fft_window_size;
    	FFT_Transformer fft_transformer;

    	std::map<unsigned, std::array<double, 4> > frequency_toas_mapping;
    	std::map<unsigned, bool>	is_frequency_toa_mapping_valid;

    public:

    	Signal_Analyzer();
    	~Signal_Analyzer();

    	void analyze(int** current_audio_buffer, 
    				 unsigned int bytes_per_channel);

    	void stop_listening_to(unsigned const frequency);
    	void start_listening_to(unsigned const frequency);

    	std::array<double, 4> get_toas_for(unsigned const frequency) ;

    	//returns the fourier transformed and accumulated samples for
    	//the specified frequency
    	std::array<std::vector<double>,4> const 
    	get_signal_samples_for(unsigned const frequency) ;

		std::map<unsigned, std::array<unsigned, 4> > signal_detected_at_sample_per_frequency;
};

#endif