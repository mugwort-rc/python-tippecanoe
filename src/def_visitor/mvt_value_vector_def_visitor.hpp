#ifndef MVT_VALUE_VECTOR_DEF_VISITOR_HPP
#define MVT_VALUE_VECTOR_DEF_VISITOR_HPP

class mvt_value_vector_def_visitor :
    public boost::python::def_visitor<mvt_value_vector_def_visitor>

{
    friend class def_visitor_access;
public:
    template <class T>
    void visit(T &class_) const {
        class_
            .def("to_list", &to_list)
            .def("to_string_list", &to_string_list)
            ;
    }

    static boost::python::list to_list(std::vector<mvt_value> &self) {
        boost::python::list result;
        for (auto &value : self) {
            switch (value.type) {
            case mvt_string:
                result.append(value.string_value);
                break;
            case mvt_int:
                result.append(value.numeric_value.int_value);
                break;
            case mvt_double:
                result.append(value.numeric_value.double_value);
                break;
            case mvt_float:
                result.append(value.numeric_value.float_value);
                break;
            case mvt_sint:
                result.append(value.numeric_value.sint_value);
                break;
            case mvt_uint:
                result.append(value.numeric_value.uint_value);
                break;
            case mvt_bool:
                result.append(value.numeric_value.bool_value);
                break;
            default:
                // None
                result.append(boost::python::object());
                break;
            }
        }
        return result;
    }

    static boost::python::list to_string_list(std::vector<mvt_value> &self) {
        boost::python::list result;
        for (auto &value : self) {
            result.append(value.toString());
        }
        return result;
    }

};

#endif  // MVT_VALUE_VECTOR_DEF_VISITOR_HPP
