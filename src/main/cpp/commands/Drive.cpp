
#include "commands/Drive.h"

#include <units/math.h>

void Drive::Initialize() {
  m_drive->ArcadeDrive(0, 0);
  m_drive->ResetEncoders();
}

void Drive::Execute() {
  m_drive->ArcadeDrive(m_speed, 0);
}

void Drive::End(bool interrupted) {
  m_drive->ArcadeDrive(0, 0);
}

bool Drive::IsFinished() {
  return units::math::abs(m_drive->GetAverageDistance()) >= m_distance;
}