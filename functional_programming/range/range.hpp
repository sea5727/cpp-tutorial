
#pragma once


template<typename T>
class range_iterator{
    T cur_;
    const T step_ = 1;
public:
    range_iterator(T init) : cur_{init} {}

    range_iterator & operator++(){
        cur_ += step_;
        return *this;
    }
    bool operator!=(const range_iterator<T> &rhs) const {
        return cur_ != rhs.cur_;
    }
    T operator*() const {
        return cur_;
    }

};

template<typename T>
class range_impl{
    const T start_;
    const T stop_;

public:
    range_impl(T start, T stop) :
        start_{start}, stop_{stop} {}
    range_iterator<T> begin() const {
        return range_iterator<T>{start_};
    }
    range_iterator<T> end() const {
        return range_iterator<T>{stop_};
    }

};


template<typename T>
range_impl<T> range(const T start, const T end) {
    return range_impl<T>{start, end};
}


