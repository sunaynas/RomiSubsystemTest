#include <units/math.h>
#include <wpi/numbers>
#include <fmt/format.h>
#include "commands/Turn.h"
#include "RobotContainer.h"
#include "subsystems/Drivetrain.h"
#include <units/math.h>

void Turner::Initialize()
{
    m_drive->ArcadeDrive(0, 0);
    m_drive->ResetEncoders();
    m_starting_angle = m_drive->GetGyroAngleZ();
    m_jobStat = false;
    fmt::print("Trun Initialized with {}\n", m_turnGoal);
}

// void Turner::turnby(double xdegree)
// {
//     // start at speed for 0.5 if error > 10degree
//     // slow down to 0.3 if error > 5degree
//     // slow down to 0.1 if error > 1degree
// }

void Turner::Execute()
{

    double errOfs = m_starting_angle + m_turnGoal - m_drive->GetGyroAngleZ();
    double speed = 0.5;
    m_jobStat = false;
    // fmt::print("erro offset is {}.", errOfs);
    const double errAllowed = 0.99;
    if (errOfs < 10)
    {
        if (errOfs > errAllowed)
        {
            speed = 0.25 + errOfs / 40;
        }
        else if (errOfs >= -errAllowed && errOfs <= errAllowed)
        {
            speed = 0;
            if (m_drive->GetGyroRateZ() > -0.1 &&
                m_drive->GetGyroRateZ() < 0.1)
            {
                m_jobStat = true;
            }
        }
        else if (errOfs > -10)
        {
            speed = -0.25;
        } else {
            speed = -0.5;
        }
    }
    // fmt::print("kAutoNameCustom2: {} {}\n", errOfs, speed);
    m_drive->ArcadeDrive(0.0, speed);
}

void Turner::End(bool interrupted)
{
    m_drive->ArcadeDrive(0, 0);
    double errOfs = m_starting_angle + m_turnGoal - m_drive->GetGyroAngleZ();
    fmt::print("Turn end with {} set and target err at {}\n",
               m_turnGoal, errOfs);
}

bool Turner::IsFinished()
{
    return m_jobStat;
}