using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GS_Note_Script : MonoBehaviour
{
    public AudioSource GS_Note;

    private void OnMouseDown()
    {
        GS_Note.Play();
    }

    private void OnCollisionEnter(Collision collision)
    {
        GS_Note.Play();
    }
}
