#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "commands/Drive.h"
#include "commands/Turn.h"
#include "subsystems/Drivetrain.h"

class FirstAuto
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 FirstAuto> {
 public:
 FirstAuto(Drivetrain *drive) {
    AddCommands(
        Drive (0.5, 10_in, drive),
        Turner(88, drive),
        Drive (0.5, 10_in, drive),
        Turner(88, drive),
        Drive (0.5, 10_in, drive),
        Turner(88, drive),
        Drive (0.5, 10_in, drive),
        Turner(88, drive)
    );
  }
};