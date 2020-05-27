using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bb_Note_Script : MonoBehaviour
{
    public AudioSource Bb_Note;

    private void OnMouseDown()
    {
        Bb_Note.Play();
    }

    private void OnCollisionEnter(Collision collision)
    {
        Bb_Note.Play();
    }
}
