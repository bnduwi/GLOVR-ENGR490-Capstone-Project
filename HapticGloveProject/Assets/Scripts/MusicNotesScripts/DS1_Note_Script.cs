using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DS1_Note_Script : MonoBehaviour
{
    public AudioSource DS1_Note;

    private void OnMouseDown()
    {
        DS1_Note.Play();
    }

    private void OnCollisionEnter(Collision collision)
    {
        DS1_Note.Play();
    }
}
