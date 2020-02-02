using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;

public class FingerMotionUpdater : MonoBehaviour
{
    // Create connection to the serial port
    static string portName = "COM11";
    static int baudRate = 9600;
    SerialPort serial = new SerialPort(portName, baudRate);

    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        // Prepare serial port for reading
        if (!serial.IsOpen)
        {
            serial.Open();
            //serial.ReadTimeout = 10;
        }

        // Read the data from serial and convert to appropriate data type
        string lineRead = serial.ReadLine();

        // Process for each finger
        Debug.Log("DATA READ [" + lineRead + "]");
        
        string[] sensors = lineRead.Split(';');
        float angle = 0;
        string knuckleId = "";
        string knuckleName = "";
        

        foreach (string item in sensors)
        {
            string[] sensor = item.Split(':');
            knuckleId = sensor[0];
            angle = float.Parse(sensor[1]);

            /*                  NOTES
             *          ---------------------
             * - a1 and a2 moves the index finger knuckles
             * - b1 and b2 moves the middle finger knuckles
             * - c1 and c2 moves the ring finger knuckles
             * - d1 and d2 moves the pinky finger knuckles
             */


            if (knuckleId == "a1")
            {
                knuckleName = "Knuckle1a";
                KnuckleRotatorXAxis(knuckleName, angle);
            }            
            else if (knuckleId == "b1")
            {
                knuckleName = "Knuckle2a";
                KnuckleRotatorXAxis(knuckleName, angle);
            }
            else if (knuckleId == "c1")
            {
                knuckleName = "Knuckle3a";
                KnuckleRotatorXAxis(knuckleName, angle);
            }
            else if (knuckleId == "d1")
            {
                knuckleName = "Knuckle4a";
                KnuckleRotatorXAxis(knuckleName, angle);
            }
            else if (knuckleId == "a2")
            {
                knuckleName = "Knuckle1b";
                KnuckleRotatorXAxis(knuckleName, angle);
            }
            else if (knuckleId == "b2")
            {
                knuckleName = "Knuckle2b";
                KnuckleRotatorXAxis(knuckleName, angle);
            }
            else if (knuckleId == "c2")
            {
                knuckleName = "Knuckle3b";
                KnuckleRotatorXAxis(knuckleName, angle);
            }
            else if (knuckleId == "d2")
            {
                knuckleName = "Knuckle4b";
                KnuckleRotatorXAxis(knuckleName, angle);
            }

        }

        void KnuckleRotatorXAxis(string knuckName, float rotationAngle)
        {
            GameObject hand = GameObject.FindGameObjectWithTag(knuckleName);
            hand.transform.rotation = Quaternion.Euler(rotationAngle,0,0);
        }

        void KnuckleRotatorZAxis(string knuckName, float rotationAngle)
        {
            GameObject hand = GameObject.FindGameObjectWithTag(knuckleName);
            hand.transform.rotation = Quaternion.Euler(0,0,rotationAngle);
        }

        void KnuckleRotatorYAxis(string knuckName, float rotationAngle)
        {
            GameObject hand = GameObject.FindGameObjectWithTag(knuckleName);
            hand.transform.rotation = Quaternion.Euler(0,rotationAngle,0);
        }

    }
}
