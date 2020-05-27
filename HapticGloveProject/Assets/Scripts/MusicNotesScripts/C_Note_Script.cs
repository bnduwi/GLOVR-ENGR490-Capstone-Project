using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class C_Note_Script : MonoBehaviour
{
    public AudioSource C_Note;

    private void OnMouseDown()
    {
        {
            print("Key Note Pressed is C");
            C_Note.Play();
        }        
    }

    private void OnCollisionEnter(Collision collision)
    {
        print("COLLISION is C");
        C_Note.Play();
    }
}
