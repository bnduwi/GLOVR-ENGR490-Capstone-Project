using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class C1_Note_Script : MonoBehaviour
{
    public AudioSource C1_Note;

    private void OnMouseDown()
    {
        C1_Note.Play();
    }

    private void OnCollisionEnter(Collision collision)
    {
        C1_Note.Play();
    }
}
