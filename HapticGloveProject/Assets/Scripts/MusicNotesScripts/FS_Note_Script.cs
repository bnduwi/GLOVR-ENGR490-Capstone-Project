using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FS_Note_Script : MonoBehaviour
{
    public AudioSource FS_Note;

    private void OnMouseDown()
    {
        FS_Note.Play();
    }

    private void OnCollisionEnter(Collision collision)
    {
        FS_Note.Play();
    }
}
