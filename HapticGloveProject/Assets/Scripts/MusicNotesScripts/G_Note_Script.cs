using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class G_Note_Script : MonoBehaviour
{
    public AudioSource G_Note;

    private void OnMouseDown()
    {
        G_Note.Play();
    }

    private void OnCollisionEnter(Collision collision)
    {
        G_Note.Play();
    }
}
