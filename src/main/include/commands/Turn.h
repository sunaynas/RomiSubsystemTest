#pragma once
#include "subsystems/Drivetrain.h"
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

class Turner : public frc2::CommandHelper<frc2::CommandBase, Turner>
{
public:
    Turner(double angle, Drivetrain *drive)
        : m_drive(drive), m_turnGoal(angle)
    {
        AddRequirements({m_drive});
    }
    void Initialize() override;
    void Execute() override;
    void End(bool interrupted) override;
    bool IsFinished() override;
    /*
      void turnby(double xdegree);
      void dowork();
      bool areYouDone();
  */

private:
    Drivetrain *m_drive;
    double m_starting_angle;
    double m_turnGoal;
    bool m_jobStat;
};