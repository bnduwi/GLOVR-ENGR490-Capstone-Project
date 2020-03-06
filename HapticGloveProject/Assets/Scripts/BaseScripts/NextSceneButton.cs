using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class NextSceneButton : MonoBehaviour
{
    void Start()
    {

    }
    void Update()
    {

    }
    void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.tag.Equals("Hand"))
        {
            Debug.Log("TOTAL: " + SceneManager.sceneCountInBuildSettings + " CURRENT: " + SceneManager.GetActiveScene().buildIndex);

            if (SceneManager.sceneCountInBuildSettings == (SceneManager.GetActiveScene().buildIndex + 1))
            {
                Debug.Log("IN THE IFFFFFFFFFFFFFFFFFFFFFFFFFF");
                SceneManager.LoadScene(0);
            }
            else
            {
                SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex + 1);
            }
        }
    }
}
