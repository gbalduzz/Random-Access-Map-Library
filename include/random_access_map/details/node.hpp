// Copyright (C) 2020 ETH Zurich
// All rights reserved.
//
// See LICENSE for terms of usage.
//
// Author: Giovanni Balduzzi (gbalduzz@itp.phys.ethz.ch)
//
// Internal node for RandomAccessMap.

#pragma once

#include "color.hpp"

namespace ramlib {
namespace details {

template <class _Key, class _Value>
struct Node {
  using Key = _Key;
  using Value = _Value;

  Node(const Key& k, const Value& v, Node* p) : parent(p), data(k, v) {}

  Node* left = nullptr;
  Node* right = nullptr;
  Node* parent = nullptr;

  std::size_t subtree_size = 1;

  std::pair<Key, Value> data;

  Color color = RED;
};

}  // namespace details
}  // namespace ramlib
