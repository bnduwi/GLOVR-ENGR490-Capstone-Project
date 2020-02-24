using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PatrolStraightLine : MonoBehaviour
{

    [SerializeField] float patrolSpeed = 1f;
    Vector3 direction = Vector3.right;

    //int maxLimit, lowerLimit;
    //float trajectory;

    Vector3 m_centerPosition;
    float m_degrees;

    [SerializeField]
    float m_speed = 1.0f;

    [SerializeField]
    float m_amplitude = 1.0f;

    [SerializeField]
    float m_period = 1.0f;


    // Start is called before the first frame update
    void Start()
    {
        // Set starting direction
        direction = Vector3.right;


        InvokeRepeating("ReverseDirection", 0, (Random.Range(-2, 2)));

        //maxLimit = (int)transform.position.y + 10; 
        //lowerLimit = (int)transform.position.y;
        //trajectory = 0.05f;

        m_centerPosition = transform.position;

    }

    // Update is called once per frame
    void Update()
    {
        // transform.Translate(direction * patrolSpeed * Time.deltaTime);

        //transform.position = transform.position + new Vector3(5.0f, trajectory, 0);
        //if (transform.position.y >= maxLimit) trajectory = -0.05f;
        //if (transform.position.y <= lowerLimit) trajectory = 0.05f;

        float deltaTime = Time.deltaTime;

        // Move center along x axis
        //m_centerPosition.x += deltaTime * m_speed;
        transform.Translate(direction * patrolSpeed * Time.deltaTime);

        // Update degrees
        float degreesPerSecond = 360.0f / m_period;
        m_degrees = Mathf.Repeat(m_degrees + (deltaTime * degreesPerSecond), 360.0f);
        float radians = m_degrees * Mathf.Deg2Rad;

        // Offset by sin wave
        Vector3 offset = new Vector3(0.5f, 0f, m_amplitude * Mathf.Sin(radians));
        //transform.position = m_centerPosition + offset;
        transform.Translate((direction + offset) * patrolSpeed * Time.deltaTime);

    }

    void ReverseDirection()
    {
        if (direction == Vector3.right)
        {
            direction = Vector3.left;
            transform.localRotation = Quaternion.Euler(0, -180, 0);
            patrolSpeed = patrolSpeed * -1;
        }
        else
        {
            direction = Vector3.right;
            transform.localRotation = Quaternion.Euler(0, 0, 0);
            patrolSpeed = patrolSpeed * -1;
        }

        //if (direction == Vector3.forward)
        //{
        //    direction = Vector3.back;
        //    transform.localRotation = Quaternion.Euler(0, -180, 0);
        //    patrolSpeed = patrolSpeed * -1;
        //}
        //else
        //{
        //    direction = Vector3.forward;
        //    transform.localRotation = Quaternion.Euler(0, 0, 0);
        //    patrolSpeed = patrolSpeed * -1;
        //}
    }


}





