using UnityEngine;

public class enemy_cookie : MonoBehaviour
{

    private Vector3 startPosition; // Stores the initial world position of the GameObject
    float floatSpeed = 2f;    // Floating speed, adjustable in the Inspector
    float floatAmplitude = 0.1f; // Floating amplitude, adjustable in the Inspector
                                 // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {

        startPosition = transform.position;
    }
    // Update is called once per frame
    void Update()
    {
        float newY = startPosition.y + Mathf.Sin(Time.time * floatSpeed) * floatAmplitude;

        // Update the world position of the GameObject
        // Keep the X and Z axes unchanged
        transform.position = new Vector3(startPosition.x, newY, startPosition.z);
    }
}
