using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;

public class Rotator : MonoBehaviour
{
    // Update the port according to your setup
    SerialPort serial = new SerialPort("COM3", 9600);
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (!serial.IsOpen)
        {
            serial.Open();
        }

        // This reads the angle from the potentiometer and ratates the object in the y direction
        int rotation = int.Parse(serial.ReadLine());
        transform.localEulerAngles = new Vector3(0, rotation, 0);
    }
}
