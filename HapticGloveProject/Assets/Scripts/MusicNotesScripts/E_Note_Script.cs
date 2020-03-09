using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class E_Note_Script : MonoBehaviour
{
    public AudioSource E_Note;

    private void OnMouseDown()
    {
        E_Note.Play();
    }

    private void OnCollisionEnter(Collision collision)
    {
        E_Note.Play();
    }
}
