using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using UnityEngine;

public class PostionTracking : MonoBehaviour
{
    // Start is called before the first frame update
    string strTime;

    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        Vector3 test = this.transform.position;
        strTime = DateTime.Now.ToString("hh.mm.ss.ffffff");

        String line = strTime + "," + test.x + "," + test.y + "," + test.z;
        Debug.Log(line);
        
        using (StreamWriter w = File.AppendText("Assets/PositionData/position_data.csv"))
        {
            w.WriteLine(line);
        }
    }
}
