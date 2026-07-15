using UnityEngine;

public class oreo_attack : MonoBehaviour
{
    //[Header("Movement Settings")]
    float superSpeed = 40f; // Very high movement speed
    Vector2 moveDirection = new Vector2(1, 0.65f).normalized; // Upper-right direction

    float rotationSpeed = 480f; // Rotation speed (degrees per second)

    [Header("Condition Settings (Example Only)")]
    [SerializeField] private bool conditionMet = false; // Switch for whether the condition has been met

    void Update() // Update every frame
    {
        if (conditionMet)
        {
            // Directly change the object position
            // Multiply by Time.deltaTime to keep movement independent of frame rate.
            transform.position += (Vector3)moveDirection * superSpeed * Time.deltaTime;
            transform.Rotate(Vector3.forward, rotationSpeed * Time.deltaTime, Space.Self);


        }
    }

    /// <summary>
    /// Called externally to enable very high speed movement.
    /// </summary>
    public void AchieveCondition()
    {
        if (!conditionMet)
        {
        //Debug.Log("Condition met. Start very high speed movement.");
            conditionMet = true;
            Destroy(gameObject, 1.0f);
            ShrinkGradually();
        }
    }

   

        // --- Test: trigger with keys during play mode ---
    void Start()
    {
            // Debug.Log("Press Space to start very high speed movement, and Esc to stop.");
    }

    public void ShrinkGradually()
    {
            StartCoroutine(ShrinkOverTime(1.0f, 0.3f)); // Shrink to 0.1 scale over 1 second
    }

    private System.Collections.IEnumerator ShrinkOverTime(float duration, float finalScale)
    {
        Vector3 initialScale = transform.localScale;
        Vector3 targetScaleVector = new Vector3(finalScale, finalScale, finalScale);
        float timer = 0f;

        while (timer < duration)
        {
            // Use Mathf.Lerp or Vector3.Lerp for a smooth transition
            transform.localScale = Vector3.Lerp(initialScale, targetScaleVector, timer / duration);
            timer += Time.deltaTime;
            yield return null; // Wait for the next frame
        }
        transform.localScale = targetScaleVector; // Ensure the final scale is exact
        //Debug.Log($"Object {gameObject.name} has shrunk gradually.", this);
    }


}
