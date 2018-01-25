#ifndef PYPP_GENERATED_MVT_LAYER_DEF_VISITOR_HPP
#define PYPP_GENERATED_MVT_LAYER_DEF_VISITOR_HPP

class mvt_layer_def_visitor :
    public boost::python::def_visitor<mvt_layer_def_visitor>

{
    friend class def_visitor_access;
public:
    template <class T>
    void visit(T &class_) const {
        class_
            .def("dump", &to_dict)
            ;
    }

    static boost::python::dict to_dict(mvt_layer &self) {
        boost::python::dict result;
        result["version"] = self.version;
        result["name"] = self.name;
        result["extent"] = self.extent;
        boost::python::list keys;
        for (const auto &key : self.keys) {
            keys.append(key);
        }
        result["keys"] = keys;
        result["values_size"] = self.values.size();
        result["features_size"] = self.features.size();
        return result;
    }

};

#endif  // PYPP_GENERATED_MVT_LAYER_DEF_VISITOR_HPP
