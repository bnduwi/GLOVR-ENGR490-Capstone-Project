using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class B_Note_Script : MonoBehaviour
{
    public AudioSource B_Note;

    private void OnMouseDown()
    {
        B_Note.Play();
    }

    private void OnCollisionEnter(Collision collision)
    {
        B_Note.Play();
    }
}
