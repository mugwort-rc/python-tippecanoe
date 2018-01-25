#ifndef PYPP_GENERATED_MVT_VALUE_DEF_VISITOR_HPP
#define PYPP_GENERATED_MVT_VALUE_DEF_VISITOR_HPP

class mvt_value_def_visitor :
    public boost::python::def_visitor<mvt_value_def_visitor>

{
    friend class def_visitor_access;
public:
    template <class T>
    void visit(T &class_) const {
        class_
            ;
    }

};

#endif  // PYPP_GENERATED_MVT_VALUE_DEF_VISITOR_HPP