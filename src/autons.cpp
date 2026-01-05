#include "main.h"

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// These are out of 127
//
///
// Constants
///

void new_constants()
{
  // P, I, D, and Start I
  chassis.pid_drive_constants_set(6.0, 0.0, 21.0);          // 4.1, 0.0, 0.0        // Fwd/rev constants, used for odom and non odom motions
  chassis.pid_heading_constants_set(12.7, 0.0, 50.0);       // 2nd version: 9.9, 0.0, 20.0      // Holds the robot straight while going forward without odom
  chassis.pid_turn_constants_set(2.8, 100.0, 20.25, 0.0);   // 3.0,0.0,20.0,0.0    // Turn in place constants
  chassis.pid_swing_constants_set(6.0, 0.0, 50.0);          // 6.0,0.0,65.0       // Swing constants
  chassis.pid_odom_angular_constants_set(6.5, 0.0, 52.5);   // Angular control for odom motions
  chassis.pid_odom_boomerang_constants_set(5.8, 0.0, 32.5); // Angular control for boomerang motions

  // Exit conditions
  chassis.pid_turn_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_swing_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 500_ms, 500_ms);
  chassis.pid_odom_turn_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 750_ms);
  chassis.pid_odom_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 500_ms, 750_ms);
  chassis.pid_turn_chain_constant_set(3_deg);
  chassis.pid_swing_chain_constant_set(5_deg);
  chassis.pid_drive_chain_constant_set(3_in);

  // Slew constants
  chassis.slew_turn_constants_set(3_deg, 50);
  chassis.slew_drive_constants_set(3_in, 50);
  chassis.slew_swing_constants_set(3_in, 50);

  // The amount that turns are prioritized over driving in odom motions
  // - if you have tracking wheels, you can run this higher.  1.0 is the max
  chassis.odom_turn_bias_set(0.9);

  chassis.odom_look_ahead_set(7_in);          // This is how far ahead in the path the robot looks at
  chassis.odom_boomerang_distance_set(16_in); // This sets the maximum distance away from target that the carrot point can be
  chassis.odom_boomerang_dlead_set(0.625);    // This handles how aggressive the end of boomerang motions are

  chassis.pid_angle_behavior_set(ez::shortest); // Changes the default behavior for turning, this defaults it to the shortest path there
}

