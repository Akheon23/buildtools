// 2007-02-04  Edward Smith-Rowland <3dw4rd@verizon.net>
//
// Copyright (C) 2007-2013 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

//  riemann_zeta

// This can take long on simulators, timing out the test.
// { dg-options "-DMAX_ITERATIONS=5" { target simulator } }

#ifndef MAX_ITERATIONS
#define MAX_ITERATIONS (sizeof(data001) / sizeof(testcase_riemann_zeta<double>))
#endif

//  Compare against values generated by the GNU Scientific Library.
//  The GSL can be found on the web: http://www.gnu.org/software/gsl/

#include <tr1/cmath>
#if defined(__TEST_DEBUG)
#include <iostream>
#define VERIFY(A) \
if (!(A)) \
  { \
    std::cout << "line " << __LINE__ \
      << "  max_abs_frac = " << max_abs_frac \
      << std::endl; \
  }
#else
#include <testsuite_hooks.h>
#endif
#include "../testcase.h"


// Test data.
testcase_riemann_zeta<double> data001[] = {
  { 0.0000000000000000, -10.000000000000000 },
  { -0.0033669820451019579, -9.8000000000000007 },
  { -0.0058129517767319039, -9.5999999999999996 },
  { -0.0072908732290557004, -9.4000000000000004 },
  { -0.0078420910654484442, -9.1999999999999993 },
  { -0.0075757575757575803, -9.0000000000000000 },
  { -0.0066476555677551898, -8.8000000000000007 },
  { -0.0052400095350859429, -8.5999999999999996 },
  { -0.0035434308017674959, -8.4000000000000004 },
  { -0.0017417330388368585, -8.1999999999999993 },
  { 0.0000000000000000, -8.0000000000000000 },
  { 0.0015440036789213965, -7.7999999999999998 },
  { 0.0027852131086497423, -7.5999999999999996 },
  { 0.0036537321227995880, -7.4000000000000004 },
  { 0.0041147930817053468, -7.2000000000000002 },
  { 0.0041666666666666683, -7.0000000000000000 },
  { 0.0038369975032738366, -6.7999999999999998 },
  { 0.0031780270571782981, -6.5999999999999996 },
  { 0.0022611282027338573, -6.4000000000000004 },
  { 0.0011710237049390511, -6.2000000000000002 },
  { 0.0000000000000000, -6.0000000000000000 },
  { -0.0011576366649881879, -5.7999999999999998 },
  { -0.0022106784318564345, -5.5999999999999996 },
  { -0.0030755853460586891, -5.4000000000000004 },
  { -0.0036804380477934787, -5.2000000000000002 },
  { -0.0039682539682539698, -5.0000000000000000 },
  { -0.0038996891301999797, -4.7999999999999998 },
  { -0.0034551830834302711, -4.5999999999999996 },
  { -0.0026366345018725115, -4.4000000000000004 },
  { -0.0014687209305056974, -4.2000000000000002 },
  { 0.0000000000000000, -4.0000000000000000 },
  { 0.0016960463875825209, -3.7999999999999998 },
  { 0.0035198355903356747, -3.5999999999999996 },
  { 0.0053441503206513421, -3.4000000000000004 },
  { 0.0070119720770910540, -3.2000000000000002 },
  { 0.0083333333333333350, -3.0000000000000000 },
  { 0.0090807294856852811, -2.7999999999999998 },
  { 0.0089824623788396681, -2.5999999999999996 },
  { 0.0077130239874243630, -2.4000000000000004 },
  { 0.0048792123593036068, -2.2000000000000002 },
  { 0.0000000000000000, -2.0000000000000000 },
  { -0.0075229347765968010, -1.8000000000000007 },
  { -0.018448986678963775, -1.5999999999999996 },
  { -0.033764987694047593, -1.4000000000000004 },
  { -0.054788441243880631, -1.1999999999999993 },
  { -0.083333333333333398, -1.0000000000000000 },
  { -0.12198707766977103, -0.80000000000000071 },
  { -0.17459571193801401, -0.59999999999999964 },
  { -0.24716546083171492, -0.40000000000000036 },
  { -0.34966628059831484, -0.19999999999999929 },
  { -0.49999999999999994, 0.0000000000000000 },
  { -0.73392092489633953, 0.19999999999999929 },
  { -1.1347977838669825, 0.40000000000000036 },
  { -1.9526614482239983, 0.59999999999999964 },
  { -4.4375384158955677, 0.80000000000000071 },
};

// Test function.
template <typename Tp>
void test001()
{
  const Tp eps = std::numeric_limits<Tp>::epsilon();
  Tp max_abs_diff = -Tp(1);
  Tp max_abs_frac = -Tp(1);
  unsigned int num_datum = MAX_ITERATIONS;
  for (unsigned int i = 0; i < num_datum; ++i)
    {
      const Tp f = std::tr1::riemann_zeta(Tp(data001[i].x));
      const Tp f0 = data001[i].f0;
      const Tp diff = f - f0;
      if (std::abs(diff) > max_abs_diff)
        max_abs_diff = std::abs(diff);
      if (std::abs(f0) > Tp(10) * eps
       && std::abs(f) > Tp(10) * eps)
        {
          const Tp frac = diff / f0;
          if (std::abs(frac) > max_abs_frac)
            max_abs_frac = std::abs(frac);
        }
    }
  VERIFY(max_abs_frac < Tp(5.0000000000000039e-13));
}

int main(int, char**)
{
  test001<double>();
  return 0;
}
