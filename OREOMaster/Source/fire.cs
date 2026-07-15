using UnityEngine;

public class fire : MonoBehaviour
{


    public float floatAmplitude = 20f; // Floating amplitude
    float floatSpeed = 3f;      // Floating speed

    private RectTransform rectTransform; // RectTransform component
    private float startY;                // Initial Y position
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        rectTransform = GetComponent<RectTransform>();
        startY = rectTransform.anchoredPosition.y;
    }

    // Update is called once per frame
    void Update()
    {
        float newY = startY + Mathf.Sin(Time.time * floatSpeed) * floatAmplitude;

        // Update the Y position of the RectTransform
        // Keep the X and Z axes unchanged
        rectTransform.anchoredPosition = new Vector2(rectTransform.anchoredPosition.x, newY);
    }
}
