#ifndef DEVICE_HPP
#define DEVICE_HPP

#include <alsa/asoundlib.h>
#include <iostream>

struct device {
  device() :
   handle{nullptr},
   name{""},
   type{SND_PCM_STREAM_PLAYBACK}
  {}

  device(device const& d):
   device{d.name, d.type}
  {}

  device(device&& d) :
   device{}
  {
    swap(*this, d);
  }

	device(std::string const& device_name, snd_pcm_stream_t typ) : 
   handle{nullptr},
   name{device_name},
   type{typ}
  {
	  int err = snd_pcm_open(&handle, device_name.c_str(), typ, 0);
	  if(err < 0) {
	    // std::cerr << "cannot open audio device " << device_name << " " << snd_strerror(err) << std::endl;
      handle = nullptr;
    }
	}

	~device() {
    if(handle) {
		  snd_pcm_close(handle);
    }
	}

  operator bool() const {
    return handle != nullptr;
  } 

  operator snd_pcm_t*() const {
    if(!handle) std::cerr << "device \"" << name << "\" not initialized" << std::endl;
    return handle;
  }

  friend void swap(device& a, device& b) {
    std::swap(a.handle, b.handle);
    std::swap(a.name, b.name);
    std::swap(a.type, b.type);
  }

  device& operator=(device d) {
    swap(*this, d);
    return *this;
  }

	snd_pcm_t* handle;
  std::string name;
  snd_pcm_stream_t type;
};

#endif //DEVICE_HPP 
