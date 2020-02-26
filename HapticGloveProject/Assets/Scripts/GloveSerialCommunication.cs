using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;
using System.Threading;

public class GloveSerialCommunication : MonoBehaviour
{
    /* This class deals with communication to glove for both finger movement 
     * and tactile feedback data.
     * The finger movement reads the potentiometer values from each finger 
     * on the glove.
     * Then tactile data is triggered on collision with objects. When the object
     * collide with the fingers they will send the pattern to play on which finger
     * 
     */

    // Create serial controller object to access to the Object with send/recieve functions
    public SerialController serialController;

    void Start()
    {
        // Get a reference SerialController prefab for the thread management
        // Make sure to update the portNumber as needed for the connection
        serialController = GameObject.Find("SerialController").GetComponent<SerialController>();
    }

    // Update is called once per frame
    void Update()
    {
        //---------------------------------------------------------------------
        // Receive data
        //---------------------------------------------------------------------

        string message = serialController.ReadSerialMessage();

        if (message == null)
            return;

        // Check if the message is plain data or a connect/disconnect event.
        if (ReferenceEquals(message, SerialController.SERIAL_DEVICE_CONNECTED))
            Debug.Log("Connection established");
        else if (ReferenceEquals(message, SerialController.SERIAL_DEVICE_DISCONNECTED))
            Debug.Log("Connection attempt failed or disconnection detected");
        else
        {
            Debug.Log("Message arrived: " + message);
            processFingerMovement(message);
            
        }
    }

    void processFingerMovement(string arduinoMessage)
    {
        string[] sensors = arduinoMessage.Split(';');
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
                knuckleName = "SpinnerB1";
                KnuckleRotatorXAxis(knuckleName, angle);
            }
            else if (knuckleId == "b1")
            {

                knuckleName = "SpinnerB2";
                KnuckleRotatorXAxis(knuckleName, angle);
            }
            else if (knuckleId == "c1")
            {
                knuckleName = "SpinnerB3";
                KnuckleRotatorXAxis(knuckleName, angle);
            }
        }
    }

    void KnuckleRotatorXAxis(string knuckleName, float rotationAngle)
    {
        GameObject hand = GameObject.FindGameObjectWithTag(knuckleName);
        hand.transform.rotation = Quaternion.Euler(rotationAngle, 0, 0);
    }

    void OnCollisionEnter(Collision collision)
    {
        /* LRA and Force
         * - Have an end character
         * - Just in case may need to pad numbers to be 3 characters
         * - f,a,123$l,b,33$
         * 
         * This will need to be done for each finger separately.
         * Logic:
         * ------------------------
         * - finger collides with object
         * - figure out what object it is to decide which pattern to send to the LRA
         * - onCollisionEnter send the data to the MCU to start the pattern playing
         * - onCollisionExit send the data to MCU to stop the pattern playing
         */


        string objectHit = collision.collider.name;

        //---------------------------------------------------------------------
        // Send data for the vibration motor patterns to play
        //---------------------------------------------------------------------

        if (objectHit == "block1")
        {
            Debug.Log("Sending a");
            serialController.SendSerialMessage("a");
        }  

    }
}
