#pragma once

// modifed this tuple implementation
// Link: https://stackoverflow.com/questions/4041447/how-is-stdtuple-implemented


template <typename T, typename... Ts>
struct siron_tuple_definition {
    siron_tuple_definition(const T& t, const Ts&... ts)
        : value(t)
        , rest(ts...)
    {
    }

    constexpr int size() const { return 1 + rest.size(); }

    T value;
    siron_tuple_definition<Ts...> rest;
};
template <typename T>
struct siron_tuple_definition<T> {
    siron_tuple_definition(const T& t)
        : value(t)
    {
    }

    constexpr int size() const { return 1; }

    T value;
};

template <size_t i, typename T, typename... Ts>
struct nthType : nthType<i-1, Ts...> {
    static_assert(i < sizeof...(Ts) + 1, "index out of bounds");
};

template <typename T, typename... Ts>
struct nthType<0, T, Ts...> { T value; };

template <size_t i>
struct getter {
    template <typename... Ts>
    static decltype(nthType<i, Ts...>::value)& get(siron_tuple_definition<Ts...>& t) {
        return getter<i-1>::get(t.rest);
    }
};
template <>
struct getter<0> {
    template <typename T, typename... Ts>
    static T& get(siron_tuple_definition<T, Ts...>& t) {
        return t.value;
    }
};

template <size_t i, typename... Ts>
decltype(nthType<i, Ts...>::value)& tuple_get(siron_tuple_definition<Ts...>& t) {
    return getter<i>::get(t);
}

template<typename... Items>
using siron_tuple_type = siron_tuple_definition<Items...>;