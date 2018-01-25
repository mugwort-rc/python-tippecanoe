#ifndef VECTOR_DEF_VISITOR_HPP
#define VECTOR_DEF_VISITOR_HPP

template <class V>
class vector_def_visitor :
    public boost::python::def_visitor<vector_def_visitor<V>>

{
    friend class def_visitor_access;
public:
    template <class T>
    void visit(T &class_) const {
        class_
            .def("tolist", &to_list)
            ;
    }

    static boost::python::list to_list(std::vector<V> &self) {
        boost::python::list result;
        for (auto &value : self) {
            result.append(value);
        }
        return result;
    }

};

#endif  // MVT_VALUE_VECTOR_DEF_VISITOR_HPP
