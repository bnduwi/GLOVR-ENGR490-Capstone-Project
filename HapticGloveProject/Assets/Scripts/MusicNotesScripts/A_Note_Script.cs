using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class A_Note_Script : MonoBehaviour
{
    public AudioSource A_Note;

    private void OnMouseDown()
    {
        A_Note.Play();
    }

    private void OnCollisionEnter(Collision collision)
    {
        A_Note.Play();
    }
}
