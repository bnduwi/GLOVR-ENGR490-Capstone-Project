using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class E1_Note_Script : MonoBehaviour
{
    public AudioSource E1_Note;

    private void OnMouseDown()
    {
        E1_Note.Play();
    }

    private void OnCollisionEnter(Collision collision)
    {
        E1_Note.Play();
    }
}
