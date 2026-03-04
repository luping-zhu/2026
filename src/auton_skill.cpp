#include "main.h"
#include "okapi/api/util/logging.hpp"
#include "okapi/impl/util/timeUtilFactory.hpp"

void setup_logger() {
    okapi::Logger::setDefaultLogger(
        std::make_shared<okapi::Logger>(
        okapi::TimeUtilFactory::createDefault().getTimer(), // Timer
        "/usd/robotLog.txt",                                // SD Card file path
        okapi::Logger::LogLevel::info                      // Log level
        )
    );
    // okapi::Logger::getDefaultLogger()->info("ttt");
    // okapi::Logger::getDefaultLogger()->close();
}

void check_velocity() {
  while (back_distance_sensor.get_object_velocity() > 0.02) {
    pros::delay(20);
  }
}

void matchloaddown2() {
    pros::delay(1200); 
    piston_bottom.set(true);
  }

void matchloaddownfor96skill() {
  pros::delay(400); //200
  piston_bottom.set(true);
  pros::delay(1100); //1300
  chassis.drive_set(0,0);
  piston_bottom.set(false);
}

void clearblueparkzonematchloaddownfor96() {
  pros::delay(350); //200
  piston_bottom.set(true);
  pros::delay(300);
  piston_bottom.set(false);
  // pros::delay(800);
  // piston_bottom.set(true);
}

