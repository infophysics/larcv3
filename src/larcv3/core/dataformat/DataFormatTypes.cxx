#ifndef __LARCV3DATAFORMAT_DATAFORMATTYPES_CXX
#define __LARCV3DATAFORMAT_DATAFORMATTYPES_CXX

#include "larcv3/core/dataformat/DataFormatTypes.h"

#ifndef SWIG

namespace larcv3{

  template<>
  H5::DataType get_datatype<int>()                {return H5::PredType::NATIVE_INT;}

  template<>
  H5::DataType get_datatype<bool>()               {return H5::PredType::NATIVE_HBOOL;}

  template<>
  H5::DataType get_datatype<float>()              {return H5::PredType::NATIVE_FLOAT;}

  template<>
  H5::DataType get_datatype<double>()             {return H5::PredType::NATIVE_DOUBLE;}

  template<>
  H5::DataType get_datatype<unsigned short>()     {return H5::PredType::NATIVE_USHORT;}

  template<>
  H5::DataType get_datatype<unsigned int>()       {return H5::PredType::NATIVE_UINT;}

  template<>
  H5::DataType get_datatype<short>()              {return H5::PredType::NATIVE_SHORT;}

  template<>
  H5::DataType get_datatype<unsigned long long>() {return H5::PredType::NATIVE_ULLONG;}
  
  template<>
  H5::DataType get_datatype<size_t>()             {return H5::PredType::NATIVE_HSIZE;}

  template<>
  H5::DataType get_datatype<ShapeType_t>()        {return get_datatype<int>();}

  template<>
  H5::DataType get_datatype<long>()               {return H5::PredType::NATIVE_LONG;}


  template<>
  H5::DataType get_datatype<Extents_t>()          {
    H5::CompType datatype(sizeof(Extents_t));
    datatype.insertMember("first", offsetof(struct Extents_t, first), get_datatype<unsigned int>());
    datatype.insertMember("N",     offsetof(struct Extents_t, n),     get_datatype<unsigned int>());
    return datatype;
  }

  template<>
  H5::DataType get_datatype<IDExtents_t>()          {
    H5::CompType datatype(sizeof(IDExtents_t));
    datatype.insertMember("first", offsetof(struct IDExtents_t, first), get_datatype<unsigned int>());
    datatype.insertMember("ID",    offsetof(struct IDExtents_t, id),    get_datatype<unsigned int>());
    datatype.insertMember("N",     offsetof(struct IDExtents_t, n),     get_datatype<unsigned int>());
    return datatype;
  }


}

#endif // swig


#endif
