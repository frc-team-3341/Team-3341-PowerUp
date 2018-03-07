#include <memory>
#include <iostream>

#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <iostream>
using namespace std;
#include "CommandBase.h"
#include "Commands/TankDrive.h"
#include "Commands/DriveForward.h"
#include "Commands/Turn.h"
#include "Commands/LSwitch.h"
#include "Commands/RSwitch.h"
#include "Commands/LScale.h"
#include "Commands/RScale.h"
#include "Commands/LScaleSwitch.h"
#include "Commands/LSwitchScale.h"
#include "Commands/Mid.h"
#include "Commands/RSwitchScale.h"
#include "Commands/RScaleSwitch.h"
#include "Commands/Auto_Right_Switch.h"
#include "Commands/Auto_Mid_LSwitch.h"
#include "Commands/Auto_Mid_RSwitch.h"
#include "Commands/Test_Mechs.h"
#include "Commands/Auto_Left_Switch.h"
#include "Commands/Auto_Left_LScale.h"


class Robot: public frc::IterativeRobot {

public:
	void RobotInit() override {
		CommandBase::initialize();
		cout << "comm-----" << endl;
				cout << "robot init" << endl;
				std::string s = frc::DriverStation::GetInstance().GetGameSpecificMessage();
				// Store the commands in the chooser, giving it ownership.
				// To dynamically allocate a shared_ptr<> with a new Turn command
				// these are equivalent:  std::shared_ptr<Turn>(new Turn(90.)
				//                        std::make_shared<Turn>(90.)
				//chooser.AddDefault("Default Auto - DriveForward", std::shared_ptr<DriveForward>(new DriveForward(100)));
				chooser.AddDefault("Default", std::shared_ptr<DriveForward>(new DriveForward(100)));

				//mid
				chooser.AddObject("Mid", std::shared_ptr<Mid>(new Mid(s)));
				chooser.AddObject("RightMid", std::shared_ptr<Auto_Mid_RSwitch>(new Auto_Mid_RSwitch()));
				chooser.AddObject("LeftMid", std::shared_ptr<Auto_Mid_LSwitch>(new Auto_Mid_LSwitch()));

				//left
				chooser.AddObject("Prioritize Scale Left", std::shared_ptr<LScaleSwitch>(new LScaleSwitch(s)));
				chooser.AddObject("Prioritize Switch Left", std::shared_ptr<LSwitchScale>(new LSwitchScale(s)));
				chooser.AddObject("Switch Left", std::shared_ptr<LSwitch>(new LSwitch("LLL")));
				chooser.AddObject("Scale Left", std::shared_ptr<LScale>(new LScale(s)));

				//right
				chooser.AddObject("Prioritize Scale Right", std::shared_ptr<RScaleSwitch>(new RScaleSwitch(s)));
				chooser.AddObject("Prioritize Switch Right", std::shared_ptr<RSwitchScale>(new RSwitchScale(s)));
				chooser.AddObject("Switch Right", std::shared_ptr<RSwitch>(new RSwitch(s)));
				chooser.AddObject("Scale Right", std::shared_ptr<RScale>(new RScale(s)));



				chooser.AddObject("TestMechanism",std::shared_ptr<Test_Mechs>(new Test_Mechs()));


				chooser.AddObject("Turn-90",std::shared_ptr<Turn>(new Turn(-90)));
				chooser.AddObject("Turn90",std::shared_ptr<Turn>(new Turn(90)));
				chooser.AddObject("Auto_Mid_Lswitch", std::shared_ptr<Auto_Mid_LSwitch>(new Auto_Mid_LSwitch()));
				chooser.AddObject("Auto_Mid_Rswitch", std::shared_ptr<Auto_Mid_RSwitch>(new Auto_Mid_RSwitch()));
				chooser.AddObject("100", std::shared_ptr<DriveForward>(new DriveForward(100)));
				//chooser.AddObject("Auto_L_switch", std::shared_ptr<Auto_Left_LScale>(new Auto_Left_LScale()));

				/*chooser.AddObject("75", std::shared_ptr<DriveForward>(new DriveForward(75)));
				chooser.AddObject("100", std::shared_ptr<DriveForward>(new DriveForward(100)));
				chooser.AddObject("150", std::shared_ptr<DriveForward>(new DriveForward(150)));
				chooser.AddObject("175", std::shared_ptr<DriveForward>(new DriveForward(175)));
				chooser.AddObject("200", std::shared_ptr<DriveForward>(new DriveForward(200)));
				// chooser.AddObject("Turn -90", std::make_shared<Turn>(-90.));*/

				//initCommand = chooser.GetSelected();

				frc::SmartDashboard::PutData("Auto Modes", &chooser);
		CameraServer::GetInstance()->StartAutomaticCapture();

	}

