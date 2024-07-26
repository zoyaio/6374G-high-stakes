#pragma once
#include "api.h"
#include "intake.cpp"
#include "drivetrain.cpp"


class Robot {
    private:
        pros::Controller m_controller {pros::E_CONTROLLER_MASTER}; 

        //robot constructor
        Robot(Drivetrain drive, Intake intake);

        //robot components
        Intake intake;
        Drivetrain dt;

        //update robot components
        void update_intake(){
            //intakes rings
            if (m_controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) && intake.get_avg_velocity() == 0) {
                intake.set_direction(true); //spins intake in positive direction
                intake.set_voltage(12000); //spins at max voltage
            }
            if (m_controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) && intake.get_avg_velocity() != 0) {
                intake.set_voltage(0); //turns off intake
            }
            //deintakes rings
            if (m_controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
                intake.set_direction(false); //spins intake in opposite direction
                intake.set_voltage(12000);
            }
        }
        void update_drivetrain();

    public: 
        //update function for whole robot
        void update(std::string info);
};
