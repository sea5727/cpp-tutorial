
#pragma once

#include <string>

#include <map>

namespace fun {
// groupBy[K](f: (A) ⇒ K): Map[K, List[A]]
// 컨테이터 C의 모든 원소에 대해 f를 실행 후, 그 결과를 map으로 저장 및 반환
// C++14 이상 필요
template<typename C/*Container*/, typename F/*Discriminator*/>
auto groupBy(C&& c, F f) {
  using element_t       = std::decay_t<decltype(*std::data(c))>;
  using discriminator_t = decltype(f(*std::data(c)));
  std::map<discriminator_t, std::vector<element_t>> r;
  for (auto&& e : c)
    r[f(e)].emplace_back(e);
  return r;
}

// def map[B](f: (A) ⇒ B): Map[B]
template<typename C/*Associative container*/, typename F/*map*/>
auto map(C&& c, F f) {
  using new_key_t   = decltype(f(*std::begin(c)).first);
  using new_value_t = decltype(f(*std::begin(c)).second);
  std::map<new_key_t, new_value_t> r;
  for (auto&& e : c) {
    auto&& mapped = f(e);
    r[mapped.first] = mapped.second;
  }
  return r;
}
// template<typename C>
// auto reduce

}

namespace fun {

}
