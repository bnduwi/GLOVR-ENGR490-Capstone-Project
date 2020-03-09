using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CS_Note_Script : MonoBehaviour
{
    public AudioSource CS_Note;

    private void OnMouseDown()
    {
        CS_Note.Play();
    }

    private void OnCollisionEnter(Collision collision)
    {
        CS_Note.Play();
    }
}
