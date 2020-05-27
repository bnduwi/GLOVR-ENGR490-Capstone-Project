using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class F_Note_Script : MonoBehaviour
{
    public AudioSource F_Note;

    private void OnMouseDown()
    {
        F_Note.Play();
    }

    private void OnCollisionEnter(Collision collision)
    {
        F_Note.Play();
    }
}
