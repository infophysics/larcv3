#include "EmptyImageFilter.hh"
#include "EventTensor.hh"
namespace larcv3 {

  static EmptyImageFilterProcessFactory __global_EmptyImageFilterProcessFactory__;

  EmptyImageFilter::EmptyImageFilter(const std::string name)
    : ProcessBase(name)
  {}
    
  void EmptyImageFilter::configure(const PSet& cfg)
  {
    _image_producer = cfg.get<std::string>("ImageProducer");
  }

  void EmptyImageFilter::initialize()
  {}

  bool EmptyImageFilter::process(IOManager& mgr)
  {
    auto const& ev_image = mgr.get_data<larcv3::EventTensor2D>(_image_producer);
    if(ev_image.image2d_array().empty()) return false;
    return true;
  }

  void EmptyImageFilter::finalize()
  {}

}

