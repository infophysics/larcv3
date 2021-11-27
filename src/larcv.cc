#include "base.hh"
#include "dataformat.hh"
#include "processor.hh"
#include "queueio.hh"

PYBIND11_MAKE_OPAQUE(std::vector<larcv3::SparseTensor<2> >);
PYBIND11_MAKE_OPAQUE(std::vector<larcv3::SparseTensor<3> >);
PYBIND11_MAKE_OPAQUE(std::vector<larcv3::Tensor      <1> >);
PYBIND11_MAKE_OPAQUE(std::vector<larcv3::Tensor      <2> >);
PYBIND11_MAKE_OPAQUE(std::vector<larcv3::Tensor      <3> >);
PYBIND11_MAKE_OPAQUE(std::vector<larcv3::Tensor      <4> >);

PYBIND11_MAKE_OPAQUE(std::vector<larcv3::ImageMeta   <1> >);
PYBIND11_MAKE_OPAQUE(std::vector<larcv3::ImageMeta   <2> >);
PYBIND11_MAKE_OPAQUE(std::vector<larcv3::ImageMeta   <3> >);
PYBIND11_MAKE_OPAQUE(std::vector<larcv3::ImageMeta   <4> >);

PYBIND11_MODULE(pylarcv, m) {
  init_base(m);
  init_dataformat(m);
  init_processor(m);
  init_queueio(m);
}