using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class D1_Note_Script : MonoBehaviour
{
    public AudioSource D1_Note;

    private void OnMouseDown()
    {
        D1_Note.Play();
    }

    private void OnCollisionEnter(Collision collision)
    {
        D1_Note.Play();
    }
}
