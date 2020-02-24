# ENGR 490 Capstone Project - Haptic Glove
## Project Overview
This is a multi-displinary capstone project involving [Concordia University](https://www.concordia.ca/) students in Mechanical Engineering and Software Engineering.

### Project Description
**Product Name:** GloVR

**Product Logo:** *Under construction*

This capstone project is a haptic feedback glove integrated with Unity to allow for VR applications that can, in the future, be potentially integrated to function with a robotic manipulator. The haptic feedback glove must be capable of both applying force feedback, which is accomplished using conventional DC motors, and tactile feedback, which is done using vibration motors. 

### Project Components
#### 1. Haptic Glove
This component contains the hand/finger design for the glove. In addition, it has sensors for force feedback, tactile feedback and motion detection. The communication between the sensors and the Virtual Environment is accomplished through an embedded system. This system will have a controll system to implement the desired feedback needed to interact with the objects in the simulation.
#### 2. Virtual Environment Simulation
This component will be developed using [unity](https://unity.com/), which allows us to create a virtual reality environment for the user to interact with. The simulation will interface with the glove by getting sensor data for finger movement, sending force feedback and tactile data. This repository contains the source code immplementation of the unity project for the simulation.

## Project Repository Overview
### Repository Contents Description
| Folder        | Content Description
| ------------- |-------------|
| HapticGloveProject/     | This is the main source code files for Unity |
| Mech Team/      | This is main area for Mechanical Engineering team to add documents related to them     |
| Software Team/ | This is main area for Software Engineering team to add documents related to them      |
| Documentation/ | General documentation needed for both teams      |

## Getting stared
### Requirements
  - Unity version 2018.4.12f1 
  > Note! This version is the one required to run to project. Other versions will overwrite everything and reset the project.
  
  - User equipment:
    - The Haptic Glove
    - [SteamVR](https://store.steampowered.com/)
    - [HTC Vive Pro](https://www.vive.com/us/product/vive-pro/) Headset (*This project was tested with Vive Pro, but any headset that works with SteamVR should work as well*)
    - [HTC Vive Tracker](https://www.vive.com/us/vive-tracker/)
    - The setup needed to get SteamVR and the HTC Vive products to work is expained [here](https://www.youtube.com/watch?v=QHei7r6sMao). This is needed for the these products to be recognized in Unity after they have been paired.
### Running the code
- Go through the HTC Vive setup
- Open SteamVR and make sure both the Headset, Vive Tracker, and base stations are being tracked. The status screen should show this:
<p align="center">
  <img  src="https://raw.githubusercontent.com/bnduwi/ENGR490-Capstone-Project/project-clean-up/Software%20Team/Images/SteamStatusTracker_final.jpg?token=AHVOJ3L2EMRWDF7AHCGQPQ26LFXOS" alt="SteamVR Status Window">
</p>

- Make sure the glove is connected (USB) to the computer Unity is running on using.
- Clone the repository and open the project in Unity 
> Note! The version specified is needed, otherwise opening the project in a different one will cause issues.
- Run the Unity project to begin using the simulation. 
