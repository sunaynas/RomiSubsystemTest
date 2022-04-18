
#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <units/length.h>

#include "subsystems/Drivetrain.h"

class Drive
    : public frc2::CommandHelper<frc2::CommandBase, Drive> {
 public:
  Drive(double speed, units::meter_t distance, Drivetrain* drive)
      : m_speed(speed), m_distance(distance), m_drive(drive) {
    AddRequirements({m_drive});
  }

  void Initialize() override;
  void Execute() override;
  void End(bool interrupted) override;
  bool IsFinished() override;

 private:
  double m_speed;
  units::meter_t m_distance;
  Drivetrain* m_drive;
};
