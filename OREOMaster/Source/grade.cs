using UnityEngine;
using UnityEngine.UI;

public class grade : MonoBehaviour
{

    float floatSpeed = 600f;
    float fadeDuration = 0.5f;
    //float maxFloatDistance = 50f;


    private RectTransform rectTransform; // Coordinates and size of the UI element
    private Graphic uiGraphic; // Gets and modifies the UI element color (Image, Text, etc.)
    private Color startColor;
    //private float currentFloatDistance = 0f;
    private float fadeTimer = 0f;
    //private bool isFading = false;
    private Vector2 startAnchoredPosition; // Stores the initial position of the UI element


    void Start()
    {
        rectTransform = GetComponent<RectTransform>();
        uiGraphic = GetComponent<Graphic>();
        startAnchoredPosition = rectTransform.anchoredPosition;
        // Stores the initial color of the UI element
        startColor = uiGraphic.color;
    }

    void Update()
    {
        // Phase 1: float upward
        //if (currentFloatDistance < maxFloatDistance)
        //{
        //    float moveAmount = floatSpeed * Time.deltaTime;
        //    // Move the UI element using anchoredPosition
        //    rectTransform.anchoredPosition += Vector2.up * moveAmount;
        //    currentFloatDistance += moveAmount;

        //    // Start fading after reaching the maximum float distance
        //    if (currentFloatDistance >= maxFloatDistance && !isFading)
        //    {
        //        isFading = true;
        //        fadeTimer = 0f; // Reset the fade timer
        //    }
        //}
        // Phase 2: gradually fade out
        //if (isFading)
        //{
            float moveAmount = floatSpeed * Time.deltaTime;
            // Move the UI element using anchoredPosition
            rectTransform.anchoredPosition += Vector2.up * moveAmount;
            fadeTimer += Time.deltaTime;
            float alpha = Mathf.Lerp(startColor.a, 0f, fadeTimer / fadeDuration);

            // Update the UI element color
            Color newColor = startColor;
            newColor.a = alpha;
            uiGraphic.color = newColor;

            // Destroy the object when it becomes fully transparent
            if (alpha <= 0.01f) // Use 0.01f to avoid floating-point precision issues
            {
                Destroy(gameObject);
            }
        //}
    }
}
