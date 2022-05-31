#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T, typename U> class Functor {
  virtual U fmap(const function<T(T)>) const = 0;
};