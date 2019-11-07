# HTC Vive Tracker and Unity 3D
## Setup instructions
- Requirments to run the code:  
  - Unity version 2018.4.12f1
  - The setup explained here (https://www.youtube.com/watch?v=QHei7r6sMao). This is needed for the Vive to be recognized in Unity after it has been paired  
  - Vive Tracker

- Clone the repository and open the project in Unity (Note! you need the version specified else when you open the project in a different one, most of the files will get rewritten and settings are lost)
- Run the code in Unity and in the Hierachy select the Cube object (Tracker)
- While the application is running in the inspector under the Steam VR-Tracked Object (Script) select change the device under Index to make sure the one attached to the Vive Tracker is selected. Use the Scene tab to verify this
- To run the application you need the Headset as it will act as the camera that picks up where the object it is and shows it on the screen if it is view field.
