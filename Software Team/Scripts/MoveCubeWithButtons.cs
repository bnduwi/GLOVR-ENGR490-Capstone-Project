using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;


public class MoveCube : MonoBehaviour
{
    // Update the port according to your setup
    SerialPort sp = new SerialPort("COM3", 9600);
    // Start is called before the first frame update
    void Start()
    {
        sp.Open();
        sp.ReadTimeout = 1;
    }

    // Update is called once per frame
    void Update()
    {
        if (sp.IsOpen)
        {
            /* When the left button is pressed on the arduino it sends the value 1
             * When the right button is pressed it sends the value
             * This then determines the direction the cube should move
             */

            try
            {
                if(sp.ReadByte() == 1)
                {
                    transform.Translate(Vector3.left * Time.deltaTime * 5);
                }
                else if(sp.ReadByte() == 2)
                {
                    transform.Translate(Vector3.right * Time.deltaTime * 5);
                }
            }
            catch(System.Exception)
            {

            }
        }
    }
}
