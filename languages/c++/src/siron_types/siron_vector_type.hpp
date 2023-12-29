#pragma once

#include <vector>

template <typename siron_list_type>
struct siron_vector_type {
private:
    std::vector<siron_list_type> value = {};
public:
    siron_vector_type() {}

    void clear() { value.clear(); }
    void add(siron_list_type val) { value.push_back(val); }
    int size() { return value.size(); }
    siron_list_type& operator[](int index) { return value[index]; } 
};
