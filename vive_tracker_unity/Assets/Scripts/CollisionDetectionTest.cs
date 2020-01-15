using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CollisionDetectionTest : MonoBehaviour
{

    private void OnCollisionEnter(Collision col)
    {
        Debug.Log(gameObject.name + " has collided with " + col.gameObject.name);
        Debug.Log(" \nand contacts: " + col.contacts[0]);
        Debug.Log(" \nand impulse " + col.impulse);
        Debug.Log(" \nand NORMALS " + col.contacts[0].normal);
        Debug.Log(" \nand REL VELOCITY: " + col.relativeVelocity);
        Debug.Log(" \nand ALL CONTACTS: " + col.GetContacts(  col.contacts  )   );
    }




    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
