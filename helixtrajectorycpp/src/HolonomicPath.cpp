#include "HolonomicPath.h"

#include <iostream>
#include <vector>

#include "HolonomicWaypoint.h"
#include "Path.h"

namespace helixtrajectory {

    HolonomicPath::HolonomicPath(const std::vector<HolonomicWaypoint>& holonomicWaypoints)
        : holonomicWaypoints(holonomicWaypoints) {
    }

    HolonomicPath::~HolonomicPath() {
    }

    inline size_t HolonomicPath::Length() const noexcept {
        return holonomicWaypoints.size();
    }
    Waypoint& HolonomicPath::GetWaypoint(size_t index) {
        return holonomicWaypoints[index];
    }
    const Waypoint& HolonomicPath::GetWaypoint(size_t index) const {
        return holonomicWaypoints[index];
    }

    std::ostream& operator<<(std::ostream& stream, const HolonomicPath& path) {
        return stream << path.holonomicWaypoints;
    }
}