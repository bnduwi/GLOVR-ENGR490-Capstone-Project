using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class F1_Note_Script : MonoBehaviour
{
    public AudioSource F1_Note;

    private void OnMouseDown()
    {
        F1_Note.Play();
    }

    private void OnCollisionEnter(Collision collision)
    {
        F1_Note.Play();
    }
}
