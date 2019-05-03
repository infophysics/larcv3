#ifndef __LARCV_VERTEX_H__
#define __LARCV_VERTEX_H__

#include "DataFormatTypes.h"
#include "Point.h"

namespace larcv3 {

  class Vertex {
  public:
    /// Particle ID default constructor
    Vertex() = default;
    Vertex(double x, double y, double z, double t);

    /// Reset function
    void reset();

    /// Reset function for x, y, z, t
    void reset(double x, double y, double z, double t);

    /// Convert to point
    const larcv3::Point2D as_point2d(larcv3::PointType_t point_type) const;
    const larcv3::Point3D as_point3d() const;
    void as_point(larcv3::PointType_t point_type, double * x, double * y, double * z);

    inline double x() const { return _x; }
    inline double y() const { return _y; }
    inline double z() const { return _z; }
    inline double t() const { return _t; }

    /// Default destructor
    // The virtual destructor must be removed to make the data layout standard in C++ specifications
    // virtual ~Vertex(){};

    inline bool operator== (const Vertex& rhs) const
    {
      return ( _x == rhs._x && _y == rhs._y && _z == rhs._z && _t == rhs._t );
    }

    inline bool operator!= (const Vertex& rhs) const
    {
      return !((*this) == rhs);
    }

    inline bool operator< (const Vertex& rhs) const
    {
      if( _x     < rhs._x ) return true;
      if( rhs._x < _x     ) return false;
      if( _y     < rhs._y ) return true;
      if( rhs._y < _y     ) return false;
      if( _z     < rhs._z ) return true;
      if( rhs._z < _z     ) return false;
      if( _t     < rhs._t ) return true;
      if( rhs._t < _t     ) return false;

      return false;
    }

    std::string dump() const;
    
  private:

    double _x, _y, _z, _t;

    // What does this function do?
    // void approx();

#ifndef SWIG
  public: 
    static H5::CompType get_datatype() {
      H5::CompType datatype(sizeof(Vertex));
      datatype.insertMember("x", offsetof(Vertex, _x), larcv3::get_datatype<double>());
      datatype.insertMember("y", offsetof(Vertex, _y), larcv3::get_datatype<double>());
      datatype.insertMember("z", offsetof(Vertex, _z), larcv3::get_datatype<double>());
      datatype.insertMember("t", offsetof(Vertex, _t), larcv3::get_datatype<double>());
      return datatype;
    }
#endif
    

  };
}

#endif