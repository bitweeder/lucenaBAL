/*------------------------------------------------------------------------------

  Lucena Build Abstraction Library
  “DESTROYING_DELETE.cpp”
  Copyright © 2026 Lucena
  All Rights Reserved

  This file is distributed under the University of Illinois Open Source
  License. See LICENSE.md for details.

  Hard false-positive probe for `LBAL_CPP20_DESTROYING_DELETE`, from P0722R3.
  It only needs to compile; see `lbalFalsePositiveTest.cpp`.

------------------------------------------------------------------------------*/

//	lbal
#include <lucenaBAL/lucenaBAL.hpp>

#if LBAL_CPP20_DESTROYING_DELETE
  //	std
  #include <new>

namespace lbal_fp {

struct S {
  void
  operator delete (S* p, std::destroying_delete_t) {
    p->~S();
    ::operator delete (p);
  }
};

inline void
destroy(S* p) {
  delete p;
}

}  // namespace lbal_fp
#endif
