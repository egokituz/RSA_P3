/*
 * File:   Test.cpp
 * Author: @bgamecho
 * 
 * Test program for iRobot_Framework
 */

#include "Libs/iRobot_framework/IRobotConnection.h"

#define COM "/dev/ttyUSB0"

using namespace std;

void dec2bin(int dec) {
    if(dec!=0) dec2bin(dec/2);
    if(dec!=0) cout<<dec%2;
    if(dec==0) cout<<"\n";
}

int main(int argc, char**argv) {

    int sensor_value = 0, maxwallsignal = 0;
    int command = 0, count = 10;

    // Creamos un objeto robot
    IRobotConnection robot(COM);
    
    // Activamos el Verbose Mode
    robot.setVerboseMode(false);
    
    // Iniciamos la conexion...
    cout << "Connecting... ";
    if(robot.connect()!=1){ 
        cout << "Error\n" << endl;
        return EXIT_FAILURE;
    }
    cout << "Done!\n" << endl;
    //delay(500);
    
    // Comando 128 start
    cout << "Send start" << endl;
    robot.start();
    //delay(500);
    
    // Comando 132 modo full
    cout << "Send Full mode" << endl;
    robot.full();    // Ejecutamos el comando 142 35 y mostramos el resultado por pantalla
    cout << "Send OI mode request" << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::OIMODE);
    cout << "Modo de funcionamiento: " << +sensor_value << endl;
      
 
    //Ejemplo de uso del sensor BUMP y conversion dec -> bin

    cout << "Activate any combination of Bumpers and Wheel Drops" << endl;
    sensor_value = robot.updateSensor(iRobotSensors::BUMPERS_AND_WHEELDROPS);
    cout << "Bumps and Wheel Drops: " << +sensor_value << endl;
    if(dec!=0) dec2bin(+sensor_value/2);
    if(dec!=0) cout<<+sensor_value%2;
  
     // Leemos todos los sensores y los mostramos por pantalla
    cout << "Listamos todos los sensores de parado" << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::WALL);
    cout << "\nGroup 8 Wall: " << +sensor_value << endl;

    sensor_value = robot.updateSensor(iRobotSensors::CLIFFLEFT);
    cout << "Group 9 Cliff Left: " << +sensor_value << endl;

    sensor_value = robot.updateSensor(iRobotSensors::CLIFFFRONTLEFT);
    cout << "Group 10 Cliff Front Left: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::CLIFFFRONTRIGHT);
    cout << "Group 11 Cliff Front Right: " << +sensor_value << endl;

    sensor_value = robot.updateSensor(iRobotSensors::CLIFFRIGHT);
    cout << "Group 12 Cliff Right: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::VIRTUALWALL);
    cout << "Group 13 Virtual Wall: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::MOTOR_OVERCURRENTS);
    cout << "Group 14 Motor Overcurrents: " << +sensor_value << endl;
      
    sensor_value = robot.updateSensor(iRobotSensors::IRBYTE);
    cout << "Group 17 IR Byte: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::BUTTONS);
    cout << "Group 18 Buttons: " << +sensor_value << endl;
    dec2bin(+sensor_value);  
        
    sensor_value = robot.updateSensor(iRobotSensors::DISTANCE);
    cout << "Group 19 Distance: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::ANGLE);
    cout << "Groupo 20 Angle: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::CHARGINGSTATE);
    cout << "Group 21 Charging State: " << +sensor_value << endl;    
    
    sensor_value = robot.updateSensor(iRobotSensors::VOLTAGE);
    cout << "Group 22 Voltage: " << +sensor_value << endl;
      
    sensor_value = robot.updateSensor(iRobotSensors::CURRENT);
    cout << "Group 23 Current: " << +sensor_value << endl;
       
    sensor_value = robot.updateSensor(iRobotSensors::TEMPERATURE);
    cout << "Group 24 Temperature: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::CHARGE);
    cout << "Group 25 Charge: " << +sensor_value << endl;
       
    sensor_value = robot.updateSensor(iRobotSensors::CAPACITY);
    cout << "Group 26 Capacity: " << +sensor_value << endl;

    sensor_value = robot.updateSensor(iRobotSensors::WALLSIGNAL);
    cout << "Group 27 Wall Signal: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::CLIFFLEFTSIGNAL);
    cout << "Group 28 Cliff Left Signal: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::CLIFFFRONTLEFTSIGNAL);
    cout << "Group 29 Cliff Front Left Signal: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::CLIFFFRONTRIGHTSIGNAL);
    cout << "Group 30 Cliff Front Right Signal: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::CLIFFRIGHTSIGNAL);
    cout << "Group 31 Cliff Right Signal: " << +sensor_value << endl;
  
    sensor_value = robot.updateSensor(iRobotSensors::USERDIGITAL);
    cout << "Group 32 User Digital: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::USERANALOG);
    cout << "Group 33 User Analog: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::CHARGINGSOURCES);
    cout << "Group 34 Charging Sources: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::OIMODE);
    cout << "Group 35 OI Mode: " << +sensor_value << endl;
  
    sensor_value = robot.updateSensor(iRobotSensors::SONGNUMBER);
    cout << "Group 36 Song Number: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::SONGPLAYING);
    cout << "Group 37 Song Playing: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::STREAMPACKETS);
    cout << "Group 38 Stream packets: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::VELOCITY);
    cout << "Group 39 Velocity: " << +sensor_value << endl;
  
    sensor_value = robot.updateSensor(iRobotSensors::RADIUS);
    cout << "Group 40 Radius: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::RIGHTVELOCITY);
    cout << "Group 41 Right Velocity: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::LEFTVELOCITY);
    cout << "Group 42 Left Velocity: " << +sensor_value << endl;
    
    //Avanzamos durante 2 segundos a 200mm/s y paramos los motores
    cout << "Send drive direct" << endl;
    robot.driveDirect(250,150);
    delay (2000);
     cout << "Listamos todos los sensores en marcha" << endl;
    // Leemos los sensores y los mostramos por pantalla

    sensor_value = robot.updateSensor(iRobotSensors::BUMPERS_AND_WHEELDROPS);
    cout << "Bumps and Wheel Drops: " << +sensor_value << endl;
    if(dec!=0) dec2bin(+sensor_value/2);
    if(dec!=0) cout<<+sensor_value%2;
  
    sensor_value = robot.updateSensor(iRobotSensors::WALL);
    cout << "\nGroup 8 Wall: " << +sensor_value << endl;

    sensor_value = robot.updateSensor(iRobotSensors::CLIFFLEFT);
    cout << "Group 9 Cliff Left: " << +sensor_value << endl;

    sensor_value = robot.updateSensor(iRobotSensors::CLIFFFRONTLEFT);
    cout << "Group 10 Cliff Front Left: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::CLIFFFRONTRIGHT);
    cout << "Group 11 Cliff Front Right: " << +sensor_value << endl;

    sensor_value = robot.updateSensor(iRobotSensors::CLIFFRIGHT);
    cout << "Group 12 Cliff Right: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::VIRTUALWALL);
    cout << "Group 13 Virtual Wall: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::MOTOR_OVERCURRENTS);
    cout << "Group 14 Motor Overcurrents: " << +sensor_value << endl;
      
    sensor_value = robot.updateSensor(iRobotSensors::IRBYTE);
    cout << "Group 17 IR Byte: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::BUTTONS);
    cout << "Group 18 Buttons: " << +sensor_value << endl;
    dec2bin(+sensor_value);  
        
    sensor_value = robot.updateSensor(iRobotSensors::DISTANCE);
    cout << "Group 19 Distance: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::ANGLE);
    cout << "Groupo 20 Angle: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::CHARGINGSTATE);
    cout << "Group 21 Charging State: " << +sensor_value << endl;    
    
    sensor_value = robot.updateSensor(iRobotSensors::VOLTAGE);
    cout << "Group 22 Voltage: " << +sensor_value << endl;
      
    sensor_value = robot.updateSensor(iRobotSensors::CURRENT);
    cout << "Group 23 Current: " << +sensor_value << endl;
       
    sensor_value = robot.updateSensor(iRobotSensors::TEMPERATURE);
    cout << "Group 24 Temperature: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::CHARGE);
    cout << "Group 25 Charge: " << +sensor_value << endl;
       
    sensor_value = robot.updateSensor(iRobotSensors::CAPACITY);
    cout << "Group 26 Capacity: " << +sensor_value << endl;

    sensor_value = robot.updateSensor(iRobotSensors::WALLSIGNAL);
    cout << "Group 27 Wall Signal: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::CLIFFLEFTSIGNAL);
    cout << "Group 28 Cliff Left Signal: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::CLIFFFRONTLEFTSIGNAL);
    cout << "Group 29 Cliff Front Left Signal: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::CLIFFFRONTRIGHTSIGNAL);
    cout << "Group 30 Cliff Front Right Signal: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::CLIFFRIGHTSIGNAL);
    cout << "Group 31 Cliff Right Signal: " << +sensor_value << endl;
  
    sensor_value = robot.updateSensor(iRobotSensors::USERDIGITAL);
    cout << "Group 32 User Digital: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::USERANALOG);
    cout << "Group 33 User Analog: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::CHARGINGSOURCES);
    cout << "Group 34 Charging Sources: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::OIMODE);
    cout << "Group 35 OI Mode: " << +sensor_value << endl;
  
    sensor_value = robot.updateSensor(iRobotSensors::SONGNUMBER);
    cout << "Group 36 Song Number: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::SONGPLAYING);
    cout << "Group 37 Song Playing: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::STREAMPACKETS);
    cout << "Group 38 Stream packets: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::VELOCITY);
    cout << "Group 39 Velocity: " << +sensor_value << endl;
  
    sensor_value = robot.updateSensor(iRobotSensors::RADIUS);
    cout << "Group 40 Radius: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::RIGHTVELOCITY);
    cout << "Group 41 Right Velocity: " << +sensor_value << endl;
    
    sensor_value = robot.updateSensor(iRobotSensors::LEFTVELOCITY);
    cout << "Group 42 Left Velocity: " << +sensor_value << endl;

    robot.driveDirect(200,200);
    cout << "Then it stops" << endl;
    robot.driveDirect(0,0);
   
    
    // Desconectamos
    cout << "Disconnect from serial line" << endl;
    robot.disconnect();

    return EXIT_SUCCESS;
}
