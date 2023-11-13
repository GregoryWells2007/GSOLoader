#pragma once

#include <vector>

template <typename gso_list_type>
struct gso_vector_type {
private:
    std::vector<gso_list_type> value = {};
public:
    gso_vector_type() {}

    void clear() { value.clear(); }
    void add(gso_list_type val) { value.push_back(val); }
    int size() { return value.size(); }
    gso_list_type& operator[](int index) { return value[index]; } 
};
