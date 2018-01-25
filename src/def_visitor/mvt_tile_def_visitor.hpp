#ifndef PYPP_GENERATED_MVT_TILE_DEF_VISITOR_HPP
#define PYPP_GENERATED_MVT_TILE_DEF_VISITOR_HPP

class mvt_tile_def_visitor :
    public boost::python::def_visitor<mvt_tile_def_visitor>

{
    friend class def_visitor_access;
public:
    template <class T>
    void visit(T &class_) const {
        class_
            .def("decode", &decode)
            ;
    }

    static boost::python::tuple decode(mvt_tile &self, std::string message) {
        bool was_compressed = false;
        bool ret = self.decode(message, was_compressed);
        return boost::python::make_tuple(ret, was_compressed);
    }

};

#endif  // PYPP_GENERATED_MVT_TILE_DEF_VISITOR_HPP
