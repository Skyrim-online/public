#pragma once

#include <vector>

#include "GeoPoint.h"
#include "Utility.h"

namespace GeoProc {
// A 3D Polygon
class GeoPolygon
{
  // Vertices of the 3D polygon
  std::vector<GeoPoint> _pts;

  // Indexes of Vertices
  std::vector<int> _idx;

  // Number of Vertices
  int _n;

public:
  GeoPolygon(void);

  ~GeoPolygon(void)
  {
    // free memory
    Utility::FreeVectorMemory(this->_pts);
    Utility::FreeVectorMemory(this->_idx);
  }

  GeoPolygon(std::vector<GeoPoint> pts)
  {
    this->_n = pts.size();

    for (int i = 0; i < _n; i++) {
      this->_pts.push_back(pts[i]);
      this->_idx.push_back(i);
    }
  }

  int GetN() { return this->_n; }

  std::vector<int> GetI() { return this->_idx; }

  std::vector<GeoPoint> GetV() { return this->_pts; }
};

}