void pid_thing()
{
  //// The first parameter is ez::LEFT_SWING or ez::RIGHT_SWING
  //// The second parameter is the target in degrees
  //// The third parameter is the speed of the moving side of the drive
  //// The fourth parameter is the speed of the still side of the drive, this allows for wider arcs

  //// chassis.drive_angle_set(180);
  //// chassis.pid_swing_set(ez::LEFT_SWING, -28_deg, SWING_SPEED, 0);
  //// chassis.pid_wait();

  // new_constants();
  // chassis.pid_drive_set(-72_in, DRIVE_SPEED, true);
  // chassis.pid_wait();

  // chassis.pid_swing_constants_set(6.0, 0.0, 50.0);
  // // chassis.pid_swing_set(ez::LEFT_SWING, -90_deg, SWING_SPEED, 0);
  // // chassis.pid_wait();

  // piston_middle_intake.set(true);
  // DRIVE_SPEED = 110;
  // belt_intake.move(180);
  // chassis.pid_drive_set(12_in, DRIVE_SPEED, true);
  // chassis.pid_wait_quick_chain();
  // chassis.pid_turn_set(33_deg, TURN_SPEED);
  // chassis.pid_wait();
  // chassis.pid_drive_set(17.5_in, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // chassis.pid_turn_set(135_deg, TURN_SPEED);
  // chassis.pid_wait_quick_chain();
  // chassis.pid_drive_set(34.4_in, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // chassis.pid_turn_set(180_deg, TURN_SPEED);
  // chassis.pid_wait_quick_chain();
  // chassis.pid_drive_set(-25_in, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // top_intake.move(-180);
  // pros::delay(1200);
  // top_intake.move(0);
  // //CODE FOR DESCORING IN 15 SECOND AUTO AFTER SCORING ONTO LONG GOAL
  // chassis.drive_angle_set(90);
  // chassis.pid_swing_set(ez::RIGHT_SWING, 60_deg, SWING_SPEED, 30);
  // chassis.pid_wait();
  // chassis.pid_turn_set(150_deg, TURN_SPEED);
  // chassis.pid_wait();
  // chassis.pid_swing_set(ez::LEFT_SWING, 90_deg, SWING_SPEED, 26);
  // chassis.pid_wait();
  // DRIVE_SPEED = 90;
  // chassis.pid_drive_set(-21_in, DRIVE_SPEED, true);
  // chassis.pid_wait();

  // clearing the parking zone and intaking at the same time at the start of auto skill
  // chassis.drive_angle_set(1);

  { // auto skill with cleanup parking zone with front at the start
    /*
    DRIVE_SPEED = 90;
    TURN_SPEED = 90;
    belt_intake.move(180);
    piston_middle_intake.set(true);
    // chassis.pid_drive_set(-10_in, DRIVE_SPEED);
    // chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(58_in, DRIVE_SPEED, true);
    chassis.pid_wait_quick_chain();
    chassis.pid_turn_set(90_deg, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    back_distance = back_distance_sensor.get_distance() / 25.4;
    DRIVE_SPEED = 110;
    chassis.pid_drive_set(30 - back_distance, DRIVE_SPEED, true);
    chassis.pid_wait();
    chassis.pid_turn_set(180_deg, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    back_distance = back_distance_sensor.get_distance() / 25.4;
    chassis.pid_drive_set(-(back_distance - 17.5), DRIVE_SPEED);
    chassis.pid_wait();

    chassis.pid_turn_set(-90_deg, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(-11_in, DRIVE_SPEED);
    // chassis.pid_wait_quick_chain();
    chassis.pid_wait_quick();
    // chassis.pid_turn_set(-90_deg, TURN_SPEED);
    // chassis.pid_wait_quick_chain();
    belt_intake.move(180);
    top_intake.move(-180);
    piston_bottom.set(true);
    pros::delay(2100);
    top_intake.move(0);
    chassis.pid_turn_set(-92.5_deg, TURN_SPEED);
    chassis.pid_drive_set(32.8_in, DRIVE_SPEED, true);
    chassis.pid_wait();

    pros::delay(1100);
    chassis.pid_turn_set(-90_deg, TURN_SPEED); // 90
    chassis.pid_wait();
    chassis.pid_drive_set(-16_in, DRIVE_SPEED, true);
    chassis.pid_wait();
    piston_bottom.set(false);
    chassis.pid_turn_set(180_deg, TURN_SPEED); // 0
    chassis.pid_wait();

    back_distance = back_distance_sensor.get_distance() / 25.4;
    chassis.pid_drive_set(30.3 - back_distance, DRIVE_SPEED, true); // 12.8
    chassis.pid_wait();
    chassis.pid_turn_set(-90_deg, TURN_SPEED); // 90
    chassis.pid_wait();

    chassis.pid_drive_set(-80_in, DRIVE_SPEED, true);
    chassis.pid_wait();
    DRIVE_SPEED = 95;

    chassis.pid_turn_set(180_deg, TURN_SPEED); // 0
    chassis.pid_wait();
    left_distance = left_distance_sensor.get_distance() / 25.4;
    back_distance = back_distance_sensor.get_distance() / 25.4;
    chassis.pid_drive_set(-(back_distance - 17.1), DRIVE_SPEED, true); // 17.6
    chassis.pid_wait();
    chassis.pid_turn_set(90_deg, TURN_SPEED); //-90
    chassis.pid_wait();
    chassis.pid_drive_set(-(40 - left_distance), DRIVE_SPEED, true);
    chassis.pid_wait_quick_chain(); // chassis.pid_wait()
    top_intake.move(-180);
    pros::delay(3000); ////3500
    top_intake.move(0);

    chassis.pid_turn_set(91.5_deg, TURN_SPEED); //-88.5
    chassis.pid_wait();

    belt_intake.move(180);
    piston_bottom.set(true);
    chassis.pid_drive_set(32.8_in, DRIVE_SPEED, true);
    chassis.pid_wait();
    pros::delay(1100);
    chassis.pid_turn_set(91.5_deg, TURN_SPEED); //-88.5
    chassis.pid_wait();
    chassis.pid_drive_set(-32_in, DRIVE_SPEED, true);
    chassis.pid_wait_quick_chain(); // pidwait
    top_intake.move(-180);
    piston_bottom.set(false);
    pros::delay(3000);
    top_intake.move(0);

    chassis.pid_drive_set(12.5_in, DRIVE_SPEED, true);
    chassis.pid_wait();
    chassis.pid_turn_set(0_deg, TURN_SPEED); // 180
    chassis.pid_wait();
    chassis.pid_drive_set(-78_in, DRIVE_SPEED, true);
    chassis.pid_wait();
    right_distance = right_distance_sensor.get_distance() / 25.4;
    back_distance = back_distance_sensor.get_distance() / 25.4;
    chassis.pid_drive_set(-(back_distance - 16), DRIVE_SPEED, true);
    chassis.pid_wait();
    chassis.pid_turn_set(90_deg, DRIVE_SPEED, true); //-90
    chassis.pid_wait();

    piston_bottom.set(true);
    chassis.pid_drive_set(right_distance - 5, DRIVE_SPEED, true);
    chassis.pid_wait();
    pros::delay(1100);

    chassis.pid_turn_set(90_deg, TURN_SPEED); //-90
    chassis.pid_wait();
    chassis.pid_drive_set(-16_in, DRIVE_SPEED, true);
    chassis.pid_wait();
    piston_bottom.set(false);
    chassis.pid_turn_set(180_deg, TURN_SPEED); // 0
    chassis.pid_wait();

    chassis.pid_drive_set(-12.8_in, DRIVE_SPEED, true);
    chassis.pid_wait();
    chassis.pid_turn_set(90_deg, TURN_SPEED); //-90
    chassis.pid_wait();

    chassis.pid_drive_set(-80_in, DRIVE_SPEED, true);
    chassis.pid_wait();
    // DRIVE_SPEED = 95;
    chassis.pid_turn_set(0_deg, TURN_SPEED); // 180
    chassis.pid_wait();
    left_distance = left_distance_sensor.get_distance() / 25.4;
    back_distance = back_distance_sensor.get_distance() / 25.4;
    piston_middle_intake.set(true);
    chassis.pid_drive_set(-(back_distance - 16.5), DRIVE_SPEED, true);
    chassis.pid_wait();
    chassis.pid_turn_set(-90_deg, TURN_SPEED); // 90
    chassis.pid_wait();
    chassis.pid_drive_set(-(40 - left_distance), DRIVE_SPEED, true);
    chassis.pid_wait_quick_chain(); // pidwait
    top_intake.move(-180);
    pros::delay(3000);
    top_intake.move(0);
    chassis.pid_turn_set(-88_deg, TURN_SPEED); // 92
    chassis.pid_wait();

    piston_bottom.set(true);
    chassis.pid_drive_set(32_in, DRIVE_SPEED, true); ////32.8
    chassis.pid_wait();
    pros::delay(1100);
    chassis.pid_turn_set(-88_deg, TURN_SPEED); // 92
    chassis.pid_wait();
    chassis.pid_drive_set(-32_in, DRIVE_SPEED, true);
    chassis.pid_wait_quick_chain(); // pidwait
    top_intake.move(-180);
    piston_bottom.set(false);
    pros::delay(3000);
    top_intake.move(0);

    chassis.pid_drive_set(9_in, DRIVE_SPEED, true);
    chassis.pid_wait();
    chassis.pid_turn_set(0_deg, TURN_SPEED); // 180
    chassis.pid_wait();
    back_distance = back_distance_sensor.get_distance() / 25.4;
    chassis.pid_drive_set(66 - back_distance, DRIVE_SPEED, true);
    chassis.pid_wait();
    chassis.pid_turn_set(90_deg, TURN_SPEED); //-90
    chassis.pid_wait();
    DRIVE_SPEED = 127;
    back_distance = back_distance_sensor.get_distance() / 25.4;
    chassis.pid_drive_set(-back_distance - 10, DRIVE_SPEED, true);
    chassis.pid_wait();
    */
  }

  { // cleanup parking zone at the start of auto with back
    /*
    DRIVE_SPEED = 90;
    TURN_SPEED = 90;

    piston_middle_intake.set(true);

    chassis.pid_drive_set(-66_in, DRIVE_SPEED, true); //58
    chassis.pid_wait_quick_chain();
    chassis.pid_turn_set(-90_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(16_in, DRIVE_SPEED);
    chassis.pid_wait();
    chassis.pid_turn_set(0_deg, TURN_SPEED);
    chassis.pid_wait();
    back_distance = back_distance_sensor.get_distance() / 25.4;
    right_distance = right_distance_sensor.get_distance() / 25.4;
    chassis.pid_drive_set(-(back_distance - 16.8), DRIVE_SPEED); //16.5
    chassis.pid_wait();
    piston_bottom.set(true);
    chassis.pid_turn_set(90_deg, DRIVE_SPEED);
    chassis.pid_wait();

    belt_intake.move(180);
    chassis.pid_drive_set(right_distance - 4.8, DRIVE_SPEED, true); // 4.5
    chassis.pid_wait();
    pros::delay(1100);
    */
  }

  ///// AUTO SKILL WITH INTAKING TWO/THREE BALLS FROM THE PILE OF FOUR AND SCORING ON THE MIDDLE FIRST THEN DOING EVERYTHING ELSE
  // DRIVE_SPEED = 110;
  // TURN_SPEED = 90;
  // belt_intake.move(180);

  // chassis.pid_turn_set(-22_deg, TURN_SPEED);
  // chassis.pid_wait_quick_chain();

  // DRIVE_SPEED = 110;
  // chassis.pid_drive_set(23_in, DRIVE_SPEED, true);
  // chassis.pid_wait_until(13_in);
  // DRIVE_SPEED = 40;
  // chassis.pid_speed_max_set(DRIVE_SPEED);
  // chassis.pid_wait();
  // chassis.pid_turn_set(-135_deg, TURN_SPEED);
  // chassis.pid_wait_quick_chain();
  // DRIVE_SPEED = 110;
  // chassis.pid_drive_set(-20.5_in, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // top_intake.move(-180);
  // pros::delay(850);
  // top_intake.move(0);
  // belt_intake.move(0);

  // chassis.pid_drive_set(52.5_in, DRIVE_SPEED, true); // 54
  // chassis.pid_wait();
  // piston_middle_intake.set(true);
  // piston_bottom.set(true);
  // chassis.pid_turn_set(180_deg, TURN_SPEED);
  // chassis.pid_wait_quick_chain();
  // belt_intake.move(180);
  // chassis.pid_drive_set(15.5_in, DRIVE_SPEED, true); // 16
  // chassis.pid_wait();
  // pros::delay(1100);

  // // copy and paste from new skill
  // chassis.pid_turn_set(180_deg, TURN_SPEED);
  // chassis.pid_wait();
  // chassis.pid_drive_set(-16_in, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // piston_bottom.set(false);
  // chassis.pid_turn_set(90_deg, TURN_SPEED);
  // chassis.pid_wait();

  // back_distance = back_distance_sensor.get_distance() / 25.4;
  // chassis.pid_drive_set(30.3 - back_distance, DRIVE_SPEED, true); // 12.8
  // chassis.pid_wait();
  // chassis.pid_turn_set(180_deg, TURN_SPEED);
  // chassis.pid_wait();

  // chassis.pid_drive_set(-80_in, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // DRIVE_SPEED = 95;

  // chassis.pid_turn_set(90_deg, TURN_SPEED);
  // chassis.pid_wait();
  // left_distance = left_distance_sensor.get_distance() / 25.4;
  // back_distance = back_distance_sensor.get_distance() / 25.4;
  // chassis.pid_drive_set(-(back_distance - 17.1), DRIVE_SPEED, true); // 17.6
  // chassis.pid_wait();
  // chassis.pid_turn_set(0_deg, TURN_SPEED);
  // chassis.pid_wait();
  // chassis.pid_drive_set(-(40 - left_distance), DRIVE_SPEED, true);
  // chassis.pid_wait();
  // top_intake.move(-180);
  // pros::delay(3500); ////2400
  // top_intake.move(0);

  // chassis.pid_turn_set(1.5_deg, TURN_SPEED); //////90
  // chassis.pid_wait();

  // belt_intake.move(180);
  // piston_bottom.set(true);
  // chassis.pid_drive_set(32.8_in, DRIVE_SPEED, true); ////////33.6
  // chassis.pid_wait();
  // pros::delay(1100); //////900
  // chassis.pid_turn_set(1.5_deg, TURN_SPEED);
  // chassis.pid_wait();
  // chassis.pid_drive_set(-32_in, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // top_intake.move(-180);
  // piston_bottom.set(false);
  // pros::delay(3500); ////2150
  // top_intake.move(0);

  // chassis.pid_drive_set(12.5_in, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // chassis.pid_turn_set(-90_deg, TURN_SPEED);
  // chassis.pid_wait();
  // chassis.pid_drive_set(-78_in, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // right_distance = right_distance_sensor.get_distance() / 25.4;
  // back_distance = back_distance_sensor.get_distance() / 25.4;
  // chassis.pid_drive_set(-(back_distance - 16), DRIVE_SPEED, true);
  // chassis.pid_wait();
  // piston_bottom.set(true);
  // chassis.pid_turn_set(0_deg, DRIVE_SPEED, true);
  // chassis.pid_wait();

  // // piston_bottom.set(true);
  // chassis.pid_drive_set(right_distance - 5, DRIVE_SPEED, true); // 32
  // chassis.pid_wait();
  // pros::delay(1100); ////900

  // chassis.pid_turn_set(0_deg, TURN_SPEED);
  // chassis.pid_wait();
  // chassis.pid_drive_set(-16_in, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // piston_bottom.set(false);
  // chassis.pid_turn_set(90_deg, TURN_SPEED);
  // chassis.pid_wait();

  // chassis.pid_drive_set(-12.8_in, DRIVE_SPEED, true); ///////12.9
  // chassis.pid_wait();
  // chassis.pid_turn_set(0_deg, TURN_SPEED);
  // chassis.pid_wait();

  // //****//NEW ITERATION WITH TWO DISTANCE SENSOR (BACK AND LEFT/RIGHT)
  // chassis.pid_drive_set(-80_in, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // DRIVE_SPEED = 95;
  // chassis.pid_turn_set(-90_deg, TURN_SPEED);
  // chassis.pid_wait();
  // left_distance = left_distance_sensor.get_distance() / 25.4;
  // back_distance = back_distance_sensor.get_distance() / 25.4;
  // piston_middle_intake.set(true);
  // chassis.pid_drive_set(-(back_distance - 16.5), DRIVE_SPEED, true); //// 17
  // chassis.pid_wait();
  // chassis.pid_turn_set(180_deg, TURN_SPEED);
  // chassis.pid_wait();
  // chassis.pid_drive_set(-(40 - left_distance), DRIVE_SPEED, true);
  // chassis.pid_wait();
  // top_intake.move(-180);
  // pros::delay(3500); // 2350
  // top_intake.move(0);
  // chassis.pid_turn_set(-178_deg, TURN_SPEED); //////90
  // chassis.pid_wait();

  // piston_bottom.set(true);
  // chassis.pid_drive_set(32.8_in, DRIVE_SPEED, true); //////34.5
  // chassis.pid_wait();
  // pros::delay(1100);                          // 900
  // chassis.pid_turn_set(-178_deg, TURN_SPEED); //////90
  // chassis.pid_wait();
  // chassis.pid_drive_set(-32_in, DRIVE_SPEED, true); //////-30.5
  // chassis.pid_wait();
  // top_intake.move(-180);
  // piston_bottom.set(false);
  // pros::delay(3600); // 2350
  // top_intake.move(0);

  // ////GOING TO PARK
  // //// chassis.drive_angle_set(90);
  // //// chassis.pid_wait();

  // chassis.pid_drive_set(9_in, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // chassis.pid_turn_set(-90_deg, TURN_SPEED);
  // chassis.pid_wait();
  // back_distance = back_distance_sensor.get_distance() / 25.4;
  // chassis.pid_drive_set(66 - back_distance, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // chassis.pid_turn_set(0_deg, TURN_SPEED);
  // chassis.pid_wait();
  // DRIVE_SPEED = 127;
  // back_distance = back_distance_sensor.get_distance() / 25.4;
  // chassis.pid_drive_set(-back_distance - 10, DRIVE_SPEED, true);
  // chassis.pid_wait();

  DRIVE_SPEED = 90;
  belt_intake.move(180);
  chassis.pid_drive_set(65_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  




  
}

void default_constants()
{ // old constants
  // P, I, D, and Start I
  chassis.pid_drive_constants_set(4.1, 0.0, 0.0);           // 6.0, 0.0, 7.0        // Fwd/rev constants, used for odom and non odom motions
  chassis.pid_heading_constants_set(11.5, 0.0, 50.0);       // 2nd version: 9.9, 0.0, 20.0      // Holds the robot straight while going forward without odom
  chassis.pid_turn_constants_set(3.0, 0.0, 20.0, 0.0);      // Turn in place constants
  chassis.pid_swing_constants_set(6.0, 0.0, 50.0);          // Swing constants
  chassis.pid_odom_angular_constants_set(6.5, 0.0, 52.5);   // Angular control for odom motions
  chassis.pid_odom_boomerang_constants_set(5.8, 0.0, 32.5); // Angular control for boomerang motions

  // Exit conditions
  chassis.pid_turn_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_swing_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 500_ms, 500_ms); //250
  chassis.pid_odom_turn_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 750_ms);
  chassis.pid_odom_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 500_ms, 750_ms);
  chassis.pid_turn_chain_constant_set(3_deg);
  chassis.pid_swing_chain_constant_set(5_deg);
  chassis.pid_drive_chain_constant_set(3_in);

  // Slew constants
  chassis.slew_turn_constants_set(3_deg, 50);
  chassis.slew_drive_constants_set(3_in, 50);
  chassis.slew_swing_constants_set(3_in, 50);

  // The amount that turns are prioritized over driving in odom motions
  // - if you have tracking wheels, you can run this higher.  1.0 is the max
  chassis.odom_turn_bias_set(0.9);

  chassis.odom_look_ahead_set(7_in);          // This is how far ahead in the path the robot looks at
  chassis.odom_boomerang_distance_set(16_in); // This sets the maximum distance away from target that the carrot point can be
  chassis.odom_boomerang_dlead_set(0.625);    // This handles how aggressive the end of boomerang motions are

  chassis.pid_angle_behavior_set(ez::shortest); // Changes the default behavior for turning, this defaults it to the shortest path there
}

