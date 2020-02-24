using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ChangeButtonColor : MonoBehaviour
{

    public Color redcolor;
    public Color bluecolor;
    bool buttonOn = false;  // Off = Blue, On = Red

    void Start()
    {
        this.GetComponent<Renderer>().material.SetColor("_Color", bluecolor);
    }

    void Update()
    {
        
    }

    void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.tag.Equals("Hand")) 
        {
            if (buttonOn)
            {
                this.GetComponent<Renderer>().material.SetColor("_Color", bluecolor);
                buttonOn = false;
                //Physics.IgnoreCollision(GameObject.FindWithTag("Hand").GetComponent<Collider>(), GetComponent<Collider>());
                //Invoke("ReEnableCollision", 1);
            }
            else
            {
                this.GetComponent<Renderer>().material.SetColor("_Color", redcolor);
                buttonOn = true;
            }
        }
    }

    void ReEnableCollision()
    {
        Physics.IgnoreCollision(GameObject.FindWithTag("Hand").GetComponent<Collider>(), GetComponent<Collider>(), false);
    }

    //    void OnTriggerEnter(Collider other)
    //{
    //        if (other.gameObject.tag == "Hand")
    //        //if (other.gameObject.CompareTag("Hand"))
    //    {
    //        Debug.Log("It's ALIVE and red");
    //        //transform.GetComponent<Renderer>().material.color = redcolor;
    //        this.GetComponent<Renderer>().material.SetColor("_Color", redcolor);
    //    }

    //    //if (other.gameObject.CompareTag("BluePaddle"))
    //    //{
    //    //    Debug.Log("It's ALIVE and blue");
    //    //    transform.GetComponent<Renderer>().material.color = bluecolor;
    //    //}
    //}
}
