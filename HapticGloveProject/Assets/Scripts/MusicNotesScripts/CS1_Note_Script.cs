using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CS1_Note_Script : MonoBehaviour
{
    public AudioSource CS1_Note;

    private void OnMouseDown()
    {
        CS1_Note.Play();
    }

    private void OnCollisionEnter(Collision collision)
    {
        CS1_Note.Play();
    }
}
