#include "utils/swerve/CANCoder.h"

using namespace hb;

S_CANCoder::S_CANCoder(const int& Id, const double& offset = 0) : CANCoder(Id), m_offset(offset), m_ID(Id) {
  printf("CANCoder: %i, reading %5.2f\n", Id, GetAbsolutePosition() - 180);
}

double S_CANCoder::Get() {
  
  double rv = GetAbsolutePosition() - m_offset;
    
  if (rv < 0.0) rv += 360.0;

  if (rv > 360.0) rv -= 360.0;

  double a = (std::numbers::pi * 2 * (rv / 360.0)) - (std::numbers::pi);

  return a;
}