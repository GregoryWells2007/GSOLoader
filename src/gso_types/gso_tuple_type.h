#pragma once

// modifed this tuple implementation
// Link: https://stackoverflow.com/questions/4041447/how-is-stdtuple-implemented

template <int i, typename Item>
struct gso_tuple_leaf {
    Item value;

    gso_tuple_leaf(Item v) {
        value = v;
    }
};  

template<int i, typename... TailItems>
struct gso_tuple_definition;

template<int i>
struct gso_tuple_definition<i> {};

template<int i, typename HeadItem>
struct gso_tuple_definition<i, HeadItem> {
    gso_tuple_leaf<i, HeadItem> value;

    HeadItem get(int index) {
        return value.value;
    }

    void set(int index, HeadItem value_to_set) {
        value.value = value_to_set;
    }

    gso_tuple_definition(HeadItem v) :
        value(v) {}
};


template<int i, typename HeadItem, typename... TailItems>
struct gso_tuple_definition<i, HeadItem, TailItems...> {
    gso_tuple_leaf<i, HeadItem> value;
    gso_tuple_definition<i + 1, TailItems...> values;

    gso_tuple_definition(HeadItem v, TailItems... v2) :
        value(v), values(v2...) {}
    
    HeadItem get(int index) {
        if (index == i) return value.value;
        else return values.get(index);
    }

    void set(int index, HeadItem value_to_set) {
        if (index == i) value.value = value_to_set;
        else values.set(index, value_to_set);
    }
};

template<typename... Items>
using gso_tuple_type = gso_tuple_definition<0, Items...>;