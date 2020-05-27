using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DS_Note_Script : MonoBehaviour
{
    public AudioSource DS_Note;

    private void OnMouseDown()
    {
        DS_Note.Play();
    }

    private void OnCollisionEnter(Collision collision)
    {
        DS_Note.Play();
    }
}
