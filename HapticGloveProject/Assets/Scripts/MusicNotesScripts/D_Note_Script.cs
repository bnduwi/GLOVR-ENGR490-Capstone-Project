using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class D_Note_Script : MonoBehaviour
{
    public AudioSource D_Note;

    private void OnMouseDown()
    {
        D_Note.Play();
    }

    private void OnCollisionEnter(Collision collision)
    {
        D_Note.Play();
    }
}
