// Copyright (c) TrajoptLib contributors

#include "trajopt/constraint/TranslationConstraint.h"

#include <optional>

#include <fmt/format.h>

#include "trajopt/set/Set2d.h"
#include "trajopt/solution/SolutionChecking.h"

namespace trajopt {

std::optional<SolutionError> TranslationConstraint::CheckTranslation(
    double x, double y, const SolutionTolerances& tolerances) const noexcept {
  auto check = CheckVector(translationBound, x, y, tolerances);
  if (check.has_value()) {
    return SolutionError{
        fmt::format("translation = (x, y) = ({}, {}): x-component: ", x, y,
                    check->errorMessage)};
  }
  return std::nullopt;
}
}  // namespace trajopt
