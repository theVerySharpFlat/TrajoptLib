// Copyright (c) TrajoptLib contributors

#pragma once

#include <optional>

#include "trajopt/SymbolExports.h"
#include "trajopt/set/IntervalSet1d.h"
#include "trajopt/set/RectangularSet2d.h"
#include "trajopt/solution/SolutionChecking.h"

namespace trajopt {

/**
 * Linear 2D set.
 */
struct TRAJOPT_DLLEXPORT LinearSet2d {
  /// FIXME What does this do?
  double theta;

  /**
   * FIXME What does this do?
   *
   * @param xComp The x coordinate.
   * @param yComp The y coordinate.
   * @param tolerances The tolerances considered to satisfy the constraint.
   */
  std::optional<SolutionError> CheckVector(
      double xComp, double yComp,
      const SolutionTolerances& tolerances) const noexcept;

  /**
   * FIXME What does this do?
   *
   * @param theta FIXME What does this do?
   * @param rBound FIXME What does this do?
   */
  static RectangularSet2d RBoundToRectangular(double theta,
                                              const IntervalSet1d& rBound);
};

}  // namespace trajopt