///
// Drive Example
///

void left2long5middle_auton()
{
  DRIVE_SPEED = 110;

  piston_middle_intake.set(true);
  belt_intake.move(180);
  chassis.pid_drive_set(10_in, DRIVE_SPEED, true);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(-27_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(16.5_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(-128_deg, TURN_SPEED); //-135
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(32_in, DRIVE_SPEED, true); // 31.5
  chassis.pid_wait();
  chassis.pid_turn_set(180_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(-12.5_in, DRIVE_SPEED);
  chassis.pid_wait();

  // NEXT TIME RUNNING UPLOAD CODE FIRST

  // piston_middle_intake.set(true);
  // DRIVE_SPEED = 110;
  // belt_intake.move(180);
  // chassis.pid_drive_set(12_in, DRIVE_SPEED, true);
  // chassis.pid_wait_quick_chain();
  // chassis.pid_turn_set(33_deg, TURN_SPEED);
  // chassis.pid_wait();

  // chassis.pid_drive_set(17.5_in, DRIVE_SPEED, true);
  // chassis.pid_wait();

  // chassis.pid_turn_set(135_deg, TURN_SPEED);
  // chassis.pid_wait_quick_chain();
  // chassis.pid_drive_set(34.4_in, DRIVE_SPEED, true);
  // chassis.pid_wait();

  // chassis.pid_turn_set(180_deg, TURN_SPEED);
  // chassis.pid_wait_quick_chain();
  // chassis.pid_drive_set(-25_in, DRIVE_SPEED, true);
  // chassis.pid_wait();

  // top_intake.move(-180);
  // pros::delay(1250); //2000
  // chassis.pid_turn_set(179_deg, TURN_SPEED);
  // chassis.pid_wait_quick_chain();
  // piston_bottom.set(true);
  // top_intake.move(0);
  // chassis.pid_drive_set(31.8_in, DRIVE_SPEED, true); //32.8
  // chassis.pid_wait();
  // // pros::delay(200);
  // chassis.pid_turn_set(179_deg, TURN_SPEED);
  // chassis.pid_wait_quick_chain();
  // chassis.pid_drive_set(-32_in, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // top_intake.move(-180);
  // piston_bottom.set(false);
  // pros::delay(1200); //1150
}

void left5long2middle_auton()
{
  DRIVE_SPEED = 110;
  piston_descore.set(true);
  // piston_middle_intake.set(true);
  ///// RED AND BLUE LEFT AUTON INTAKE THREE BALLS SCORE TO MIDDLE AND INTAKE THREE RELOADER BALLS SCORE LONG
  belt_intake.move(180);
  chassis.pid_drive_set(10_in, DRIVE_SPEED, true); // 12
  chassis.pid_wait();
  chassis.pid_turn_set(-27_deg, TURN_SPEED); //-30
  chassis.pid_wait();
  // chassis.pid_drive_set(10.2_in, DRIVE_SPEED, true); //9
  // chassis.pid_wait();
  // piston_bottom.set(true);
  // chassis.pid_drive_set(4.3_in, DRIVE_SPEED, true);  //6.5
  // chassis.pid_wait();
  chassis.pid_drive_set(16.5_in, DRIVE_SPEED, true); ///////16!!!!!!!
  chassis.pid_wait();
  chassis.pid_turn_set(-135_deg, TURN_SPEED);
  chassis.pid_wait();
  // piston_bottom.set(false);
  chassis.pid_drive_set(-19.5_in, DRIVE_SPEED, true); //////////-20
  chassis.pid_wait();
  top_intake.move(-180);
  pros::delay(530); ///////for one balls: 100, trying two balls for sig: at home 430
  top_intake.move(0);
  belt_intake.move(0);
  ////// piston_middle_intake.set(true);
  chassis.pid_drive_set(54_in, DRIVE_SPEED, true); // 53
  chassis.pid_wait();
  piston_middle_intake.set(true);
  chassis.pid_turn_set(180_deg, TURN_SPEED); // 180
  chassis.pid_wait();
  belt_intake.move(180);
  piston_bottom.set(true);
  chassis.pid_drive_set(16_in, DRIVE_SPEED, true); //////////22
  chassis.pid_wait();
  pros::delay(200);

  // //new code going back into the loader again
  // chassis.pid_drive_set(-7_in, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // chassis.pid_turn_set(180_deg, TURN_SPEED);;
  // chassis.pid_wait();
  // chassis.pid_drive_set(10_in, DRIVE_SPEED, true);
  // chassis.pid_wait();

  // pros::delay(100); //200
  // belt_intake.move(0);
  //  DRIVE_SPEED = 80;
  chassis.pid_turn_set(180_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-33_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  // piston_middle_intake.set(true);
  top_intake.move(-180);
  piston_bottom.set(false);
  pros::delay(1950);
  top_intake.move(0);
}

void rightsevendescore_auton()
{
  // piston_descore.set(true);
  piston_middle_intake.set(true);
  DRIVE_SPEED = 110;
  belt_intake.move(180);
  chassis.pid_drive_set(12_in, DRIVE_SPEED, true);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(33_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(17.5_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(135_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(34.4_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(180_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(-25_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  top_intake.move(-180);
  pros::delay(1250); // 2000
  chassis.pid_turn_set(179_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  piston_bottom.set(true);
  top_intake.move(0);
  chassis.pid_drive_set(31.8_in, DRIVE_SPEED, true); // 32.8
  chassis.pid_wait();
  // pros::delay(200);
  chassis.pid_turn_set(179_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(-32_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  top_intake.move(-180);
  piston_bottom.set(false);
  pros::delay(1200); // 1150
  top_intake.move(0);

  // going to descore from the long goal
  chassis.drive_angle_set(-90);
  chassis.pid_swing_set(ez::RIGHT_SWING, -120_deg, SWING_SPEED, 30);
  chassis.pid_wait();
  chassis.pid_turn_set(-31_deg, TURN_SPEED); //-30
  chassis.pid_wait();
  chassis.pid_swing_set(ez::LEFT_SWING, -91_deg, SWING_SPEED, 27);
  chassis.pid_wait();
  DRIVE_SPEED = 90;
  chassis.pid_drive_set(-21_in, DRIVE_SPEED, true);
  chassis.pid_wait_until(-15_in);
  DRIVE_SPEED = 110;
  chassis.pid_speed_max_set(DRIVE_SPEED);
  chassis.pid_wait();

  // chassis.pid_drive_set(5_in, DRIVE_SPEED);
  // piston_middle_intake.set(false);
  // chassis.pid_wait_quick_chain();
  // chassis.pid_drive_set(-15_in, DRIVE_SPEED);
}

void leftsevendescore_auton() {
  DRIVE_SPEED = 110;
}

void rightsevendescorewithonlyoneouttaking() {
  piston_middle_intake.set(true);
  DRIVE_SPEED = 110;
  belt_intake.move(180);
  chassis.pid_drive_set(12_in, DRIVE_SPEED, true);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(33_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(17.5_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(135_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(33.8_in, DRIVE_SPEED, true); //34.4
  chassis.pid_wait();

  chassis.pid_turn_set(179_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  piston_bottom.set(true);
  chassis.pid_drive_exit_condition_set(20_ms, 1_in, 50_ms, 3_in, 500_ms, 500_ms);
  chassis.pid_drive_set(16_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 500_ms, 500_ms);
  //pros::delay(100);
  chassis.pid_turn_set(179_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(-32_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  top_intake.move(-180);
  piston_bottom.set(false);
  pros::delay(2800); 
  top_intake.move(0);


  // going to descore from the long goal
  chassis.drive_angle_set(-90);
  chassis.pid_swing_set(ez::RIGHT_SWING, -120_deg, SWING_SPEED, 30);
  chassis.pid_wait();
  chassis.pid_turn_set(-31_deg, TURN_SPEED); //-30
  chassis.pid_wait();
  chassis.pid_swing_set(ez::LEFT_SWING, -91_deg, SWING_SPEED, 27);
  chassis.pid_wait();
  DRIVE_SPEED = 90;
  chassis.pid_drive_set(-21_in, DRIVE_SPEED, true);
  chassis.pid_wait_until(-15_in);
  DRIVE_SPEED = 110;
  chassis.pid_speed_max_set(DRIVE_SPEED);
  chassis.pid_wait();
}

void rightsevenpush_auton() {
  piston_middle_intake.set(true);
  DRIVE_SPEED = 110;
  belt_intake.move(180);
  chassis.pid_drive_set(12_in, DRIVE_SPEED, true);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(33_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(17.5_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(135_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(33.8_in, DRIVE_SPEED, true); //34.4
  chassis.pid_wait();

  chassis.pid_turn_set(179_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  piston_bottom.set(true);
  chassis.pid_drive_exit_condition_set(20_ms, 1_in, 50_ms, 3_in, 500_ms, 500_ms);
  chassis.pid_drive_set(16_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 500_ms, 500_ms);
  chassis.pid_turn_set(179_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(-32_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  top_intake.move(-180);
  piston_bottom.set(false);
  pros::delay(2800); 
  top_intake.move(0);

  // push
  chassis.pid_drive_set(5_in, DRIVE_SPEED);
  piston_middle_intake.set(false);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(-15_in, DRIVE_SPEED);
}

void leftfourdescore_auton()
{
  DRIVE_SPEED = 110;
  piston_middle_intake.set(true);

  right_distance = right_distance_sensor.get_distance() / 25.4;
  back_distance = back_distance_sensor.get_distance() / 25.4;
  chassis.pid_drive_set(-(back_distance - 19), DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  piston_bottom.set(true);
  chassis.pid_wait();
  belt_intake.move(180);
  chassis.pid_drive_set(right_distance - 4.5, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_turn_set(88_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-31_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  top_intake.move(-180);
  pros::delay(1600);
  top_intake.move(0);
  piston_bottom.set(false);

  // going to descore from the long goal
  chassis.drive_angle_set(90);
  chassis.pid_swing_set(ez::RIGHT_SWING, 60_deg, SWING_SPEED, 30);
  chassis.pid_wait();
  chassis.pid_turn_set(150_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_swing_set(ez::LEFT_SWING, 89.5_deg, SWING_SPEED, 29);
  chassis.pid_wait();
  DRIVE_SPEED = 90;
  chassis.pid_drive_set(-21_in, DRIVE_SPEED, true);
  chassis.pid_wait_until(-15_in);
  DRIVE_SPEED = 110;
  chassis.pid_speed_max_set(DRIVE_SPEED);
  chassis.pid_wait();
}

void rightfourdescore_auton()
{
  DRIVE_SPEED = 110;
  piston_middle_intake.set(true);

  left_distance = left_distance_sensor.get_distance() / 25.4;
  back_distance = back_distance_sensor.get_distance() / 25.4;
  chassis.pid_drive_set(-(back_distance - 19), DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  piston_bottom.set(true);
  chassis.pid_wait();
  // pros::delay(80);
  belt_intake.move(180);
  chassis.pid_drive_set(left_distance - 4, DRIVE_SPEED); // 4.5
  chassis.pid_wait();
  chassis.pid_turn_set(-87_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-31_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  top_intake.move(-180);
  pros::delay(1500); // 1600
  top_intake.move(0);
  piston_bottom.set(false);

  // going to descore from the long goal
  chassis.drive_angle_set(-90);
  chassis.pid_swing_set(ez::RIGHT_SWING, -120_deg, SWING_SPEED, 30);
  chassis.pid_wait();
  chassis.pid_turn_set(-31_deg, TURN_SPEED); //-30
  chassis.pid_wait();
  chassis.pid_swing_set(ez::LEFT_SWING, -91_deg, SWING_SPEED, 27);
  chassis.pid_wait();
  DRIVE_SPEED = 90;
  chassis.pid_drive_set(-21_in, DRIVE_SPEED, true);
  chassis.pid_wait_until(-15_in);
  DRIVE_SPEED = 110;
  chassis.pid_speed_max_set(DRIVE_SPEED);
  chassis.pid_wait();
}

void soloawp_auton()
{
  DRIVE_SPEED = 110;
  chassis.pid_drive_set(13.5_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(27_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(22_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  belt_intake.move(30);
  pros::delay(200);
  belt_intake.move(0);
  chassis.pid_drive_set(-32_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(-27_deg, TURN_SPEED);
  chassis.pid_wait();
  belt_intake.move(180);
  piston_descore.set(true);
  chassis.pid_drive_set(22_in, DRIVE_SPEED, true); // 21.5 works
  chassis.pid_wait();
  chassis.pid_turn_set(-136_deg, TURN_SPEED); //-132
  chassis.pid_wait();
  chassis.pid_drive_set(-18_in, DRIVE_SPEED, true); //-19
  chassis.pid_wait();
  top_intake.move(-180);
  pros::delay(300);
  top_intake.move(0);

  belt_intake.move(0);
  DRIVE_SPEED = 127;
  piston_bottom.set(true);
  chassis.pid_drive_set(55.5_in, DRIVE_SPEED, true); // 54.5
  chassis.pid_wait();
  piston_middle_intake.set(true);
  TURN_SPEED = 90;
  chassis.pid_turn_set(180_deg, TURN_SPEED); // 180
  chassis.pid_wait();
  belt_intake.move(180);
  // piston_bottom.set(true); // changed in comp
  chassis.pid_drive_set(12.5_in, DRIVE_SPEED, true); //////////16
  chassis.pid_wait();
  // pros::delay(50);
  TURN_SPEED = 70;
  chassis.pid_turn_set(180_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-32_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  top_intake.move(-180);
  piston_bottom.set(false);
  // pros::delay(1950);
  // top_intake.move(0);
}

void right_auton1_6()
{
  DRIVE_SPEED = 110;
  piston_descore.set(true);
  piston_middle_intake.set(true);
  chassis.pid_drive_set(30.5_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  belt_intake.move(180);
  pros::delay(100);
  belt_intake.move(0);
  chassis.pid_drive_set(-8.5_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  belt_intake.move(180);
  chassis.pid_turn_set(90_deg, DRIVE_SPEED, true);
  chassis.pid_wait();
  DRIVE_SPEED = 30;
  chassis.pid_drive_set(20_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  DRIVE_SPEED = 110;
  chassis.pid_turn_set(135_deg, TURN_SPEED, true);
  chassis.pid_wait();
  chassis.pid_drive_set(30_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(180_deg, DRIVE_SPEED, true);
  chassis.pid_wait();
}

void new_skill()
{
  // new_constants();
  DRIVE_SPEED = 110;
  TURN_SPEED = 90;
  piston_middle_intake.set(true);
  back_distance = back_distance_sensor.get_distance() / 25.4;
  right_distance = right_distance_sensor.get_distance() / 25.4;
  chassis.pid_drive_set(-(back_distance - 18), DRIVE_SPEED, true); // 16.5
  chassis.pid_wait();

  piston_bottom.set(true);
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
  // piston_bottom.set(true);
  belt_intake.move(180);
  chassis.pid_drive_set(right_distance - 4.5, DRIVE_SPEED, true); // 19.5
  chassis.pid_wait();
  pros::delay(1100); /////900
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-16_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  piston_bottom.set(false);
  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  back_distance = back_distance_sensor.get_distance() / 25.4;
  chassis.pid_drive_set(30.3 - back_distance, DRIVE_SPEED, true); // 12.8
  chassis.pid_wait();
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-80_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  DRIVE_SPEED = 95;

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();
  left_distance = left_distance_sensor.get_distance() / 25.4;
  back_distance = back_distance_sensor.get_distance() / 25.4;
  chassis.pid_drive_set(-(back_distance - 17.1), DRIVE_SPEED, true); // 17.6
  chassis.pid_wait();
  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-(40 - left_distance), DRIVE_SPEED, true);
  chassis.pid_wait();
  top_intake.move(-180);
  pros::delay(3500); ////2400
  top_intake.move(0);

  chassis.pid_turn_set(-88.5_deg, TURN_SPEED); //////90
  chassis.pid_wait();

  belt_intake.move(180);
  piston_bottom.set(true);
  chassis.pid_drive_set(32.8_in, DRIVE_SPEED, true); ////////33.6
  chassis.pid_wait();
  pros::delay(1100); //////900
  chassis.pid_turn_set(-88.5_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-32_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  top_intake.move(-180);
  piston_bottom.set(false);
  pros::delay(3500); ////2150
  top_intake.move(0);

  chassis.pid_drive_set(12.5_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(180_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-78_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  right_distance = right_distance_sensor.get_distance() / 25.4;
  back_distance = back_distance_sensor.get_distance() / 25.4;
  chassis.pid_drive_set(-(back_distance - 16), DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(-90_deg, DRIVE_SPEED, true);
  chassis.pid_wait();

  ////******OUTTAKE ON MIDDLE GOAL */
  //// chassis.pid_drive_set(13_in, DRIVE_SPEED, true);
  //// chassis.pid_wait();
  //// chassis.pid_turn_set(35_deg, TURN_SPEED);
  //// chassis.pid_wait();
  //// DRIVE_SPEED = 85;
  //// chassis.pid_drive_set(30_in, DRIVE_SPEED, true);
  //// chassis.pid_wait();
  //// chassis.pid_turn_set(0_deg, TURN_SPEED);
  //// chassis.pid_wait();
  //// chassis.pid_drive_set(54_in, DRIVE_SPEED, true);
  //// chassis.pid_wait();
  //// DRIVE_SPEED = 110;

  //// piston_middle_intake.set(false);
  //// chassis.pid_turn_set(-40_deg, TURN_SPEED);
  //// chassis.pid_wait();
  //// chassis.pid_drive_set(-23_in, DRIVE_SPEED, true);
  //// chassis.pid_wait();
  //// top_intake.move(-130);
  //// pros::delay(2500);
  //// top_intake.move(0);

  //// chassis.pid_drive_set(44_in, DRIVE_SPEED, true);
  //// chassis.pid_wait();
  //// chassis.pid_turn_set(180_deg, TURN_SPEED);
  //// chassis.pid_wait();
  //// right_distance = right_distance_sensor.get_distance() / 25.4;
  //// back_distance = back_distance_sensor.get_distance() / 25.4;
  //// chassis.pid_drive_set(- (back_distance - 15.5), DRIVE_SPEED, true); ///////15.5
  //// chassis.pid_wait();
  //// chassis.pid_turn_set(-91_deg, TURN_SPEED, true);
  //// chassis.pid_wait();

  piston_bottom.set(true);
  chassis.pid_drive_set(right_distance - 5, DRIVE_SPEED, true); // 32
  chassis.pid_wait();
  pros::delay(1100); ////900

  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-16_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  piston_bottom.set(false);
  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-12.8_in, DRIVE_SPEED, true); ///////12.9
  chassis.pid_wait();
  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();

  ////!!!before iteration with only one distance sensor (no left/right)
  ////************* */ chassis.pid_drive_set(-80_in, DRIVE_SPEED, true); ///***-74 */
  //// chassis.pid_wait();
  //// DRIVE_SPEED = 95;
  //// back_distance = back_distance_sensor.get_distance() / 25.4;
  //// chassis.pid_drive_set(- (back_distance - 24), DRIVE_SPEED, true); //////20
  //// chassis.pid_wait();
  //// chassis.pid_turn_set(180_deg, TURN_SPEED);
  //// chassis.pid_wait();
  //// back_distance = back_distance_sensor.get_distance() / 25.4;
  //// chassis.pid_drive_set(- (back_distance - 16.8), DRIVE_SPEED, true); ////// 17.6
  //// chassis.pid_wait();
  //// chassis.pid_turn_set(90_deg, TURN_SPEED);
  //// chassis.pid_wait();
  //// piston_middle_intake.set(true);
  //// chassis.pid_drive_set(-16_in, DRIVE_SPEED, true);
  //// chassis.pid_wait();
  //// top_intake.move(-180);
  //// pros::delay(2150);
  //// top_intake.move(0);

  //****//NEW ITERATION WITH TWO DISTANCE SENSOR (BACK AND LEFT/RIGHT)
  chassis.pid_drive_set(-80_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  DRIVE_SPEED = 95;
  chassis.pid_turn_set(180_deg, TURN_SPEED);
  chassis.pid_wait();
  left_distance = left_distance_sensor.get_distance() / 25.4;
  back_distance = back_distance_sensor.get_distance() / 25.4;
  piston_middle_intake.set(true);
  chassis.pid_drive_set(-(back_distance - 16.5), DRIVE_SPEED, true); //// 17
  chassis.pid_wait();
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-(40 - left_distance), DRIVE_SPEED, true);
  chassis.pid_wait();
  top_intake.move(-180);
  pros::delay(3500); // 2350
  top_intake.move(0);
  chassis.pid_turn_set(92_deg, TURN_SPEED); //////90
  chassis.pid_wait();

  piston_bottom.set(true);
  chassis.pid_drive_set(32.8_in, DRIVE_SPEED, true); //////34.5
  chassis.pid_wait();
  pros::delay(1100);                        // 900
  chassis.pid_turn_set(92_deg, TURN_SPEED); //////90
  chassis.pid_wait();
  chassis.pid_drive_set(-32_in, DRIVE_SPEED, true); //////-30.5
  chassis.pid_wait();
  top_intake.move(-180);
  piston_bottom.set(false);
  pros::delay(3600); // 2350
  top_intake.move(0);

  ////GOING TO PARK
  //// chassis.drive_angle_set(90);
  //// chassis.pid_wait();

  chassis.pid_drive_set(9_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(180_deg, TURN_SPEED);
  chassis.pid_wait();
  back_distance = back_distance_sensor.get_distance() / 25.4;
  chassis.pid_drive_set(66 - back_distance, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();
  DRIVE_SPEED = 127;
  back_distance = back_distance_sensor.get_distance() / 25.4;
  chassis.pid_drive_set(-back_distance - 10, DRIVE_SPEED, true);
  chassis.pid_wait();

  // adsfsdpfkad

  // chassis.pid_wait();
  // back_distance = back_distance_sensor.get_distance() / 25.4;
  // chassis.pid_drive_set(- (back_distance - 5), DRIVE_SPEED, true);
  // chassis.pid_wait();
  // chassis.pid_turn_set(90_deg, TURN_SPEED);
  // chassis.pid_wait();
  // chassis.pid_drive_set(-74_in, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // DRIVE_SPEED = 95;
  // back_distance = back_distance_sensor.get_distance() / 25.4;
  // chassis.pid_drive_set(- (back_distance - 20), DRIVE_SPEED, true);
  // chassis.pid_wait();
  // chassis.pid_turn_set(0_deg, TURN_SPEED);
  // chassis.pid_wait();
  // chassis.pid_drive_set(12_in, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // chassis.pid_turn_set(-90_deg, TURN_SPEED);
  // chassis.pid_wait();
  // belt_intake.move(-180);
}

void auton_skill()
{
  DRIVE_SPEED = 95;

  piston_descore.set(true);
  piston_middle_intake.set(true);
  chassis.pid_drive_set(29.2_in, DRIVE_SPEED, true); // 29
  chassis.pid_wait();
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
  piston_bottom.set(true);
  belt_intake.move(180);
  chassis.pid_drive_set(20.5_in, DRIVE_SPEED, true); // 20
  chassis.pid_wait();
  pros::delay(1500); // 2000
  chassis.pid_turn_set(91.5_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-33_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  // piston_middle_intake.set(true);
  top_intake.move(-180);
  pros::delay(2500);
  top_intake.move(0);
  piston_bottom.set(false);

  chassis.pid_drive_set(15_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();
  DRIVE_SPEED = 110;
  chassis.pid_drive_set(-80_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  DRIVE_SPEED = 95;
  back_distance = back_distance_sensor.get_distance() / 25.4;
  chassis.pid_drive_set(-(back_distance - 18.5), DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
  piston_bottom.set(true);
  belt_intake.move(180);
  chassis.pid_drive_set(22.5_in, DRIVE_SPEED, true); // 22
  chassis.pid_wait();
  pros::delay(1800);                          // 2000
  chassis.pid_turn_set(88.5_deg, TURN_SPEED); // 89
  chassis.pid_wait();
  chassis.pid_drive_set(-33_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  top_intake.move(-180); //-180
  pros::delay(2001);
  top_intake.move(0);
  piston_bottom.set(false);

  chassis.pid_drive_set(8_in, DRIVE_SPEED, true); // 10
  chassis.pid_wait();
  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(13_in, DRIVE_SPEED, true); // 13.8
  chassis.pid_wait();
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
  DRIVE_SPEED = 110;
  chassis.pid_drive_set(-74_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  DRIVE_SPEED = 95;
  back_distance = back_distance_sensor.get_distance() / 25.4;
  chassis.pid_drive_set(-(back_distance - 20), DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();
  back_distance = back_distance_sensor.get_distance() / 25.4;
  chassis.pid_drive_set(-(back_distance - 18.5), DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();
  piston_bottom.set(true);
  belt_intake.move(180);
  chassis.pid_drive_set(21_in, DRIVE_SPEED, true); // 20
  chassis.pid_wait();
  pros::delay(2000);

  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-18_in, DRIVE_SPEED, true); //-17.5
  chassis.pid_wait();
  piston_bottom.set(false);
  chassis.pid_turn_set(180_deg, TURN_SPEED);
  chassis.pid_wait();
  DRIVE_SPEED = 110;
  chassis.pid_drive_set(-80_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  DRIVE_SPEED = 95;
  back_distance = back_distance_sensor.get_distance() / 25.4;
  chassis.pid_drive_set(-(back_distance - 16.5), DRIVE_SPEED, true); // 15.5
  chassis.pid_wait();
  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-19_in, DRIVE_SPEED, true); //-18
  chassis.pid_wait();
  top_intake.move(-180);
  pros::delay(1900); // 2001
  top_intake.move(0);

  chassis.pid_turn_set(-91.5_deg, TURN_SPEED);
  chassis.pid_wait();
  piston_bottom.set(true);
  belt_intake.move(180);
  chassis.pid_drive_set(35.5_in, DRIVE_SPEED, true); // 35
  chassis.pid_wait();
  pros::delay(2000);
  chassis.pid_drive_set(-17.5_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  piston_bottom.set(false);

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();
  DRIVE_SPEED = 110;
  chassis.pid_drive_set(-80_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  DRIVE_SPEED = 95;
  back_distance = back_distance_sensor.get_distance() / 25.4;
  chassis.pid_drive_set(-(back_distance - 17), DRIVE_SPEED, true); // 16.5
  chassis.pid_wait();
  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-18_in, DRIVE_SPEED, true); //-17
  chassis.pid_wait();
  top_intake.move(-180);
  pros::delay(750); // 1100
  top_intake.move(0);

  // parking
  DRIVE_SPEED = 110;
  // chassis.drive_angle_set(-90);
  chassis.pid_drive_set(20_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_turn_set(-118_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-97_in, DRIVE_SPEED, true); //-101
  chassis.pid_wait();
  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();
  // back_distance = back_distance_sensor.get_distance() / 25.4;
  // chassis.pid_drive_set(40 - back_distance, DRIVE_SPEED, true); //40
  // chassis.pid_wait();

  DRIVE_SPEED = 127;
  chassis.pid_drive_set(-75_in, DRIVE_SPEED, true);

  // going to parking
  //  chassis.pid_drive_set(10_in, DRIVE_SPEED, true);
  //  chassis.pid_wait();
  //  chassis.pid_turn_set(150_deg, TURN_SPEED);
  //  chassis.pid_wait();
  //  DRIVE_SPEED = 110;
  //  chassis.pid_drive_set(-48_in, DRIVE_SPEED, true);
  //  chassis.pid_wait();

  // chassis.pid_drive_set(28_in, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // chassis.pid_turn_set(170_deg, TURN_SPEED); //
  // chassis.pid_wait();
  // DRIVE_SPEED = 110;
  // chassis.pid_drive_set(-70_in, DRIVE_SPEED, true);
  // chassis.pid_wait();

  // DRIVE_SPEED = 110;
  // chassis.pid_drive_set(28_in, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // chassis.pid_turn_set(170_deg, TURN_SPEED); //
  // chassis.pid_wait();
  // chassis.pid_drive_set(-40_in, DRIVE_SPEED, true);
  // chassis.pid_wait_quick_chain();
  // chassis.pid_turn_set(180_deg, TURN_SPEED);
  // chassis.pid_wait();
  // chassis.pid_drive_set(-70_in,DRIVE_SPEED, true);

  // chassis.pid_drive_set(-88_in, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // chassis.pid_turn_set(180_deg, TURN_SPEED);
  // chassis.pid_wait();
  // chassis.pid_drive_set(12_in, DRIVE_SPEED, true); //11
  // chassis.pid_wait();
  // chassis.pid_turn_set(-90_deg, TURN_SPEED);
  // chassis.pid_wait();
  // piston_bottom.set(true);
  // belt_intake.move(180);
  // chassis.pid_drive_set(20_in, DRIVE_SPEED, true); //22
  // chassis.pid_wait();
  // pros::delay(1000);
  // chassis.pid_turn_set(-90_deg, TURN_SPEED);
  // chassis.pid_wait();
  // chassis.pid_drive_set(-7_in, DRIVE_SPEED, true);
  // chassis.pid_wait();

  // piston_descore.set(true);
  // chassis.pid_drive_set(29_in, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // chassis.pid_turn_set(90_deg, TURN_SPEED);
  // chassis.pid_wait();
  // piston_bottom.set(true);
  // belt_intake.move(180);
  // chassis.pid_drive_set(20_in, DRIVE_SPEED, true); //22
  // chassis.pid_wait();
  // pros::delay(1000);
  // chassis.pid_turn_set(90_deg, TURN_SPEED);
  // chassis.pid_wait();
  // chassis.pid_drive_set(-33_in, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // piston_middle_intake.set(true);
  // top_intake.move(-180);
  // pros::delay(3400);
  // top_intake.move(0);
  // piston_bottom.set(false);
  // chassis.pid_drive_set(15_in, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // chassis.pid_turn_set(0_deg, TURN_SPEED);
  // chassis.pid_wait();
  // chassis.pid_drive_set(-94_in, DRIVE_SPEED, true); //-94.7
  // chassis.pid_wait();
  // chassis.pid_turn_set(90_deg, TURN_SPEED);
  // chassis.pid_wait();
  // piston_bottom.set(true);
  // belt_intake.move(180);
  // chassis.pid_drive_set(29_in, DRIVE_SPEED, true); //29.8
  // chassis.pid_wait();
  // pros::delay(1000);
  // chassis.pid_turn_set(90_deg, TURN_SPEED);
  // chassis.pid_wait();
  // chassis.pid_drive_set(-33_in, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // top_intake.move(-180);
  // pros::delay(3400);
  // top_intake.move(0);
  // piston_bottom.set(false);
  // chassis.pid_drive_set(16_in, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // chassis.pid_turn_set(0_deg, TURN_SPEED);
  // chassis.pid_wait();
  // chassis.pid_drive_set(13.8_in, DRIVE_SPEED, true); //-15
  // chassis.pid_wait();
  // chassis.pid_turn_set(90_deg, TURN_SPEED);
  // chassis.pid_wait();
  // chassis.pid_drive_set(-88_in, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // chassis.pid_turn_set(180_deg, TURN_SPEED);
  // chassis.pid_wait();
  // chassis.pid_drive_set(11_in, DRIVE_SPEED, true); //11.3
  // chassis.pid_wait();
  // chassis.pid_turn_set(-90_deg, TURN_SPEED);
  // chassis.pid_wait();
  // piston_bottom.set(true);
  // belt_intake.move(180);
  // chassis.pid_drive_set(20_in, DRIVE_SPEED, true); //22
  // chassis.pid_wait();
  // pros::delay(1000);
  // chassis.pid_turn_set(-90_deg, TURN_SPEED);
  // chassis.pid_wait();
  // chassis.pid_drive_set(-39_in, DRIVE_SPEED, true); //-33
  // chassis.pid_wait();
  // top_intake.move(-180);
  // pros::delay(3400);
  // top_intake.move(0);
  // piston_bottom.set(false);
  // chassis.pid_drive_set(12_in, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // chassis.pid_turn_set(180_deg, TURN_SPEED);
  // chassis.pid_wait();
  // chassis.pid_drive_set(-94.7_in, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // chassis.pid_turn_set(-90_deg, TURN_SPEED);
  // chassis.pid_wait();
  // chassis.pid_drive_set(-25_in, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // top_intake.move(-180);
  // pros::delay(3400);
  // top_intake.move(0);
  // piston_bottom.set(true);
  // chassis.pid_drive_set(-33_in, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // pros::delay(3400);
  // chassis.pid_drive_set(-12_in, DRIVE_SPEED, true);
  // chassis.pid_wait();
}

void drive_example()
{
  // belt_intake.move(180);
  // chassis.pid_drive_set(12_in, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // chassis.pid_turn_set(-33_deg, TURN_SPEED); //-33
  // chassis.pid_wait();
  // DRIVE_SPEED = 65;
  // chassis.pid_drive_set(8.5_in, DRIVE_SPEED, true); //9
  // chassis.pid_wait();
  // piston_bottom.set(true);
  // chassis.pid_drive_set(6.2_in, DRIVE_SPEED, true);  //5.7
  // chassis.pid_wait();
  // DRIVE_SPEED = 100;
  // chassis.pid_turn_set(-135_deg, TURN_SPEED);
  // chassis.pid_wait();
  // //piston_bottom.set(false);
  // chassis.pid_drive_set(-18_in, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // top_intake.move(-100);
  // pros::delay(1900); //1000
  // top_intake.move(0);
  // chassis.pid_drive_set(52_in, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // chassis.pid_turn_set(180_deg, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // //piston_bottom.set(true);
  // chassis.pid_drive_set(21_in, DRIVE_SPEED, true); //16
  // chassis.pid_wait();
  // pros::delay(1000);
  // //belt_intake.move(0);00
  // DRIVE_SPEED = 60;
  // chassis.pid_turn_set(180_deg, DRIVE_SPEED, true);
  // chassis.pid_wait();
  // chassis.pid_drive_set(-32_in, DRIVE_SPEED, true); //-33
  // chassis.pid_wait();
  // piston_middle_intake.set(true);
  // top_intake.move(-180);
  // piston_bottom.set(false);
}

///
// Turn Example
///
void turn_example()
{
  // The first parameter is the target in degrees
  // The second parameter is max speed the robot will drive at

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();
}

///
// Combining Turn + Drive
///
void drive_and_turn()
{
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}

///
// Wait Until and Changing Max Speed
///
void wait_until_change_speed()
{
  // pid_wait_until will wait until the robot gets to a desired position

  // When the robot gets to 6 inches slowly, the robot will travel the remaining distance at full speed
  chassis.pid_drive_set(24_in, 30, true);
  chassis.pid_wait_until(6_in);
  chassis.pid_speed_max_set(DRIVE_SPEED); // After driving 6 inches at 30 speed, the robot will go the remaining distance at DRIVE_SPEED
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  // When the robot gets to -6 inches slowly, the robot will travel the remaining distance at full speed
  chassis.pid_drive_set(-24_in, 30, true);
  chassis.pid_wait_until(-6_in);
  chassis.pid_speed_max_set(DRIVE_SPEED); // After driving 6 inches at 30 speed, the robot will go the remaining distance at DRIVE_SPEED
  chassis.pid_wait();
}

///
// Swing Example
///
void swing_example()
{
  // The first parameter is ez::LEFT_SWING or ez::RIGHT_SWING
  // The second parameter is the target in degrees
  // The third parameter is the speed of the moving side of the drive
  // The fourth parameter is the speed of the still side of the drive, this allows for wider arcs

  chassis.pid_swing_set(ez::LEFT_SWING, 45_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, 0_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, 45_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::LEFT_SWING, 0_deg, SWING_SPEED, 45);
  chassis.pid_wait();
}

///
// Motion Chaining
///
void motion_chaining()
{
  // Motion chaining is where motions all try to blend together instead of individual movements.
  // This works by exiting while the robot is still moving a little bit.
  // To use this, replace pid_wait with pid_wait_quick_chain.
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  // Your final motion should still be a normal pid_wait
  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}

///
// Auto that tests everything
///
void combining_movements()
{
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, -45_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}

///
// Interference example
///
void tug(int attempts)
{
  for (int i = 0; i < attempts - 1; i++)
  {
    // Attempt to drive backward
    printf("i - %i", i);
    chassis.pid_drive_set(-12_in, 127);
    chassis.pid_wait();

    // If failsafed...
    if (chassis.interfered)
    {
      chassis.drive_sensor_reset();
      chassis.pid_drive_set(-2_in, 20);
      pros::delay(1000);
    }
    // If the robot successfully drove back, return
    else
    {
      return;
    }
  }
}

// If there is no interference, the robot will drive forward and turn 90 degrees.
// If interfered, the robot will drive forward and then attempt to drive backward.
void interfered_example()
{
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  if (chassis.interfered)
  {
    tug(3);
    return;
  }

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
}

///
// Odom Drive PID
///
void odom_drive_example()
{
  // This works the same as pid_drive_set, but it uses odom instead!
  // You can replace pid_drive_set with pid_odom_set and your robot will
  // have better error correction.

  chassis.pid_odom_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_odom_set(-12_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_odom_set(-12_in, DRIVE_SPEED);
  chassis.pid_wait();
}

///
// Odom Pure Pursuit
///
void odom_pure_pursuit_example()
{
  // Drive to 0, 30 and pass through 6, 10 and 0, 20 on the way, with slew
  chassis.pid_odom_set({{{6_in, 10_in}, fwd, DRIVE_SPEED},
                        {{0_in, 20_in}, fwd, DRIVE_SPEED},
                        {{0_in, 30_in}, fwd, DRIVE_SPEED}},
                       true);
  chassis.pid_wait();

  // Drive to 0, 0 backwards
  chassis.pid_odom_set({{0_in, 0_in}, rev, DRIVE_SPEED},
                       true);
  chassis.pid_wait();
}

///
// Odom Pure Pursuit Wait Until
///
void odom_pure_pursuit_wait_until_example()
{
  chassis.pid_odom_set({{{0_in, 24_in}, fwd, DRIVE_SPEED},
                        {{12_in, 24_in}, fwd, DRIVE_SPEED},
                        {{24_in, 24_in}, fwd, DRIVE_SPEED}},
                       true);
  chassis.pid_wait_until_index(1); // Waits until the robot passes 12, 24
  // Intake.move(127);  // Set your intake to start moving once it passes through the second point in the index
  chassis.pid_wait();
  // Intake.move(0);  // Turn the intake off
}

///
// Odom Boomerang
///
void odom_boomerang_example()
{
  chassis.pid_odom_set({{0_in, 24_in, 45_deg}, fwd, DRIVE_SPEED},
                       true);
  chassis.pid_wait();

  chassis.pid_odom_set({{0_in, 0_in, 0_deg}, rev, DRIVE_SPEED},
                       true);
  chassis.pid_wait();
}

///
// Odom Boomerang Injected Pure Pursuit
///
void odom_boomerang_injected_pure_pursuit_example()
{
  chassis.pid_odom_set({{{0_in, 24_in, 45_deg}, fwd, DRIVE_SPEED},
                        {{12_in, 24_in}, fwd, DRIVE_SPEED},
                        {{24_in, 24_in}, fwd, DRIVE_SPEED}},
                       true);
  chassis.pid_wait();

  chassis.pid_odom_set({{0_in, 0_in, 0_deg}, rev, DRIVE_SPEED},
                       true);
  chassis.pid_wait();
}

///
// Calculate the offsets of your tracking wheels
///
void measure_offsets()
{
  // Number of times to test
  int iterations = 10;

  // Our final offsets
  double l_offset = 0.0, r_offset = 0.0, b_offset = 0.0, f_offset = 0.0;

  // Reset all trackers if they exist
  if (chassis.odom_tracker_left != nullptr)
    chassis.odom_tracker_left->reset();
  if (chassis.odom_tracker_right != nullptr)
    chassis.odom_tracker_right->reset();
  if (chassis.odom_tracker_back != nullptr)
    chassis.odom_tracker_back->reset();
  if (chassis.odom_tracker_front != nullptr)
    chassis.odom_tracker_front->reset();

  for (int i = 0; i < iterations; i++)
  {
    // Reset pid targets and get ready for running an auton
    chassis.pid_targets_reset();
    chassis.drive_imu_reset();
    chassis.drive_sensor_reset();
    chassis.drive_brake_set(MOTOR_BRAKE_HOLD);
    chassis.odom_xyt_set(0_in, 0_in, 0_deg);
    double imu_start = chassis.odom_theta_get();
    double target = i % 2 == 0 ? 90 : 270; // Switch the turn target every run from 270 to 90

    // Turn to target at half power
    chassis.pid_turn_set(target, 63, ez::raw);
    chassis.pid_wait();
    pros::delay(250);

    // Calculate delta in angle
    double t_delta = util::to_rad(fabs(util::wrap_angle(chassis.odom_theta_get() - imu_start)));

    // Calculate delta in sensor values that exist
    double l_delta = chassis.odom_tracker_left != nullptr ? chassis.odom_tracker_left->get() : 0.0;
    double r_delta = chassis.odom_tracker_right != nullptr ? chassis.odom_tracker_right->get() : 0.0;
    double b_delta = chassis.odom_tracker_back != nullptr ? chassis.odom_tracker_back->get() : 0.0;
    double f_delta = chassis.odom_tracker_front != nullptr ? chassis.odom_tracker_front->get() : 0.0;

    // Calculate the radius that the robot traveled
    l_offset += l_delta / t_delta;
    r_offset += r_delta / t_delta;
    b_offset += b_delta / t_delta;
    f_offset += f_delta / t_delta;
  }

  // Average all offsets
  l_offset /= iterations;
  r_offset /= iterations;
  b_offset /= iterations;
  f_offset /= iterations;

  // Set new offsets to trackers that exist
  if (chassis.odom_tracker_left != nullptr)
    chassis.odom_tracker_left->distance_to_center_set(l_offset);
  if (chassis.odom_tracker_right != nullptr)
    chassis.odom_tracker_right->distance_to_center_set(r_offset);
  if (chassis.odom_tracker_back != nullptr)
    chassis.odom_tracker_back->distance_to_center_set(b_offset);
  if (chassis.odom_tracker_front != nullptr)
    chassis.odom_tracker_front->distance_to_center_set(f_offset);
}

// . . .
// Make your own autonomous functions here!
// . . .