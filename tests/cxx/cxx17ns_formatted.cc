//===--- cxx17ns_formatted.cc - test input file for iwyu ------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// IWYU_ARGS: -Xiwyu --cxx17ns_formatted -std=c++17 -I .

#include "tests/cxx/cxx17ns-i1.h"

struct Two {
  Two(a::b::c::One& one);
  Two(a::b::One2& one);
  Two(a::One3& one);
  Two(a::One4& one);
};

/**** IWYU_SUMMARY

tests/cxx/cxx17ns_formatted.cc should add these lines:
namespace a { namespace { struct One4; } }
namespace a { struct One3; }
namespace a::b { struct One2; }
namespace a::b::c { struct One; }

tests/cxx/cxx17ns_formatted.cc should remove these lines:
- #include "tests/cxx/cxx17ns-i1.h"  // lines XX-XX

The full include-list for tests/cxx/cxx17ns_formatted.cc:

namespace a { namespace {
struct One4;
} }

namespace a {
struct One3;
}

namespace a::b {
struct One2;
}

namespace a::b::c {
struct One;
}

***** IWYU_SUMMARY */
