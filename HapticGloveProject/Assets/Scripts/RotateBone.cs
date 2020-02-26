using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/* 
    To select bone:
    Palm = Hold down SPACE
    Proximal bones = Hold down 1-5
    Middle bones = Hold down 6-0
    Tips = Hold down Q,W,E,R,T

    To rotate:
    X axis = Up/Down Arrows
    Y axis = Left/Right Arrows  (Only works on Palm)
    Z axis = +/-                     (Only works on Palm)
*/

public class RotateBone : MonoBehaviour
{
    float jointAngle = 0;
    
    //// Start is called before the first frame update
    //void Start()
    //{
    //}
    
    void Update()
    {
        if ((this.gameObject.tag == "Palm" ) & (Input.GetKey(KeyCode.Space)))
        {
            RotateOnAxis("Palm");
        }
        if ((this.gameObject.tag == "Proximal1") & (Input.GetKey(KeyCode.Alpha1) | Input.GetKey(KeyCode.Keypad1)))
        {
            RotateOnAxis("Knuckle1a");
        }
        if ((this.gameObject.tag == "Proximal2") & (Input.GetKey(KeyCode.Alpha2) | Input.GetKey(KeyCode.Keypad2)))
        {
            RotateOnAxis("Knuckle2a");
        }
        if ((this.gameObject.tag == "Proximal3") & (Input.GetKey(KeyCode.Alpha3) | Input.GetKey(KeyCode.Keypad3)))
        {
            RotateOnAxis("Knuckle3a");
        }
        if ((this.gameObject.tag == "Proximal4") & (Input.GetKey(KeyCode.Alpha4) | Input.GetKey(KeyCode.Keypad4)))
        {
            RotateOnAxis("Knuckle4a");
        }
        if ((this.gameObject.tag == "Proximal5") & (Input.GetKey(KeyCode.Alpha5) | Input.GetKey(KeyCode.Keypad5)))
        {
            RotateOnAxis("Knuckle5a");
        }
        if ((this.gameObject.tag == "Middle1") & (Input.GetKey(KeyCode.Alpha6) | Input.GetKey(KeyCode.Keypad6)))
        {
            RotateOnAxis("Knuckle1b");
        }
        if ((this.gameObject.tag == "Middle2") & (Input.GetKey(KeyCode.Alpha7) | Input.GetKey(KeyCode.Keypad7)))
        {
            RotateOnAxis("Knuckle2b");
        }
        if ((this.gameObject.tag == "Middle3") & (Input.GetKey(KeyCode.Alpha8) | Input.GetKey(KeyCode.Keypad8)))
        {
            RotateOnAxis("Knuckle3b");
        }
        if ((this.gameObject.tag == "Middle4") & (Input.GetKey(KeyCode.Alpha9) | Input.GetKey(KeyCode.Keypad9)))
        {
            RotateOnAxis("Knuckle4b");
        }
        if ((this.gameObject.tag == "Middle5") & (Input.GetKey(KeyCode.Alpha0) | Input.GetKey(KeyCode.Keypad0)))
        {
            RotateOnAxis("Knuckle5b");
        }
        if ((this.gameObject.tag == "Tip1") & (Input.GetKey(KeyCode.Q)))
        {
            RotateOnAxis("Knuckle1c");
        }
        if ((this.gameObject.tag == "Tip2") & (Input.GetKey(KeyCode.W)))
        {
            RotateOnAxis("Knuckle2c");
        }
        if ((this.gameObject.tag == "Tip3") & (Input.GetKey(KeyCode.E)))
        {
            RotateOnAxis("Knuckle3c");
        }
        if ((this.gameObject.tag == "Tip4") & (Input.GetKey(KeyCode.R)))
        {
            RotateOnAxis("Knuckle4c");
        }
        if ((this.gameObject.tag == "Tip5") & (Input.GetKey(KeyCode.T)))
        {
            RotateOnAxis("Knuckle5c");
        }
    }

    void Bend(string bone, Vector3 rotationAxis, float angleDelta)
    {
        transform.RotateAround(GameObject.Find(bone).transform.position, rotationAxis, jointAngle + angleDelta);
    }

    void RotateOnAxis(string bone)
    {
        // Rotate around X-axis
        if (Input.GetKey(KeyCode.UpArrow))
        {
            Bend(bone, GameObject.Find(bone).transform.right, 1f);
        }
        if (Input.GetKey(KeyCode.DownArrow))
        {
            Bend(bone, GameObject.Find(bone).transform.right, -1f);
        }

        // ONLY PALM CAN ROTATE AROUND Y AND Z AXIS
        if (this.gameObject.tag == "Palm")
        {
            // Rotate around Y-axis
            if (Input.GetKey(KeyCode.RightArrow))
            {
                Bend(bone, Vector3.up, 1f);
            }
            if (Input.GetKey(KeyCode.LeftArrow))
            {
                Bend(bone, Vector3.up, -1f);
            }
            // Rotate around Z-axis
            if (Input.GetKey(KeyCode.KeypadPlus) | Input.GetKey(KeyCode.Plus) | Input.GetKey(KeyCode.Equals))
            {
                Bend(bone, Vector3.forward, 1f);
            }
            if (Input.GetKey(KeyCode.KeypadMinus) | Input.GetKey(KeyCode.Minus))
            {
                Bend(bone, Vector3.forward, -1f);
            }
        }
    }
}
