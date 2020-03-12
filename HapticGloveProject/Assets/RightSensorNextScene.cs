using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RightSensorNextScene : MonoBehaviour
{
    private void OnCollisionEnter(Collision collision)
    {
        Debug.Log("THE NEXT SCENE NEEDS TO BE LOADED");
    }
}