void version3_autonskill() {
    default_constants();
    DRIVE_SPEED = 90;
    belt_intake.move(180);
    chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 90_ms, 250_ms);
    chassis.pid_drive_set(30_in, DRIVE_SPEED); //15
    chassis.pid_wait();
    chassis.pid_drive_exit_condition_set(90_ms, 1_in, 180_ms, 3_in, 90_ms, 180_ms);
    chassis.pid_drive_set(-6.5_in, DRIVE_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(30_in, DRIVE_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 500_ms, 500_ms);
  
    DRIVE_SPEED = 115;
    chassis.pid_drive_set(-27_in, DRIVE_SPEED, true);
    chassis.pid_wait();
    chassis.pid_turn_set(-90_deg, TURN_SPEED);
    chassis.pid_wait();
    check_velocity();
    back_distance = back_distance_sensor.get_distance() / 25.4;
    right_distance = right_distance_sensor.get_distance() / 25.4;
    chassis.pid_drive_set(-(back_distance - 18), DRIVE_SPEED, true); ///17.5
    chassis.pid_wait();
    piston_middle_intake.set(true);
    chassis.pid_turn_set(0_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(-(45 - right_distance), DRIVE_SPEED, true);
    chassis.pid_wait();
    top_intake.move(-90);
    pros::delay(2750);
  
    chassis.pid_turn_set(-1.5_deg, TURN_SPEED);
    chassis.pid_wait();
    piston_bottom.set(true);
    top_intake.move(0);
    chassis.pid_drive_set(31.8_in, DRIVE_SPEED, true); // 32.8
    chassis.pid_wait();
    pros::delay(900);
    chassis.pid_turn_set(-1.5_deg, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(-32_in, DRIVE_SPEED, true);
    chassis.pid_wait();
    top_intake.move(-180);
    piston_bottom.set(false);
    pros::delay(2350);
  
    chassis.pid_drive_set(8_in, DRIVE_SPEED, true); // 10
    chassis.pid_wait();
    chassis.pid_turn_set(-90_deg, TURN_SPEED);
    chassis.pid_wait();
    check_velocity();
    back_distance = back_distance_sensor.get_distance() / 25.4;
    chassis.pid_drive_set(30.8 - back_distance, DRIVE_SPEED); //30.3
    chassis.pid_wait();
    chassis.pid_turn_set(0_deg, TURN_SPEED);
    chassis.pid_wait();
    DRIVE_SPEED = 127;
    chassis.pid_drive_set(-74_in, DRIVE_SPEED, true);
    chassis.pid_wait();
    chassis.pid_turn_set(-90_deg, TURN_SPEED);
    chassis.pid_wait();
    check_velocity();
    back_distance = back_distance_sensor.get_distance() / 25.4;
    left_distance = left_distance_sensor.get_distance() / 25.4;
    chassis.pid_drive_set(-(back_distance - 17.1), DRIVE_SPEED, true);
    chassis.pid_wait();
    DRIVE_SPEED = 115;
    piston_bottom.set(true);
    chassis.pid_turn_set(180_deg, TURN_SPEED);
    chassis.pid_wait();
    top_intake.move(0);
    chassis.pid_drive_set(left_distance - 4.4, DRIVE_SPEED, true); //4
    chassis.pid_wait();
    pros::delay(900);
  
    chassis.pid_drive_set(-18_in, DRIVE_SPEED, true); //-17.5
    chassis.pid_wait();
    piston_bottom.set(false);
    chassis.pid_turn_set(90_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(-80_in, DRIVE_SPEED, true);
    chassis.pid_wait();
    check_velocity();
    right_distance = right_distance_sensor.get_distance() / 25.4;
    back_distance = back_distance_sensor.get_distance() / 25.4;
    chassis.pid_drive_set(-(back_distance - 18), DRIVE_SPEED, true); //16.5
    chassis.pid_wait();
    chassis.pid_turn_set(180_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(-(42 - right_distance), DRIVE_SPEED, true); //
    chassis.pid_wait();
    top_intake.move(-90);
    pros::delay(2350); //2050
  
    chassis.pid_turn_set(178.5_deg, TURN_SPEED); //////90
    chassis.pid_wait();
    belt_intake.move(180);
    piston_bottom.set(true);
    top_intake.move(0);
    chassis.pid_drive_set(31.8_in, DRIVE_SPEED, true); ////////32.3
    chassis.pid_wait();
    pros::delay(950); 
    chassis.pid_turn_set(178.5_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(-32_in, DRIVE_SPEED, true);
    chassis.pid_wait();
    top_intake.move(-180);
    piston_bottom.set(false);
    pros::delay(2350); //2050
  
    chassis.pid_drive_set(10_in, DRIVE_SPEED, true);
    chassis.pid_wait();
    chassis.pid_turn_set(90_deg, TURN_SPEED);
    chassis.pid_wait();
    piston_bottom.set(false);
    check_velocity();
    back_distance = back_distance_sensor.get_distance() / 25.4;
    chassis.pid_drive_set(31.3 - back_distance, DRIVE_SPEED); //30.3
    chassis.pid_wait();
    chassis.pid_turn_set(180_deg, TURN_SPEED);
    chassis.pid_wait();
    DRIVE_SPEED = 127;
    chassis.pid_drive_set(-75_in, DRIVE_SPEED, true); //74
    chassis.pid_wait();
    chassis.pid_turn_set(90_deg, TURN_SPEED);
    chassis.pid_wait();
    check_velocity();
    back_distance = back_distance_sensor.get_distance() / 25.4;
    left_distance = left_distance_sensor.get_distance() / 25.4;
    chassis.pid_drive_set(-(back_distance - 18.6), DRIVE_SPEED, true); //17.1
    chassis.pid_wait();
    piston_bottom.set(true);
    DRIVE_SPEED = 115;
    chassis.pid_turn_set(0_deg, TURN_SPEED);
    chassis.pid_wait();
    top_intake.move(0);
    chassis.pid_drive_set(left_distance - 4.4, DRIVE_SPEED, true); 
    chassis.pid_wait();
    pros::delay(900);
  
  
    DRIVE_SPEED = 127;
    chassis.pid_drive_set(-16_in, DRIVE_SPEED, true);
    chassis.pid_wait();
    piston_bottom.set(false);
    chassis.pid_turn_set(90_deg, TURN_SPEED);
    chassis.pid_wait();
    check_velocity();
    back_distance = back_distance_sensor.get_distance() / 25.4;
    top_intake.move(-180);
    chassis.pid_drive_set(66.5 - back_distance, DRIVE_SPEED, true); //65.5
    chassis.pid_wait();
    chassis.pid_turn_set(0_deg, TURN_SPEED);
    chassis.pid_wait();
    DRIVE_SPEED = 127;
    belt_intake.move(180);
    chassis.pid_drive_set(60_in, DRIVE_SPEED, true);
    chassis.pid_wait();
  }
  
void new_skill() {
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
    top_intake.move(-90);
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
    top_intake.move(-90);
    pros::delay(3500); // 2350
    top_intake.move(0);
    chassis.pid_turn_set(92_deg, TURN_SPEED); //////90
    chassis.pid_wait();
  
    piston_bottom.set(true);
    chassis.pid_drive_set(32.3_in, DRIVE_SPEED, true); //////32.8
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
  
void auton_skill() {
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

void stop_in_parking() {
  pros::delay(1500);
  chassis.drive_set(0,0);
}

void align_middle_driver() {
  drive_example();
  //writing 4th gen auto skill with 7 in middle goal yay
  DRIVE_SPEED = 110;


  //new_constants();
  DRIVE_SPEED = 90;
  //top_intake.move(-18);
  DRIVE_SPEED = 90;
  
  
  chassis.pid_turn_set(-90_deg, DRIVE_SPEED);
  chassis.pid_wait();
  check_velocity();
  right_distance = right_distance_sensor.get_distance() / 25.4;
  back_distance = back_distance_sensor.get_distance() / 25.4;
  // back_distance_sensor.get_object_velocity()
  chassis.pid_drive_set(-(back_distance - 39), DRIVE_SPEED, true); //38.5
  chassis.pid_wait();
  chassis.pid_turn_set(180_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(40 - right_distance, DRIVE_SPEED, true);
  chassis.pid_wait();
  //belt_intake.move(0);

  chassis.pid_turn_set(48_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-21.2_in, DRIVE_SPEED, true); 
  chassis.pid_wait();
}

void test() {

  drive_example();
  //writing 4th gen auto skill with 7 in middle goal yay
  DRIVE_SPEED = 110;


  //new_constants();
  DRIVE_SPEED = 90;
  //top_intake.move(-18);
  DRIVE_SPEED = 90;
  belt_intake.move(180);

  
  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 90_ms, 250_ms);
  chassis.pid_drive_set(40_in, DRIVE_SPEED); //15
  chassis.pid_wait();
  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 180_ms, 3_in, 90_ms, 180_ms); //50, 180 for last two
  chassis.pid_drive_set(-6_in, DRIVE_SPEED); //-6.5
  chassis.pid_wait();
  chassis.pid_drive_set(40_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 500_ms, 500_ms);

  DRIVE_SPEED = 110; //115
  chassis.pid_drive_set(-26_in, DRIVE_SPEED, true); //-27
  chassis.pid_wait();
  chassis.pid_turn_set(-90_deg, DRIVE_SPEED);
  chassis.pid_wait();
  check_velocity();
  right_distance = right_distance_sensor.get_distance() / 25.4;
  back_distance = back_distance_sensor.get_distance() / 25.4;
  // back_distance_sensor.get_object_velocity()
  chassis.pid_drive_set(-(back_distance - 39), DRIVE_SPEED, true); //38.5
  chassis.pid_wait();
  chassis.pid_turn_set(180_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(40 - right_distance, DRIVE_SPEED, true);
  chassis.pid_wait();
  //belt_intake.move(0);

  chassis.pid_turn_set(48_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-21.7_in, DRIVE_SPEED, true); //-21.2
  chassis.pid_wait();

  //top_intake.move(-55);
  top_intake.move_velocity(-185); //185
  belt_intake.move(180);
  pros::delay(1200);
  top_intake.move_velocity(-175); //200
  pros::delay(1200);
  top_intake.move_velocity(-185); //-220
  pros::delay(1250); //1200
  top_intake.move(0);

  chassis.pid_drive_set(1_in, DRIVE_SPEED, true); //1.5
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(-4_in, DRIVE_SPEED, true); //-4.5
  chassis.pid_wait();

  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 100_ms, 500_ms);

  // chassis.pid_drive_set(1.5_in, DRIVE_SPEED, true);
  // chassis.pid_wait_quick_chain();
  // chassis.pid_drive_set(-4.5_in, DRIVE_SPEED, true); //-1.6
  // chassis.pid_wait();


  //going to first matchload
  
  chassis.pid_drive_set(49.5_in, DRIVE_SPEED, true); // 49
  chassis.pid_wait();
  piston_middle_intake.set(true);
  piston_bottom.set(true);
  chassis.pid_turn_set(0_deg, TURN_SPEED); // 180
  chassis.pid_wait();
  belt_intake.move(180);
  piston_bottom.set(true);
  chassis.pid_drive_set(15.5_in, DRIVE_SPEED, true); //16
  chassis.pid_wait();
  pros::delay(1400); //1300


  
  chassis.pid_drive_set(-16_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  piston_bottom.set(false);
  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  check_velocity();
  back_distance = back_distance_sensor.get_distance() / 25.4;
  chassis.pid_drive_set(33 - back_distance, DRIVE_SPEED, true); // 33.5
  chassis.pid_wait();
  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  long_distance(-80);
  //chassis.pid_drive_set(-80_in, DRIVE_SPEED, true);
  //chassis.pid_wait();
  //DRIVE_SPEED = 95;

  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  check_velocity();
  left_distance = left_distance_sensor.get_distance() / 25.4;
  back_distance = back_distance_sensor.get_distance() / 25.4;
  chassis.pid_drive_set(-(back_distance - 17.5), DRIVE_SPEED, true); // 17.1
  chassis.pid_wait();
  chassis.pid_turn_set(180_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(-(40 - left_distance), DRIVE_SPEED, true);
  chassis.pid_wait();
  top_intake.move(-95); //-180
  pros::delay(1300); ////1450

  chassis.pid_turn_set(-176.5_deg, TURN_SPEED); //////-175.3
  chassis.pid_wait_quick_chain();
  top_intake.move(0);

  belt_intake.move(180);
  piston_bottom.set(true);
  chassis.pid_drive_set(30_in, DRIVE_SPEED, true); //29.5
  chassis.pid_wait();
  pros::delay(1350); //////730
  chassis.pid_turn_set(-176.5_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(-31_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  top_intake.move(-180);
  piston_bottom.set(false);
  pros::delay(2050); ////2150
  top_intake.move(0);




  chassis.pid_drive_set(9_in, DRIVE_SPEED, true); //8
  chassis.pid_wait();
  chassis.pid_turn_set(90_deg, TURN_SPEED); //180
  chassis.pid_wait();
  long_distance(-78);
  // chassis.pid_drive_set(-78_in, DRIVE_SPEED, true);
  //chassis.pid_wait();
  check_velocity();
  right_distance = right_distance_sensor.get_distance() / 25.4;
  back_distance = back_distance_sensor.get_distance() / 25.4;
  chassis.pid_drive_set(-(back_distance - 18), DRIVE_SPEED, true); //16
  chassis.pid_wait();
  piston_bottom.set(true);
  chassis.pid_turn_set(180_deg, DRIVE_SPEED, true); //-90
  chassis.pid_wait();

  chassis.pid_drive_set(right_distance - 7, DRIVE_SPEED, true); //6.5
  chassis.pid_wait();
  pros::delay(1250); //1100

  chassis.pid_turn_set(180_deg, TURN_SPEED); //-90
  chassis.pid_wait();
  chassis.pid_drive_set(-16_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  piston_bottom.set(false);
  chassis.pid_turn_set(-90_deg, TURN_SPEED); //0
  chassis.pid_wait();

  chassis.pid_drive_set(-14_in, DRIVE_SPEED, true); //-14.5
  chassis.pid_wait();
  chassis.pid_turn_set(180_deg, TURN_SPEED); //-90
  chassis.pid_wait();

  long_distance(-80);
  //chassis.pid_drive_set(-80_in, DRIVE_SPEED, true);
  //chassis.pid_wait();
  DRIVE_SPEED = 95;
  chassis.pid_turn_set(90_deg, TURN_SPEED); //180
  chassis.pid_wait();
  check_velocity();
  left_distance = left_distance_sensor.get_distance() / 25.4;
  back_distance = back_distance_sensor.get_distance() / 25.4;
  piston_middle_intake.set(true);
  chassis.pid_drive_set(-(back_distance - 17), DRIVE_SPEED, true); //// 16.5
  chassis.pid_wait();
  chassis.pid_turn_set(0_deg, TURN_SPEED); //90
  chassis.pid_wait();
  chassis.pid_drive_set(-(40 - left_distance), DRIVE_SPEED, true);
  chassis.pid_wait();
  top_intake.move(-100);
  pros::delay(2200); //2150
  top_intake.move(0);
  chassis.pid_turn_set(4_deg, TURN_SPEED); //6
  chassis.pid_wait();

  piston_bottom.set(true);
  chassis.pid_drive_set(29.6_in, DRIVE_SPEED, true); //30
  chassis.pid_wait();
  pros::delay(1400); //1300
  chassis.pid_turn_set(4_deg, TURN_SPEED); //6
  chassis.pid_wait();
  chassis.pid_drive_set(-32_in, DRIVE_SPEED, true); //////-30.5
  chassis.pid_wait();
  top_intake.move(-180);
  piston_bottom.set(false);
  pros::delay(2050); //2150
  top_intake.move(0);

  //GOING TO PARK
  

  DRIVE_SPEED = 127;
  chassis.drive_angle_set(90);
  chassis.pid_swing_set(ez::LEFT_SWING, 129_deg, SWING_SPEED, 30);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(27_in, DRIVE_SPEED, true); //26
  chassis.pid_wait();
  chassis.pid_swing_set(ez::LEFT_SWING, 174_deg, SWING_SPEED, 0);
  chassis.pid_wait_quick_chain();
  belt_intake.move(180);
  //DRIVE_SPEED = 110;

  pros::Task task1(stop_in_parking);
  chassis.pid_drive_set(50_in, DRIVE_SPEED); //true //49
  
}

void auton_91_skill() {
    drive_example();
    DRIVE_SPEED = 110;
    TURN_SPEED = 90;

    belt_intake.move(180);

    //red clearup
    DRIVE_SPEED = 110;
    chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 90_ms, 250_ms);
    chassis.pid_drive_set(30_in, DRIVE_SPEED); //15
    chassis.pid_wait();
    chassis.pid_drive_exit_condition_set(90_ms, 1_in, 180_ms, 3_in, 90_ms, 180_ms); //50, 180 for last two
    DRIVE_SPEED = 110;
    chassis.pid_drive_set(-6_in, DRIVE_SPEED); //-6 kljlk
    chassis.pid_wait();
    chassis.pid_drive_set(30_in, DRIVE_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 500_ms, 500_ms);
  
    chassis.pid_drive_set(-26_in, DRIVE_SPEED, true); //-27
    chassis.pid_wait();
    DRIVE_SPEED = 90;
    chassis.pid_turn_set(-90_deg, DRIVE_SPEED);
    chassis.pid_wait();
    check_velocity();
    right_distance = right_distance_sensor.get_distance() / 25.4;
    back_distance = back_distance_sensor.get_distance() / 25.4;
    chassis.pid_drive_set(-(back_distance - 39), DRIVE_SPEED, true); //38.5
    chassis.pid_wait();
    chassis.pid_turn_set(180_deg, TURN_SPEED);
    chassis.pid_wait();
  
    chassis.pid_drive_set(40 - right_distance, DRIVE_SPEED, true);
    chassis.pid_wait();
  
    chassis.pid_turn_set(48_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(-21_in, DRIVE_SPEED, true); //-21.7
    chassis.pid_wait();
  
    // top_intake.move_velocity(-185);
    // belt_intake.move(180);
    // pros::delay(1200);
    // top_intake.move_velocity(-175);
    // pros::delay(1200);
    // top_intake.move_velocity(-185); 
    // pros::delay(1250); 

    top_intake.move_velocity(-160); //180
    //belt_intake.move_velocity(400); //450
    pros::delay(3000);
    top_intake.move_velocity(-260); //260
    pros::delay(1200); //1000
    top_intake.move(0);
  
    chassis.pid_drive_set(1_in, DRIVE_SPEED, true); 
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(-4_in, DRIVE_SPEED, true); 
    chassis.pid_wait();
  
    DRIVE_SPEED = 110;
    belt_intake.move(180);

    chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 100_ms, 500_ms);
  
    //going to first matchload
    
    chassis.pid_drive_set(50_in, DRIVE_SPEED, true); // 49.5
    chassis.pid_wait();
    piston_middle_intake.set(true);
    piston_bottom.set(true);
    chassis.pid_turn_set(0_deg, TURN_SPEED); // 180
    chassis.pid_wait();
    belt_intake.move(180);
    piston_bottom.set(true);
    chassis.pid_drive_set(15.5_in, DRIVE_SPEED, true); //16
    chassis.pid_wait();
    pros::delay(1700); //1300
  
  
    chassis.pid_swing_set(ez::LEFT_SWING, -50_deg, SWING_SPEED, 45);
    chassis.pid_wait();
  
    chassis.pid_swing_set(ez::RIGHT_SWING, 0_deg, SWING_SPEED, 37);
    chassis.pid_wait();
  
  
    chassis.pid_drive_set(-66_in, DRIVE_SPEED, true); //66 CHANGE LATER
    piston_bottom.set(false);
    chassis.pid_wait();
  
    back_distance = back_distance_sensor.get_distance() / 25.4;
    if (back_distance > 33) {
      chassis.pid_drive_set(-(back_distance - 30), DRIVE_SPEED, true); //24
      chassis.pid_wait();
    } 
    else if (back_distance < 12) {
      chassis.pid_drive_set(- (back_distance - 30), DRIVE_SPEED, true); //
      chassis.pid_wait();
    }
  
    chassis.pid_turn_set(-90_deg, TURN_SPEED);
    chassis.pid_wait();
  
    left_distance = left_distance_sensor.get_distance() / 25.4;
    back_distance = back_distance_sensor.get_distance() / 25.4;
    chassis.pid_drive_set(-(back_distance - 17.5), DRIVE_SPEED, true); // 17.1
    chassis.pid_wait();
    chassis.pid_turn_set(180_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(-(39.5 - left_distance), DRIVE_SPEED, true); //40
    chassis.pid_wait();
    top_intake.move(-95); //-180
    pros::delay(2100); ////1900
  
  
  
    chassis.pid_turn_set(-178_deg, TURN_SPEED); //////-175.3
    chassis.pid_wait();
    top_intake.move(0);
  
    belt_intake.move(180);
    piston_bottom.set(true);
    chassis.pid_drive_set(30_in, DRIVE_SPEED, true); //29.5
    chassis.pid_wait();
    pros::delay(1600); //////1350
    chassis.pid_turn_set(-178_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(-31_in, DRIVE_SPEED, true);
    chassis.pid_wait();
    top_intake.move(-180);
    piston_bottom.set(false);
    pros::delay(2250); ////2050
    top_intake.move(0);
  
  
    //going to third matchload
    chassis.pid_drive_set(9_in, DRIVE_SPEED, true); //8
    chassis.pid_wait();
    chassis.pid_turn_set(90_deg, TURN_SPEED); //180
    chassis.pid_wait();
    long_distance(-78);
    check_velocity();
    right_distance = right_distance_sensor.get_distance() / 25.4;
    back_distance = back_distance_sensor.get_distance() / 25.4;
    chassis.pid_drive_set(-(back_distance - 18), DRIVE_SPEED, true); //16
    chassis.pid_wait();
    piston_bottom.set(true);
    chassis.pid_turn_set(180_deg, DRIVE_SPEED, true); //-90
    chassis.pid_wait();
    chassis.pid_drive_set(right_distance - 7, DRIVE_SPEED, true); //6.5
    chassis.pid_wait();
    pros::delay(1600); //1350
  
  
  
    chassis.pid_swing_set(ez::LEFT_SWING, 130_deg, SWING_SPEED, 45); //-50
    chassis.pid_wait();
  
    chassis.pid_swing_set(ez::RIGHT_SWING, 180_deg, SWING_SPEED, 37); //0
    chassis.pid_wait();
  
  
    chassis.pid_drive_set(-66_in, DRIVE_SPEED, true); //66 CHANGE LATER
    piston_bottom.set(false);
    chassis.pid_wait();
  
    back_distance = back_distance_sensor.get_distance() / 25.4;
    if (back_distance > 33) {
      chassis.pid_drive_set(-(back_distance - 30), DRIVE_SPEED, true); //24
      chassis.pid_wait();
    } 
    else if (back_distance < 12) {
      chassis.pid_drive_set(- (back_distance - 30), DRIVE_SPEED, true); //
      chassis.pid_wait();
    }
  
    chassis.pid_turn_set(90_deg, TURN_SPEED);
    chassis.pid_wait();
  
    left_distance = left_distance_sensor.get_distance() / 25.4;
    back_distance = back_distance_sensor.get_distance() / 25.4;
    chassis.pid_drive_set(-(back_distance - 17.5), DRIVE_SPEED, true); // 17.1
    chassis.pid_wait();
    chassis.pid_turn_set(0_deg, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(-(39.5 - left_distance), DRIVE_SPEED, true); //40
    chassis.pid_wait();
    top_intake.move(-95); //-180
    pros::delay(2250); ////2050
    top_intake.move(0);
  
    chassis.pid_turn_set(3_deg, TURN_SPEED); //6
    chassis.pid_wait();
  
    piston_bottom.set(true);
    chassis.pid_drive_set(29.8_in, DRIVE_SPEED, true); //29.6
    chassis.pid_wait();
    pros::delay(1600); //1300
    chassis.pid_turn_set(3_deg, TURN_SPEED); //6
    chassis.pid_wait();
    chassis.pid_drive_set(-32.5_in, DRIVE_SPEED, true); //////-32.5
    chassis.pid_wait();
    top_intake.move(-180);
    piston_bottom.set(false);
    pros::delay(2450); //2250
    top_intake.move(0);
  
  
    //GOING TO PARK
    
  
    DRIVE_SPEED = 127;
    chassis.drive_angle_set(90);
    chassis.pid_swing_set(ez::LEFT_SWING, 129_deg, SWING_SPEED, 30);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(27_in, DRIVE_SPEED, true); //26
    chassis.pid_wait();
    chassis.pid_swing_set(ez::LEFT_SWING, 174_deg, SWING_SPEED, 0);
    chassis.pid_wait_quick_chain();
    belt_intake.move(180);
    //DRIVE_SPEED = 110;
  
    pros::Task task1(stop_in_parking);
    chassis.pid_drive_set(50_in, DRIVE_SPEED); //true //49
  
}

void auton_96_skill() {

    outtakingonlonggoaltime = 2000; //1950
    intakingmatchloadtime = 1250;


    drive_example();
    DRIVE_SPEED = 110;
    TURN_SPEED = 90;

    chassis.drive_angle_set(180);



    belt_intake.move(180);

    chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 350_ms, 350_ms);
    chassis.pid_turn_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);

    /*
    back_distance = back_distance_sensor.get_distance() / 25.4;
    chassis.pid_drive_set(49 - back_distance, DRIVE_SPEED, true);
    chassis.pid_wait();
    chassis.pid_turn_set(45_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(-6.5_in, DRIVE_SPEED, true);
    chassis.pid_wait();

    top_intake.move(-180);
    pros::delay(500);
    top_intake.move(0);

  
    //going to first matchload
    
    chassis.pid_drive_set(50_in, DRIVE_SPEED, true); // 49.5
    chassis.pid_wait();
    piston_middle_intake.set(true);
    piston_bottom.set(true);
    chassis.pid_turn_set(0_deg, TURN_SPEED); // 180
    chassis.pid_wait();
    belt_intake.move(180);
    piston_bottom.set(true);
    chassis.pid_drive_set(15_in, DRIVE_SPEED, true); //15.5
    chassis.pid_wait();
    pros::delay(intakingmatchloadtime); //1300
  
  
    chassis.pid_swing_set(ez::LEFT_SWING, -50_deg, SWING_SPEED, 45);
    chassis.pid_wait();
  
    chassis.pid_swing_set(ez::RIGHT_SWING, 0_deg, SWING_SPEED, 37);
    chassis.pid_wait();
  
  
    chassis.pid_drive_set(-61_in, DRIVE_SPEED, true); //-66
    piston_bottom.set(false);
    chassis.pid_wait();
  
    back_distance = back_distance_sensor.get_distance() / 25.4;
    if (back_distance > 33) {
      chassis.pid_drive_set(-(back_distance - 30), DRIVE_SPEED, true); //24
      chassis.pid_wait();
    } 
    else if (back_distance < 12) {
      chassis.pid_drive_set(- (back_distance - 30), DRIVE_SPEED, true); //
      chassis.pid_wait();
    }
  
    chassis.pid_turn_set(-90_deg, TURN_SPEED);
    chassis.pid_wait();
  
    left_distance = left_distance_sensor.get_distance() / 25.4;
    back_distance = back_distance_sensor.get_distance() / 25.4;
    chassis.pid_drive_set(-(back_distance - 17.5), DRIVE_SPEED, true); // 17.1
    chassis.pid_wait();
    chassis.pid_turn_set(180_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(-(39.5 - left_distance), DRIVE_SPEED, true); //40
    chassis.pid_wait();
    top_intake.move(-95); //-180
    pros::delay(outtakingonlonggoaltime); ////1900
  
  
  
    chassis.pid_turn_set(-178_deg, TURN_SPEED); //////-175.3
    chassis.pid_wait();
    top_intake.move(0);
  
    belt_intake.move(180);
    piston_bottom.set(true);
    chassis.pid_drive_set(30_in, DRIVE_SPEED, true); //29.5
    chassis.pid_wait();
    pros::delay(intakingmatchloadtime); //////1350
    chassis.pid_turn_set(-178_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(-31_in, DRIVE_SPEED, true);
    chassis.pid_wait();
    top_intake.move(-180);
    piston_bottom.set(false);
    pros::delay(outtakingonlonggoaltime); ////2050
    top_intake.move(0);

    //add swing replace slow movements
    */

    chassis.pid_swing_set(ez::LEFT_SWING, -91.5_deg, SWING_SPEED, 53);
    chassis.pid_wait();
    pros::Task task1(clearblueparkzonematchloaddownfor96);
    chassis.pid_drive_set(95_in, DRIVE_SPEED); //true //49
    chassis.pid_wait();
    chassis.pid_turn_set(0_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(13_in, DRIVE_SPEED, true); //15
    chassis.pid_wait();
    // right_distance = right_distance_sensor.get_distance() / 25.4;
    chassis.pid_turn_set(90_deg, TURN_SPEED);
    top_intake.move(-180);
    chassis.pid_wait();
    right_distance = right_distance_sensor.get_distance() / 25.4;

    back_distance = back_distance_sensor.get_distance() / 25.4;
    chassis.pid_drive_set(-(back_distance - 19), DRIVE_SPEED, true); //18
    chassis.pid_wait();
    piston_bottom.set(true);
    chassis.pid_turn_set(180_deg, DRIVE_SPEED, true); //-90
    chassis.pid_wait();
    chassis.pid_drive_set(right_distance - 7, DRIVE_SPEED, true); //7
    top_intake.move(0);
    chassis.pid_wait();
    pros::delay(intakingmatchloadtime);
    /*

    chassis.pid_drive_set(9_in, DRIVE_SPEED, true);
    chassis.pid_wait();
    chassis.pid_turn_set(-90_deg, TURN_SPEED);
    chassis.pid_wait();
    piston_middle_intake.set(false);
    back_distance = back_distance_sensor.get_distance() / 25.4;
    chassis.pid_drive_set(68 - back_distance, DRIVE_SPEED, true); //67.5
    chassis.pid_wait();
    left_distance = left_distance_sensor.get_distance() / 25.4;
    chassis.pid_turn_set(180_deg, TURN_SPEED);
    chassis.pid_wait();
    
    chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 90_ms, 350_ms);
    chassis.pid_drive_set(left_distance + 20, DRIVE_SPEED); //15
    chassis.pid_wait();
    chassis.pid_drive_exit_condition_set(90_ms, 1_in, 180_ms, 3_in, 90_ms, 180_ms); //50, 180 for last two
    DRIVE_SPEED = 110;
    chassis.pid_drive_set(-6_in, DRIVE_SPEED); //-6 kljlk
    chassis.pid_wait();
    chassis.pid_drive_set(40_in, DRIVE_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 250_ms, 350_ms);

    chassis.pid_drive_set(-26_in, DRIVE_SPEED, true);
    chassis.pid_wait();

    chassis.pid_turn_set(90_deg, TURN_SPEED);
    chassis.pid_wait();
    back_distance = back_distance_sensor.get_distance() / 25.4;
    chassis.pid_drive_set(-(back_distance - 49), DRIVE_SPEED, true);
    chassis.pid_wait();
    chassis.pid_turn_set(0_deg, TURN_SPEED);
    chassis.pid_wait();

    back_distance = back_distance_sensor.get_distance() / 25.4;
    chassis.pid_drive_set(48 - back_distance, DRIVE_SPEED, true);
    chassis.pid_wait();
    chassis.pid_turn_set(-135_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(-7_in, DRIVE_SPEED, true); //6.5
    chassis.pid_wait();

 
    // top_intake.move_velocity(-180); 
    // pros::delay(3500);
    // top_intake.move(0);

    top_intake.move_velocity(-160); 
    pros::delay(3000);
    top_intake.move_velocity(-260);
    pros::delay(500);
    top_intake.move(0);

    chassis.pid_drive_set(1_in, DRIVE_SPEED, true); 
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(-4_in, DRIVE_SPEED, true); 
    chassis.pid_wait();

    ///*

    //going to third matchload
    chassis.pid_drive_set(50.5_in, DRIVE_SPEED, true); // 50
    chassis.pid_wait();
    piston_middle_intake.set(true);
    piston_bottom.set(true);
    chassis.pid_turn_set(180_deg, TURN_SPEED); // 0
    chassis.pid_wait();
    belt_intake.move(180);
    piston_bottom.set(true);
    chassis.pid_drive_set(14.5_in, DRIVE_SPEED, true); //15
    chassis.pid_wait();
    pros::delay(intakingmatchloadtime); //1350
  
  
  
    chassis.pid_swing_set(ez::LEFT_SWING, 130_deg, SWING_SPEED, 45); //-50
    chassis.pid_wait();
  
    chassis.pid_swing_set(ez::RIGHT_SWING, 180_deg, SWING_SPEED, 37); //0
    chassis.pid_wait();
  
  
    chassis.pid_drive_set(-61_in, DRIVE_SPEED, true); //66 CHANGE LATER
    piston_bottom.set(false);
    chassis.pid_wait();
  
    back_distance = back_distance_sensor.get_distance() / 25.4;
    if (back_distance > 33) {
      chassis.pid_drive_set(-(back_distance - 30), DRIVE_SPEED, true); //24
      chassis.pid_wait();
    } 
    else if (back_distance < 12) {
      chassis.pid_drive_set(- (back_distance - 30), DRIVE_SPEED, true); //
      chassis.pid_wait();
    }
  
    chassis.pid_turn_set(90_deg, TURN_SPEED);
    chassis.pid_wait();
  
    left_distance = left_distance_sensor.get_distance() / 25.4;
    back_distance = back_distance_sensor.get_distance() / 25.4;
    chassis.pid_drive_set(-(back_distance - 17.5), DRIVE_SPEED, true); // 17.1
    chassis.pid_wait();
    chassis.pid_turn_set(0_deg, TURN_SPEED);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(-(39.5 - left_distance), DRIVE_SPEED, true); //40
    chassis.pid_wait();
    top_intake.move(-95); //-180
    pros::delay(outtakingonlonggoaltime); ////2050
    top_intake.move(0);
  
    chassis.pid_turn_set(3_deg, TURN_SPEED); //6
    chassis.pid_wait();
  
    piston_bottom.set(true);
    chassis.pid_drive_set(29.8_in, DRIVE_SPEED, true); //29.6
    chassis.pid_wait();
    pros::delay(intakingmatchloadtime); //1300
    chassis.pid_turn_set(3_deg, TURN_SPEED); //6
    chassis.pid_wait();
    chassis.pid_drive_set(-32.5_in, DRIVE_SPEED, true); //////-32.5
    chassis.pid_wait();
    top_intake.move(-180);
    piston_bottom.set(false);
    pros::delay(outtakingonlonggoaltime); //2250
    top_intake.move(0);


  
  
    //GOING TO PARK
    
  
    DRIVE_SPEED = 127;
    // chassis.drive_angle_set(90);
    // chassis.pid_swing_set(ez::LEFT_SWING, 129_deg, SWING_SPEED, 30);
    // chassis.pid_wait_quick_chain();
    // chassis.pid_drive_set(27_in, DRIVE_SPEED, true); //26
    // chassis.pid_wait();
    // chassis.pid_swing_set(ez::LEFT_SWING, 174_deg, SWING_SPEED, 0);
    // chassis.pid_wait_quick_chain();
    // belt_intake.move(180);
    // //DRIVE_SPEED = 110;
  
    // pros::Task task1(matchloaddownfor96skill);
    // chassis.pid_drive_set(50_in, DRIVE_SPEED); //true //49

    chassis.pid_swing_set(ez::LEFT_SWING, 88.5_deg, SWING_SPEED, 53);
    chassis.pid_wait();
    pros::Task task2(matchloaddownfor96skill);
    chassis.pid_drive_set(50_in, DRIVE_SPEED); //true //49
    chassis.pid_wait();

    */

}