	/**
	 * This function is called once each time the robot enters Disabled mode.
	 * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
	 */
	void DisabledInit() override {
		if (!autonomousCommand.expired()) { // check if the autonomous command pointer is valid
			// convert the weak pointer to a std::shared_ptr<> to access its contents
			// In this case, we can use auto instead of "std::shared_ptr<frc::Command>"
			if (auto autonomousCommandSP = autonomousCommand.lock()) {
				// Cancel the command if it is running
				if (autonomousCommandSP->IsRunning()) {
					autonomousCommandSP->Cancel();
				}
			}
		}
	}

	void DisabledPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}
	/**
	 * This autonomous (along with the chooser code above) shows how to select
	 * between different autonomous modes using the dashboard. The sendable
	 * chooser code works with the Java SmartDashboard. If you prefer the
	 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
	 * GetString code to get the auto name from the text box below the Gyro.
	 *
	 * You can add additional auto modes by adding additional commands to the
	 * chooser code above (like the commented example) or additional comparisons
	 * to the if-else structure below with additional strings & commands.
	 */
	void AutonomousInit() override {
		std::string autoSelected = frc::SmartDashboard::GetString("Auto Selector", "Default");
		//cout << autoSelected << endl;
		/*if (autoSelected == "My Auto") {
			autonomousCommand.reset(new MyAutoCommand());
		}
		else {
			autonomousCommand.reset(new ExampleCommand());
		}*/

		std::cout<<"AutonomousInit Successful" <<std::endl;

		// Obtain the selected command, which will be a std::weak_ptr<frc::command>
		autonomousCommand = chooser.GetSelected();

		// check if the std::weak_ptr<> refers to something valid
		//if (!autonomousCommand.expifAutored()) {
			// convert the weak pointer to a std::shared_ptr<> to access its contents
			// In this case, we can use auto instead of "std::shared_ptr<frc::Command>"

			if (auto autonomousCommandSP = autonomousCommand.lock()) {
				//autonomousCommandSP->Start();
				autonomousCommand.lock()->Start();
			}
		//}
	}

	void AutonomousPeriodic() override {
		frc::Scheduler::GetInstance()->Run();

	}

	void TeleopInit() override {

		if (!autonomousCommand.expired()) { // check if the autonomous command pointer is valid
			// convert the weak pointer to a std::shared_ptr<> to access its contents
			// In this case, we can use auto instead of "std::shared_ptr<frc::Command>"
			if (auto autonomousCommandSP = autonomousCommand.lock()) {
				// Cancel the command if it is running
				if (autonomousCommandSP->IsRunning()) {
					autonomousCommandSP->Cancel();
				}
			}
		}
	}

	void TeleopPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}

	void TestPeriodic() override {
	//	frc::LiveWindow::GetInstance()->Run();
	}

private:
	std::weak_ptr<frc::Command> autonomousCommand; // command selected on driver station
	std::weak_ptr<frc::Command> initCommand; // command selected on driver station
	frc::SendableChooser<std::shared_ptr<frc::Command>> chooser;
};

START_ROBOT_CLASS(Robot)
