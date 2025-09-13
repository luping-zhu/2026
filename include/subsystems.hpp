#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;

// Your motors, sensors, etc. should go here.  Below are examples
inline pros::Motor belt_intake(17, pros::v5::MotorGears::blue);
inline pros::Motor top_intake(16, pros::v5::MotorGears::blue);
inline ez::Piston piston_bottom('A', false);
inline ez::Piston piston_middle_intake('B', false ); //true

inline int DRIVE_SPEED = 100;
inline int TURN_SPEED = 70;
inline int SWING_SPEED = 110;
// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');