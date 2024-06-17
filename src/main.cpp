#include "main.h"
#include "autons.hpp"
#include "ports.hpp"
#include "lemlib/api.hpp"

pros::Controller master {pros::E_CONTROLLER_MASTER}; 


pros::Motor left_front_motor(ports::LEFT_FRONT_TOP_DT, pros::E_MOTOR_GEARSET_06); // port 1, blue gearbox, not reversed
pros::Motor left_middle_motor(ports::LEFT_FRONT_BOTTOM_DT, pros::E_MOTOR_GEARSET_06); // port 1, blue gearbox, not reversed
pros::Motor left_back_motor(ports::LEFT_BACK_DT, pros::E_MOTOR_GEARSET_06); // port 2, green gearbox, not reversed

pros::Motor right_front_motor(ports::RIGHT_FRONT_TOP_DT, pros::E_MOTOR_GEARSET_06); // port 3, red gearbox, reversed
pros::Motor right_middle_motor(ports::RIGHT_FRONT_BOTTOM_DT, pros::E_MOTOR_GEARSET_06); // port 3, red gearbox, reversed
pros::Motor right_back_motor(ports::RIGHT_BACK_DT, pros::E_MOTOR_GEARSET_06); // port 4, red gearbox, reversed

pros::Motor_Group left_side_motors {{left_front_motor,left_middle_motor, left_back_motor}};
// left_side_motors.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
pros::Motor_Group right_side_motors = pros::Motor_Group{{right_front_motor, right_middle_motor, right_back_motor}};
// right_side_motors.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);




void screen() {
    
}

void initialize() {
  // Print our branding over your terminal :D
  pros::lcd::initialize(); // initialize brain screen
  pros::delay(500); // Stop the user from doing anything while legacy ports configure.
  // chassis.setPose(0, 0, 0);




}


void disabled() {
  // . . .
}

void competition_initialize() {

  pros::lcd::initialize(); // initialize brain screen
  pros::delay(500); // Stop the user from doing anything while legacy ports configure.


  // . . .
}





void opcontrol() {
  while (true) { 
    pros::delay(10); // This is used for timer calculations!  Keep this ez::util::DELAY_TIME
  
  }

}





void autonomous() {
  
  Intake intake = Intake {ports::INTAKE_MOTOR};
  Pneumatics wings = Pneumatics {ports::WING_PORT_BACK, ports::WING_PORT_FRONT_RIGHT, ports::WING_PORT_FRONT_LEFT, ports::RATCHET};
  Matchloader matchloader = Matchloader {ports::BIG_CATAPULT_MOTOR,ports::SMALL_CATAPULT_MOTOR };
  Climb climb = Climb {-ports::BIG_CATAPULT_MOTOR,ports::SMALL_CATAPULT_MOTOR, ports::ROTATIONAL_SENSOR  }; 

  std::printf("delaying..");
  pros::Task::delay(500) 


}
