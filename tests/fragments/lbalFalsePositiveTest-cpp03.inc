/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “lbalFalsePositiveTest-cpp03.inc”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Soft false-positive probes for C++03 language tokens.

------------------------------------------------------------------------------*/

//	std
#include <stdexcept>
#include <string>
#include <typeinfo>

LBAL_FP_TEST(CPP03, EXCEPTIONS) {
  LBAL_FP_REQUIRE(LBAL_CPP03_EXCEPTIONS);
#if LBAL_CPP03_EXCEPTIONS
  bool caught = false;

  try {
    throw std::runtime_error("probe");
  } catch (const std::exception& e) {
    caught = (std::string(e.what()) == "probe");
  }

  EXPECT_TRUE(caught);
#endif
}

#if LBAL_CPP03_RTTI
namespace lbal_fp_cpp03 {

struct Base {
  virtual ~Base() = default;
};

struct Derived : Base { };

}  // namespace lbal_fp_cpp03
#endif

LBAL_FP_TEST(CPP03, RTTI) {
  LBAL_FP_REQUIRE(LBAL_CPP03_RTTI);
#if LBAL_CPP03_RTTI
  using namespace lbal_fp_cpp03;

  Derived d;
  Base& b = d;

  EXPECT_NE(dynamic_cast<Derived*>(&b), nullptr);
  EXPECT_TRUE(typeid(b) == typeid(Derived));
#endif
}
