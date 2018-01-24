#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

#include "../../main.hpp"
#include "../../mvt.hpp"


extern void init_mvt_hpp();


// for `error: no match for ‘operator==’ (operand types are ‘mvt_feature’ and ‘const mvt_feature’)`
//   at init_vector_T<mvt_feature>("mvt_feature_vector");
bool operator ==(const mvt_feature &lhs, const mvt_feature &rhs) {
    return (
        lhs.tags == rhs.tags &&
        lhs.geometry == rhs.geometry &&
        lhs.type == rhs.type &&
        lhs.id == rhs.id &&
        lhs.has_id == rhs.has_id
    );
}
// for `error: no match for ‘operator==’ (operand types are ‘mvt_value’ and ‘const mvt_value’)`
//   at init_vector_T<mvt_value>("mvt_value_vector");
bool operator ==(const mvt_value &lhs, const mvt_value &rhs) {
    return (
        lhs.type == rhs.type &&
        lhs.string_value == rhs.string_value &&
        // note: numeric_value is union
        // see also mvt_value::mvt_value()
        // (because double_value is most longest bit-length variable)
        lhs.numeric_value.double_value == rhs.numeric_value.double_value
    );
}
// for `error: no match for ‘operator==’ (operand types are ‘mvt_layer’ and ‘const mvt_layer’)`
//   at init_vector_T<mvt_layer>("mvt_layer_vector");
bool operator ==(const mvt_layer &lhs, const mvt_layer &rhs) {
    return (
        lhs.version == rhs.version &&
        lhs.features == rhs.features &&
        lhs.keys == rhs.keys &&
        lhs.values == rhs.values &&
        lhs.extent == rhs.extent &&
        lhs.key_map == rhs.key_map &&
        lhs.value_map == rhs.value_map
    );
}


template <typename T>
boost::python::class_<std::vector<T>> init_vector_T(const char *name) {
    return boost::python::class_<std::vector<T>>(name)
        .def(boost::python::vector_indexing_suite<std::vector<T>>())
        ;
}


BOOST_PYTHON_MODULE(__tippecanoe) {
    init_mvt_hpp();

    // used at mvt_feature
    init_vector_T<unsigned>("unsigned_int_vector");
    init_vector_T<mvt_geometry>("mvt_geometry_vector");
    // used at mvt_layer
    init_vector_T<mvt_feature>("mvt_feature_vector");
    init_vector_T<std::string>("string_vector");
    init_vector_T<mvt_value>("mvt_value_vector");
    // used at mvt_tile
    init_vector_T<mvt_layer>("mvt_layer_vector");
}
