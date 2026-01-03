#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;

// Your motors, sensors, etc. should go here.  Below are examples
inline pros::Motor belt_intake(-17, pros::v5::MotorGears::blue);
inline pros::Motor top_intake(16, pros::v5::MotorGears::blue);
inline ez::Piston piston_bottom('A', false);
inline ez::Piston piston_middle_intake('B', false); //true
inline ez::Piston piston_descore('C', false);
inline ez::Piston piston_descore_middle('D', false);
// inline ez::Piston piston_descore_updown('D', false);

inline pros::Distance back_distance_sensor(10);
inline pros::Distance right_distance_sensor(19);
inline pros::Distance left_distance_sensor(18);
inline double back_distance = 0.0;
inline double left_distance = 0.0;
inline double right_distance = 0.0;

// inline pros::Optical optical_intake(13);

// right_distance = right_distance_sensor.get_distance() / 25.4;

inline int DRIVE_SPEED = 110;
inline int TURN_SPEED = 90;
inline int SWING_SPEED = 110;
// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');

// inline bool alliance_color = true; // true is red
// inline bool color_flag = false;

// inline int detectColor() {
//     double hue = optical_intake.get_hue();
//     if (hue >= 330 || hue <= 30) {
//         if (alliance_color) {
//             return 1;
//         } else {
//             return -1;
//         }
//     } else if (hue >= 160 && hue <= 270) {
//         if (alliance_color) {
//             return -1;
//         } else {
//             return 1;
//         }
//     } else {
//         return 0;
//     }
// }