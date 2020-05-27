using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LeftSensorPrevScene : MonoBehaviour
{
    private void OnCollisionEnter(Collision collision)
    {
        Debug.Log("THE PREVIOUS SCENE NEEDS TO BE LOADED");
    }
}
