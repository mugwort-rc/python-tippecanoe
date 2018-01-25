// generate by pypp
// original source code: ../../mvt.hpp

#include "../../mvt.hpp"

#include <boost/python.hpp>


#include "def_visitor/mvt_geometry_def_visitor.hpp"
#include "def_visitor/mvt_feature_def_visitor.hpp"
#include "def_visitor/mvt_value_def_visitor.hpp"
#include "def_visitor/mvt_layer_def_visitor.hpp"
#include "def_visitor/mvt_tile_def_visitor.hpp"


void init_mvt_hpp() {
    boost::python::class_<mvt_geometry, std::shared_ptr<mvt_geometry>>("mvt_geometry", boost::python::init<int, long long, long long>())
        .def(mvt_geometry_def_visitor())
        .def("__lt__", &mvt_geometry::operator<)
        .def("__eq__", &mvt_geometry::operator==)
        .def_readwrite("x", &mvt_geometry::x)
        .def_readwrite("y", &mvt_geometry::y)
        .def_readwrite("op", &mvt_geometry::op)
        ;
    boost::python::class_<mvt_feature, std::shared_ptr<mvt_feature>>("mvt_feature")
        .def(mvt_feature_def_visitor())
        .def_readwrite("tags", &mvt_feature::tags)
        .def_readwrite("geometry", &mvt_feature::geometry)
        .def_readwrite("type", &mvt_feature::type)
        .def_readwrite("id", &mvt_feature::id)
        .def_readwrite("has_id", &mvt_feature::has_id)
        ;
    boost::python::class_<mvt_value, std::shared_ptr<mvt_value>>("mvt_value")
        .def(mvt_value_def_visitor())
        .def("__lt__", &mvt_value::operator<)
        .def("toString", &mvt_value::toString)
        .def_readwrite("type", &mvt_value::type)
        .def_readwrite("string_value", &mvt_value::string_value)
        .def_readwrite("numeric_value", &mvt_value::numeric_value)
        ;
    boost::python::class_<mvt_layer, std::shared_ptr<mvt_layer>>("mvt_layer")
        .def(mvt_layer_def_visitor())
        .def("tag", &mvt_layer::tag)
        .def_readwrite("version", &mvt_layer::version)
        .def_readwrite("name", &mvt_layer::name)
        .def_readwrite("features", &mvt_layer::features)
        .def_readwrite("keys", &mvt_layer::keys)
        .def_readwrite("values", &mvt_layer::values)
        .def_readwrite("extent", &mvt_layer::extent)
        .def_readwrite("key_map", &mvt_layer::key_map)
        .def_readwrite("value_map", &mvt_layer::value_map)
        ;
    boost::python::class_<mvt_tile, std::shared_ptr<mvt_tile>>("mvt_tile")
        .def(mvt_tile_def_visitor())
        .def("encode", &mvt_tile::encode)
        .def("decode", &mvt_tile::decode)
        .def_readwrite("layers", &mvt_tile::layers)
        ;
    boost::python::def("is_compressed", &is_compressed);
    boost::python::def("decompress", &decompress);
    boost::python::def("compress", &compress);
    //boost::python::def("dezig", &dezig);
    boost::python::def("stringified_to_mvt_value", &stringified_to_mvt_value);
    boost::python::def("is_integer", &is_integer);
    boost::python::def("is_unsigned_integer", &is_unsigned_integer);
    boost::python::enum_<mvt_operation>("mvt_operation")
        .value("mvt_moveto", mvt_moveto)
        .value("mvt_lineto", mvt_lineto)
        .value("mvt_closepath", mvt_closepath)
        .export_values()
        ;
    boost::python::enum_<mvt_geometry_type>("mvt_geometry_type")
        .value("mvt_point", mvt_point)
        .value("mvt_linestring", mvt_linestring)
        .value("mvt_polygon", mvt_polygon)
        .export_values()
        ;
    boost::python::enum_<mvt_value_type>("mvt_value_type")
        .value("mvt_string", mvt_string)
        .value("mvt_float", mvt_float)
        .value("mvt_double", mvt_double)
        .value("mvt_int", mvt_int)
        .value("mvt_uint", mvt_uint)
        .value("mvt_sint", mvt_sint)
        .value("mvt_bool", mvt_bool)
        .value("mvt_null", mvt_null)
        .export_values()
        ;
}
