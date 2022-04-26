# Automation-of-Waste-Management

## Project Description
An IoT project aimed at improving the waste management system while simultaneously reducing human labor involved. Implemented using Arduino uno and other components such as ultrasonic sensors, servo motors, dc motors and a L293D motor driver.   

![image](https://user-images.githubusercontent.com/66276711/139736829-630f7808-6fab-48a6-8dca-bbbdc38b615f.png)  

The bot uses the motor driver and the DC motors to go around in a predefined path (The model is designed to travel an arbitrary rectangular path). This bot is designed to clean a close designed sewer system. As the bot is traversing the path, it uses an ultrasonic sensor to constantly monitor the objects nearby and its proximity to the bot. If the bot identifies an object to be present within a threshold limit (in the model's case, 100cm) the bot stops and uses a mechanical arm to claw into the sewer (or water body) and take out the waste. The mechanical arm is powered by a servo motor. Additionally, an led is used to show the bot working. When the bot identifies the object the led lights up. As the bot is done clawing out the waste, the led is turned off. Once its done taking out the waste, the bot continues along its path. Then the process is repeated.   
  
    
This project was designed to reduce manual labor and improve waste management conditions. It will improve efficiency and reduce the cost and time required to clean sewers. It will also reduce exposure of labourers to unsanitary and unhealthy conditions. The bot can also be adapted to clean other water bodies and even terrains.
